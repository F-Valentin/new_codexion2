/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafechte <vafechte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 14:38:57 by vafechte          #+#    #+#             */
/*   Updated: 2026/03/11 14:40:51 by vafechte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"
#include "check_simulation.h"
#include "get_time.h"

void	log_status(t_coder *coder, const char *status)
{
	long	timestamp;

	// peut etre race condition
	timestamp = get_time_in_ms() - coder->data->start_time;
	if (!is_simulation_finished(coder->data))
	{
		pthread_mutex_lock(&coder->data->log_mutex);
		printf("%ld %d %s", timestamp, coder->id, status);
		pthread_mutex_unlock(&coder->data->log_mutex);
	}
}
