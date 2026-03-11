/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dongle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafechte <vafechte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 14:07:29 by vafechte          #+#    #+#             */
/*   Updated: 2026/03/11 14:58:32 by vafechte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dongle.h"
#include "utils.h"
#include "check_simulation.h"

bool	take_dongle(t_coder *coder, t_dongle *dongle)
{
	if (is_simulation_finished(coder->data))
		return (false);
	pthread_mutex_lock(&dongle->dongle_mutex);
	log_status(coder, "has taken a dongle");
	return (true);
}

void	release_dongle(t_dongle *dongle)
{
	pthread_mutex_unlock(&dongle->dongle_mutex);
}
