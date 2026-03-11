/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafechte <vafechte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 10:59:23 by vafechte          #+#    #+#             */
/*   Updated: 2026/03/11 10:59:24 by vafechte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GETTERS_H
# define GETTERS_H

# include <pthread.h>

long	get_long(long *value, pthread_mutex_t *mutex);
int		get_int(int *value, pthread_mutex_t *mutex);
#endif