/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafechte <vafechte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 11:11:28 by vafechte          #+#    #+#             */
/*   Updated: 2026/03/10 14:39:13 by vafechte         ###   ########.fr       */
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
	if (!init(&data))
	{
		fprintf(stderr, "Init data failed.\n");
		return (-1);
	}
	cleanup_data(&data);
	return (0);
}
