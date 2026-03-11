/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafechte <vafechte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 16:26:48 by vafechte          #+#    #+#             */
/*   Updated: 2026/03/11 18:18:23 by vafechte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_time.h"
#include "check_simulation.h"
#include "dongle.h"
#include "coder.h"

static bool	is_coder_finished(t_coder *coder)
{
	pthread_mutex_lock(&coder->coder_mutex);
	if (coder->compilation_count >= coder->data->number_of_compiles_required)
	{
		pthread_mutex_unlock(&coder->coder_mutex);
		return (true);
	}
	pthread_mutex_unlock(&coder->coder_mutex);
	return (false);
}

void	*coder_simulation(void *arg)
{
	t_coder	*coder;

	coder = (t_coder *)arg;
	while (!is_coder_finished(coder))
	{
		if (is_simulation_finished(coder->data))
			break ;
		if (!take_dongle(coder, coder->first_dongle))
			break ;
		if (!take_dongle(coder, coder->second_dongle))
		{
			release_dongle(coder->data, coder->first_dongle);
			break ;
		}
		if (!compiling(coder))
		{
			release_dongle(coder->data, coder->first_dongle);
			release_dongle(coder->data, coder->second_dongle);
			break ;
		}
		release_dongle(coder->data, coder->first_dongle);
		release_dongle(coder->data, coder->second_dongle);
	}
	return (NULL);
}
