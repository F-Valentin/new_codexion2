/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafechte <vafechte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 10:59:51 by vafechte          #+#    #+#             */
/*   Updated: 2026/03/11 10:59:54 by vafechte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "getters.h"

long	get_long(long *value, pthread_mutex_t *mutex)
{
	long	v;

	pthread_mutex_lock(mutex);
	v = *value;
	pthread_mutex_unlock(mutex);
	return (v);
}

int	get_int(int *value, pthread_mutex_t *mutex)
{
	int	v;

	pthread_mutex_lock(mutex);
	v = *value;
	pthread_mutex_unlock(mutex);
	return (v);
}
