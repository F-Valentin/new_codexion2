/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafechte <vafechte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 09:28:11 by vafechte          #+#    #+#             */
/*   Updated: 2026/03/12 09:28:21 by vafechte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	set_long(long *v, long s, pthread_mutex_t *mutex)
{
	pthread_mutex_lock(mutex);
	*v = s;
	pthread_mutex_unlock(mutex);
}

void	set_int(int *v, int s, pthread_mutex_t *mutex)
{
	pthread_mutex_lock(mutex);
	*v = s;
	pthread_mutex_unlock(mutex);
}
