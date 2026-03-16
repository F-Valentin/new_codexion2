/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dongle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafechte <vafechte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 14:07:29 by vafechte          #+#    #+#             */
/*   Updated: 2026/03/16 12:44:27 by vafechte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "dongle.h"
#include "utils.h"
#include "check_simulation.h"
#include "get_time.h"
#include "heap.h"

static long	get_priority(t_coder *coder)
{
	long	edf;

	if (coder->data->scheduler == FIFO)
		return (get_time_in_ms());
	pthread_mutex_lock(&coder->coder_mutex);
	edf = coder->last_compile_start + coder->data->time_to_burnout;
	pthread_mutex_unlock(&coder->coder_mutex);
	return (edf);
}

static bool	wait_dongle(t_coder *coder, t_dongle *dongle)
{
	if (is_simulation_finished(coder->data))
		return (false);
	while (get_time_in_ms() < dongle->available_at)
	{
		if (is_simulation_finished(coder->data))
			return (false);
		usleep(100);
	}
	dongle->available_at = 0;
	return (true);
}

static bool	coder_waiting(t_coder *coder, t_dongle *dongle)
{
	int	coder_id;

	while (true)
	{
		if (is_simulation_finished(coder->data))
		{
			pthread_mutex_unlock(&dongle->dongle_mutex);
			return (false);
		}
		coder_id = heap_peek_min(&dongle->waiting_queue);
		if (coder_id == coder->id)
			break ;
		pthread_cond_wait(&dongle->dongle_cond, &dongle->dongle_mutex);
	}
	heap_extract_min(&dongle->waiting_queue);
	return (true);
}

bool	take_dongle(t_coder *coder, t_dongle *dongle)
{
	if (is_simulation_finished(coder->data))
		return (false);
	pthread_mutex_lock(&dongle->dongle_mutex);
	heap_insert(&dongle->waiting_queue, coder->id, get_priority(coder));
	if (!coder_waiting(coder, dongle))
		return (false);
	if (!wait_dongle(coder, dongle))
		return ((void)pthread_mutex_unlock(&dongle->dongle_mutex), false);
	if (is_simulation_finished(coder->data))
		return ((void)pthread_mutex_unlock(&dongle->dongle_mutex), false);
	log_status(coder, "has taken a dongle");
	return (true);
}

void	release_dongle(t_coder *coder, t_dongle *dongle)
{
	t_data	*data;

	data = coder->data;
	dongle->available_at = get_time_in_ms() + data->dongle_cooldown;
	pthread_cond_broadcast(&dongle->dongle_cond);
	pthread_mutex_unlock(&dongle->dongle_mutex);
}
