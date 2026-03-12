/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafechte <vafechte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 09:29:08 by vafechte          #+#    #+#             */
/*   Updated: 2026/03/12 09:29:09 by vafechte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETTERS_H
# define SETTERS_H

# include <pthread.h>

void	set_int(int *v, int s, pthread_mutex_t *mutex);
void	set_long(long *v, long s, pthread_mutex_t *mutex);
#endif