/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafechte <vafechte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 14:38:57 by vafechte          #+#    #+#             */
/*   Updated: 2026/03/12 14:52:24 by vafechte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "check_simulation.h"
#include "get_time.h"

void	log_status(t_coder *coder, const char *status)
{
	long	timestamp;

	if (!is_simulation_finished(coder->data))
	{
		pthread_mutex_lock(&coder->data->log_mutex);
		pthread_mutex_lock(&coder->data->data_mutex);
		timestamp = get_time_in_ms() - coder->data->start_time;
		pthread_mutex_unlock(&coder->data->data_mutex);
		if (!is_simulation_finished(coder->data))
			printf("%ld %d %s\n", timestamp, coder->id, status);
		pthread_mutex_unlock(&coder->data->log_mutex);
	}
}

void	wake_up_all_coders(t_coder *coders, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		pthread_mutex_lock(&coders[i].coder_waiting);
		pthread_cond_broadcast(&coders[i].coder_cond);
		pthread_mutex_unlock(&coders[i].coder_waiting);
		i++;
	}
}
