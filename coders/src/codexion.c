/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafechte <vafechte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 11:11:28 by vafechte          #+#    #+#             */
/*   Updated: 2026/03/12 14:45:53 by vafechte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "init.h"
#include "coder.h"
#include "free_data.h"
#include "get_time.h"
#include "monitor.h"

static bool	start_simulation(t_data *data)
{
	int		i;
	t_coder	*coder;

	data->start_time = get_time_in_ms();
	if (pthread_create(&data->monitor.monitor_id, NULL, monitor, data))
	{
		fprintf(stderr, "Failed to create monitor thread.\n");
		return (false);
	}
	i = 0;
	while (i < data->number_of_coders)
	{
		coder = &data->coders[i];
		if (pthread_create(&coder->coder_id, NULL, coder_simulation, coder))
		{
			fprintf(stderr, "Failed to create coder %d thread.\n", i);
			return (false);
		}
		i++;
	}
	i = 0;
	while (i < data->number_of_coders)
		pthread_join(data->coders[i++].coder_id, NULL);
	pthread_join(data->monitor.monitor_id, NULL);
	return (true);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 9)
		return (-1);
	if (!parsing_input(&data, av))
	{
		fprintf(stderr, "Parsing input failed.\n");
		return (-1);
	}
	if (!init(&data))
	{
		fprintf(stderr, "Init data failed.\n");
		return (-1);
	}
	printf("nb coder: %d\n", data.number_of_coders);
	if (data.number_of_coders == 1)
		one_coder(&data);
	else
		start_simulation(&data);
	cleanup_data(&data);
	return (0);
}
