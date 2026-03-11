/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafechte <vafechte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 16:50:17 by vafechte          #+#    #+#             */
/*   Updated: 2026/03/11 14:13:58 by vafechte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODEXION_H
# define CODEXION_H

# include <pthread.h>
# include <stdbool.h>
# include "heap.h"

typedef struct s_data	t_data;

typedef enum e_scheduler
{
	FIFO,
	EDF,
}	t_scheduler;

typedef struct s_dongle
{
	int				dongle_id;
	long			available_at;
	t_heap			waiting_queue;
	pthread_mutex_t	dongle_mutex;
	pthread_cond_t	dongle_cond;
}	t_dongle;

typedef struct s_coder
{
	int				id;
	int				compilation_count;
	long			last_compile_start;
	pthread_t		coder_id;
	t_dongle		*first_dongle;
	t_dongle		*second_dongle;
	t_data			*data;
	pthread_mutex_t	coder_mutex;
	pthread_mutex_t	coder_waiting;
	pthread_cond_t	coder_cond;
}	t_coder;

typedef struct s_monitor
{
	pthread_t		monitor_id;
	pthread_mutex_t	monitor_mutex;
	pthread_cond_t	monitor_cond;
}	t_monitor;

typedef struct s_data
{
	bool			end_simulation;
	int				number_of_coders;
	int				number_of_compiles_required;
	t_scheduler		scheduler;
	long			start_time;
	long			time_to_burnout;
	long			time_to_compile;
	long			time_to_debug;
	long			time_to_refactor;
	long			dongle_cooldown;
	t_coder			*coders;
	t_dongle		*dongles;
	pthread_mutex_t	log_mutex;
	pthread_mutex_t	end_mutex;
	pthread_mutex_t	data_mutex;
	t_monitor		monitor;
}	t_data;
#endif
