/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafechte <vafechte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 15:23:34 by vafechte          #+#    #+#             */
/*   Updated: 2026/03/11 17:35:27 by vafechte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "get_time.h"
#include <stdio.h>
#include "codexion.h"
#include "check_simulation.h"
#include "utils.h"
#include "unistd.h"

// peut etre deadlock trop de verif
bool	compiling(t_coder *coder)
{
	pthread_mutex_lock(&coder->coder_mutex);
	if (coder->compilation_count >= coder->data->number_of_compiles_required)
	{
		pthread_mutex_unlock(&coder->coder_mutex);
		return (false);
	}
	pthread_mutex_unlock(&coder->coder_mutex);
	pthread_mutex_lock(&coder->coder_mutex);
	coder->last_compile_start = get_time_in_ms();
	pthread_mutex_unlock(&coder->coder_mutex);
	if (is_simulation_finished(coder->data))
		return (false);
	log_status(coder, "is compiling");
	if (is_simulation_finished(coder->data))
		return (false);
	usleep(coder->data->time_to_compile * 1000);
	pthread_mutex_lock(&coder->coder_mutex);
	coder->compilation_count++;
	pthread_mutex_unlock(&coder->coder_mutex);
	if (is_simulation_finished(coder->data))
		return (false);
	return (true);
}

// peut etre deadlock trop de verif
bool	debugging(t_coder *coder)
{
	if (is_simulation_finished(coder->data))
		return (false);
	log_status(coder, "is debugging");
	if (is_simulation_finished(coder->data))
		return (false);
	usleep(coder->data->time_to_debug * 1000);
	if (is_simulation_finished(coder->data))
		return (false);
	return (true);
}

// peut etre deadlock trop de verif
bool	refactoring(t_coder *coder)
{
	if (is_simulation_finished(coder->data))
		return (false);
	log_status(coder, "is refactoring");
	if (is_simulation_finished(coder->data))
		return (false);
	usleep(coder->data->time_to_refactor * 1000);
	pthread_mutex_lock(&coder->coder_mutex);
	coder->compilation_count++;
	pthread_mutex_unlock(&coder->coder_mutex);
	return (true);
}
