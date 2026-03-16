/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafechte <vafechte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 10:59:39 by vafechte          #+#    #+#             */
/*   Updated: 2026/03/16 12:29:48 by vafechte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "check_simulation.h"
#include "utils.h"

void	*monitor(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	while (true)
	{
		if (is_simulation_finished(data))
		{
			wake_up_all_coders(data->dongles, data->number_of_coders);
			break ;
		}
		if (check_all_coders_finished(data))
			break ;
		if (check_coders_burnout(data))
		{
			pthread_mutex_lock(&data->end_mutex);
			data->end_simulation = true;
			pthread_mutex_unlock(&data->end_mutex);
		}
		usleep(500);
	}
	return (NULL);
}
