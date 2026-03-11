/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dongle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafechte <vafechte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 14:07:29 by vafechte          #+#    #+#             */
/*   Updated: 2026/03/11 14:38:45 by vafechte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dongle.h"

bool	take_dongle(t_dongle *dongle)
{
	pthread_mutex_lock(&dongle->dongle_mutex);
	pthread_mutex_unlock(&dongle->dongle_mutex);
}
