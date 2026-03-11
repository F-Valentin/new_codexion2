/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafechte <vafechte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 10:59:28 by vafechte          #+#    #+#             */
/*   Updated: 2026/03/11 12:23:56 by vafechte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "codexion.h"
#include "getters.h"
#include "time.h"

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
			return (true);
		i++;
	}
	return (false);
}
