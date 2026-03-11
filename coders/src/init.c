/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafechte <vafechte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 16:49:46 by vafechte          #+#    #+#             */
/*   Updated: 2026/03/11 10:42:28 by vafechte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include "init.h"
#include "coder_init.h"
#include "dongle_init.h"
#include "free_data.h"
#include "time.h"

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
	data->start_time = 0;
	return (true);
}

bool	init(t_data *data)
{
	if (!data)
		return (false);
	if (!data_init(data))
		return (false);
	if (!monitor_init(&data->monitor))
		return (free_data_mutex_and_cond(data), false);
	if (!dongle_init(data))
	{
		free_data_mutex_and_cond(data);
		fprintf(stderr, "Failed to initialize Dongles\n");
		return (free_monitor(&data->monitor), false);
	}
	if (!coder_init(data))
	{
		free_data_mutex_and_cond(data);
		free_dongle(data->dongles, data->number_of_coders);
		fprintf(stderr, "Failed to initialize Coders\n");
		return (free_monitor(&data->monitor), false);
	}
	return (true);
}
