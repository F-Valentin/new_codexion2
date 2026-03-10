/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafechte <vafechte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 11:11:28 by vafechte          #+#    #+#             */
/*   Updated: 2026/03/10 15:38:10 by vafechte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "init.h"
#include "free_data.h"

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
	printf("nb of coders: %d\n", data.number_of_coders);
	printf("time_to_burnout: %ld\n", data.time_to_burnout);
	printf("time_to_compile: %ld\n", data.time_to_compile);
	printf("time_to_debug: %ld\n", data.time_to_debug);
	printf("time_to_refactor: %ld\n", data.time_to_refactor);
	printf("nb of compile required: %d\n", data.number_of_coders);
	printf("dongle cooldown: %ld\n", data.dongle_cooldown);
	printf("scheduler: %s\n", data.scheduler == 0 ? "fifo" : "edf");
	if (!init(&data))
	{
		fprintf(stderr, "Init data failed.\n");
		return (-1);
	}
	cleanup_data(&data);
	return (0);
}
