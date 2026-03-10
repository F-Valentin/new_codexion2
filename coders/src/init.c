/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafechte <vafechte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 16:49:46 by vafechte          #+#    #+#             */
/*   Updated: 2026/03/10 15:27:21 by vafechte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include "init.h"
#include "coder_init.h"
#include "dongle_init.h"
#include "free_data.h"

static bool	monitor_init(t_monitor *monitor)
{
	if (pthread_mutex_init(&monitor->monitor_mutex, NULL) != 0)
		return (false);
	if (pthread_cond_init(&monitor->monitor_cond, NULL) != 0)
	{
		pthread_mutex_destroy(&monitor->monitor_mutex);
		return (false);
	}
	return (true);
}

static bool	data_init(t_data *data)
{
	data->coders = NULL;
	data->dongles = NULL;
	if (pthread_mutex_init(&data->log_mutex, NULL) != 0)
		return (false);
	if (pthread_mutex_init(&data->end_mutex, NULL) != 0)
	{
		pthread_mutex_destroy(&data->log_mutex);
		return (false);
	}
	if (pthread_mutex_init(&data->data_mutex, NULL) != 0)
	{
		pthread_mutex_destroy(&data->log_mutex);
		pthread_mutex_destroy(&data->end_mutex);
		return (false);
	}
	data->start_simulation = false;
	data->end_simulation = false;
	data->start_time = get_time_in_ms();
	return (true);
}

bool	init(t_data *data)
{
	if (!data)
		return (false);
	if (!data_init(data))
		return (false);
	if (!monitor_init(&data->monitor))
		return (false);
	if (!dongle_init(data))
	{
		free_monitor(&data->monitor);
		fprintf(stderr, "Failed to initialize Dongles\n");
		return (false);
	}
	if (!coder_init(data))
	{
		free_monitor(&data->monitor);
		free_dongle(data->dongles, data->number_of_coders);
		fprintf(stderr, "Failed to initialize Coders\n");
		return (false);
	}
	return (true);
}
