/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dongle_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafechte <vafechte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 10:30:04 by vafechte          #+#    #+#             */
/*   Updated: 2026/03/10 16:56:01 by vafechte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "dongle_init.h"
#include "free_data.h"

static bool	dongle_mutex_and_cond_init(t_dongle *dongle)
{
	if (pthread_mutex_init(&dongle->dongle_mutex, NULL) != 0)
		return (false);
	if (pthread_cond_init(&dongle->dongle_cond, NULL) != 0)
	{
		pthread_mutex_destroy(&dongle->dongle_mutex);
		return (false);
	}
	return (true);
}

bool	dongle_init(t_data *data)
{
	int			i;
	t_dongle	*dongle;

	data->dongles = malloc(sizeof(t_dongle) * data->number_of_coders);
	if (!data->dongles)
		return (false);
	i = 0;
	while (i < data->number_of_coders)
	{
		dongle = &data->dongles[i];
		dongle->dongle_id = i;
		dongle->available_at = 0;
		if (!dongle_mutex_and_cond_init(dongle))
			return (free_dongle(data->dongles, i), false);
		dongle->waiting_queue.nodes = malloc(
				sizeof(t_heap_node) * 2);
		if (!dongle->waiting_queue.nodes)
			return (free_dongle(data->dongles, i), false);
		dongle->waiting_queue.size = 0;
		dongle->waiting_queue.capacity = 2;
		i++;
	}
	return (true);
}
