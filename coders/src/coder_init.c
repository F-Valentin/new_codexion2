/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafechte <vafechte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 10:28:39 by vafechte          #+#    #+#             */
/*   Updated: 2026/03/10 16:12:40 by vafechte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include "coder_init.h"
#include "free_data.h"
#include "time.h"

static void	assign_dongles(t_coder *coder, t_dongle *dongles)
{
	int	number_of_coders;
	int	coder_pos;

	number_of_coders = coder->data->number_of_coders;
	coder_pos = coder->id - 1;
	if (coder->id % 2 == 0)
	{
		coder->first_dongle = &dongles[coder_pos];
		coder->second_dongle = &dongles[(coder_pos + 1) % number_of_coders];
	}
	else
	{
		coder->first_dongle = &dongles[(coder_pos + 1) % number_of_coders];
		coder->second_dongle = &dongles[coder_pos];
	}
}

static void	sync_last_compile_start(t_data *data)
{
	int		i;
	long	time;
	t_coder	*coder;

	i = 0;
	time = get_time_in_ms();
	while (i < data->number_of_coders)
	{
		coder = &data->coders[i];
		coder->last_compile_start = time;
		i++;
	}
}

static bool	coder_mutex_and_cond_init(t_coder *coder)
{
	if (pthread_mutex_init(&coder->coder_mutex, NULL) != 0)
		return (false);
	if (pthread_mutex_init(&coder->coder_waiting, NULL) != 0)
	{
		pthread_mutex_destroy(&coder->coder_waiting);
		return (false);
	}
	if (pthread_cond_init(&coder->coder_cond, NULL) != 0)
	{
		pthread_mutex_destroy(&coder->coder_waiting);
		pthread_mutex_destroy(&coder->coder_mutex);
		return (false);
	}
	return (true);
}

bool	coder_init(t_data *data)
{
	int		i;
	t_coder	*coder;

	data->coders = malloc(sizeof(t_coder) * data->number_of_coders);
	if (!data->coders)
		return (false);
	i = 0;
	while (i < data->number_of_coders)
	{
		coder = &data->coders[i];
		coder->id = i + 1;
		coder->data = data;
		coder->compilation_count = 0;
		if (!coder_mutex_and_cond_init(coder))
			return (free_coder(data->coders, i), false);
		assign_dongles(coder, data->dongles);
		i++;
	}
	sync_last_compile_start(data);
	return (true);
}
