/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafechte <vafechte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 16:49:35 by vafechte          #+#    #+#             */
/*   Updated: 2026/03/10 16:23:15 by vafechte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include "free_data.h"

void	free_dongle(t_dongle *dongles, int size)
{
	int			i;
	t_dongle	*dongle;

	i = 0;
	while (i < size)
	{
		dongle = &dongles[i];
		if (pthread_mutex_destroy(&dongle->dongle_mutex) != 0)
			fprintf(stderr, "Failed to destroy the %d dongle's mutex.\n", i);
		if (pthread_cond_destroy(&dongle->dongle_cond) != 0)
			fprintf(stderr, "Failed to destroy the %d dongle's cond.\n", i);
		if (dongle->waiting_queue.nodes)
			free(dongle->waiting_queue.nodes);
		i++;
	}
	free(dongles);
}

void	free_coder(t_coder *coders, int size)
{
	int		i;
	t_coder	*coder;

	i = 0;
	while (i < size)
	{
		coder = &coders[i];
		if (pthread_mutex_destroy(&coder->coder_mutex) != 0)
			fprintf(stderr, "Failed to destroy the %d coder's mutex.\n", i);
		if (pthread_mutex_destroy(&coder->coder_waiting) != 0)
			fprintf(
				stderr, "Failed to destroy the %d coder's waiting mutex.\n", i);
		if (pthread_cond_destroy(&coder->coder_cond) != 0)
			fprintf(stderr, "Failed to destroy the %d coder's cond.\n", i);
		i++;
	}
	free(coders);
}

void	free_data_mutex_and_cond(t_data *data)
{
	if (pthread_mutex_destroy(&data->data_mutex) != 0)
		fprintf(stderr, "Failed to destroy the data_mutex.\n");
	if (pthread_mutex_destroy(&data->end_mutex) != 0)
		fprintf(stderr, "Failed to destroy the end_mutex.\n");
	if (pthread_mutex_destroy(&data->log_mutex) != 0)
		fprintf(stderr, "Failed to destroy the log_mutex.\n");
}

void	free_monitor(t_monitor *monitor)
{
	if (pthread_mutex_destroy(&monitor->monitor_mutex) != 0)
		fprintf(stderr, "Failed to destroy the monitor's mutex.\n");
	if (pthread_cond_destroy(&monitor->monitor_cond) != 0)
		fprintf(stderr, "Failed to destroy the monitor's cond");
}

void	cleanup_data(t_data *data)
{
	if (!data)
		return ;
	if (pthread_mutex_destroy(&data->data_mutex) != 0)
		fprintf(stderr, "Failed to destroy data_mutex.\n");
	if (pthread_mutex_destroy(&data->log_mutex) != 0)
		fprintf(stderr, "Failted to destroy log_mutex.\n");
	if (pthread_mutex_destroy(&data->end_mutex) != 0)
		fprintf(stderr, "Failted to destroy end_mutex.\n");
	free_monitor(&data->monitor);
	if (data->dongles)
		free_dongle(data->dongles, data->number_of_coders);
	if (data->coders)
		free_coder(data->coders, data->number_of_coders);
}
