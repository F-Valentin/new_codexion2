/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafechte <vafechte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 10:59:28 by vafechte          #+#    #+#             */
/*   Updated: 2026/03/11 10:59:29 by vafechte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "codexion.h"
#include "getters.h"
#include "time.h"

static long	get_elapsed_time(
	long start,
	long *end,
	pthread_mutex_t *mutex
)
{
	return (start - get_long(end, mutex));
}

bool	check_coders_burnout(t_data *data)
{
	int		i;
	long	elapsed;
	long	time;
	t_coder	*coder;

	i = 0;
	while (i < data->number_of_coders)
	{
		coder = &data->coders[i];
		time = get_time_in_ms();
		elapsed = get_elapsed_time(time,
				&coder->last_compile_start, &coder->coder_mutex);
		if (get_int(&coder->compilation_count, &coder->coder_mutex)
			!= data->number_of_compiles_required
			&& elapsed >= data->time_to_burnout)
			return (true);
		i++;
	}
	return (false);
}
