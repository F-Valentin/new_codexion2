/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafechte <vafechte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 16:26:48 by vafechte          #+#    #+#             */
/*   Updated: 2026/03/11 16:50:18 by vafechte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_simulation.h"
#include "dongle.h"
#include "coder.h"

void	*coder_simulation(void *arg)
{
	t_coder	*coder;
	
	coder = (t_coder *)arg;
	while (true)
	{
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
		pthread_mutex_lock(&coder->coder_mutex);
		if (coder->compilation_count >= coder->data->number_of_coders)
		{
			pthread_mutex_unlock(&coder->coder_mutex);
			break ;
		}
		pthread_mutex_unlock(&coder->coder_mutex);
		if (is_simulation_finished(coder->data))
			break ;
	}
	return (NULL);
}
