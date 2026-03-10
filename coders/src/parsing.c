/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafechte <vafechte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 16:49:52 by vafechte          #+#    #+#             */
/*   Updated: 2026/03/10 11:06:53 by vafechte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <string.h>
#include "utils.h"
#include "codexion.h"

static bool	valid_input(char **av, long *arr)
{
	int		i;

	i = 0;
	while (i < 7)
	{
		arr[i] = ft_atol(av[i + 1]);
		if (arr[i] <= -1)
			return (false);
		i++;
	}
	return (true);
}

bool	parsing_input(t_data *data, char **av)
{
	long	arr[7];

	if (!valid_input(av, arr))
		return (false);
	if (!arr[0] || !arr[5])
		return (false);
	data->number_of_coders = arr[0];
	data->time_to_burnout = arr[1];
	data->time_to_compile = arr[2];
	data->time_to_debug = arr[3];
	data->time_to_refactor = arr[4];
	data->number_of_compiles_required = arr[5];
	data->dongle_cooldown = arr[6];
	if (strcmp(av[8], "fifo") == 0)
		data->scheduler = FIFO;
	else if (strcmp(av[8], "edf") == 0)
		data->scheduler = EDF;
	else
		return (false);
	return (true);
}
