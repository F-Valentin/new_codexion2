/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_coder.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafechte <vafechte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 14:06:30 by vafechte          #+#    #+#             */
/*   Updated: 2026/03/11 14:13:33 by vafechte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_time.h"
#include "codexion.h"
#include "monitor.h"

static void	*one_coder_simulation(void *arg)
{
	(void)arg;
	return (NULL);
}

void	*one_coder(t_data *data)
{
	t_coder	*coder;

	coder = &data->coders[0];
	data->start_time = get_time_in_ms();
	if (pthread_create(&data->monitor.monitor_id, NULL, monitor, data) != 0)
	{
		fprintf(stderr, "Failed to create monitor thread.\n");
		return (NULL);
	}
	if (pthread_create(&coder->coder_id, NULL, one_coder_simulation, coder))
	{
		fprintf(stderr, "Failed to create one_coder thread.\n");
		return (NULL);
	}
	
	pthread_join(coder->coder_id, NULL);
	pthread_join(data->monitor.monitor_id, NULL);
	return (NULL);
}
