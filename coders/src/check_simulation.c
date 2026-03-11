/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafechte <vafechte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 10:59:28 by vafechte          #+#    #+#             */
/*   Updated: 2026/03/11 13:33:04 by vafechte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_simulation.h"
#include "getters.h"
#include "get_time.h"

bool	check_coders_burnout(t_data *data)
{
	int		i;
	long	elapsed;
	t_coder	*coder;

	i = 0;
	while (i < data->number_of_coders)
	{
		coder = &data->coders[i];
		pthread_mutex_lock(&coder->coder_mutex);
		elapsed = get_time_in_ms() - coder->last_compile_start;
		pthread_mutex_unlock(&coder->coder_mutex);
		if (get_int(&coder->compilation_count, &coder->coder_mutex)
			!= data->number_of_compiles_required
			&& elapsed >= data->time_to_burnout)
		{
			// print burnout
			return (true);
		}
		i++;
	}
	return (false);
}

bool	is_simulation_finished(t_data *data)
{
	bool	end;

	pthread_mutex_lock(&data->end_mutex);
	end = data->end_simulation;
	pthread_mutex_unlock(&data->end_mutex);
	return (end);
}

bool	check_all_coders_finished(t_data *data)
{
	int		i;
	int		count;
	t_coder	*coder;

	i = 0;
	count = 0;
	while (i < data->number_of_coders)
	{
		coder = &data->coders[i];
		pthread_mutex_lock(&coder->coder_mutex);
		if (coder->compilation_count >= data->number_of_compiles_required)
			count++;
		pthread_mutex_unlock(&coder->coder_mutex);
		i++;
	}
	if (count >= data->number_of_compiles_required)
	{
		pthread_mutex_lock(&data->end_mutex);
		data->end_simulation = true;
		pthread_mutex_unlock(&data->end_mutex);
		return (true);
	}
	return (false);
}
