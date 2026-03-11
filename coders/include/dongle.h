/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dongle.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafechte <vafechte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 14:06:22 by vafechte          #+#    #+#             */
/*   Updated: 2026/03/11 14:56:24 by vafechte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DONGLE_H
# define DONGLE_H

# include <stdbool.h>
# include "codexion.h"

bool	take_dongle(t_coder *coder, t_dongle *dongle);
void	release_dongle(t_dongle *dongle);
#endif