/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafechte <vafechte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 11:19:57 by vafechte          #+#    #+#             */
/*   Updated: 2026/03/10 16:20:55 by vafechte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_DATA_H
# define FREE_DATA_H

# include "codexion.h"

void	free_dongle(t_dongle *dongles, int size);
void	free_coder(t_coder *coders, int size);
void	free_monitor(t_monitor *monitor);
void	free_data_mutex_and_cond(t_data *data);
void	cleanup_data(t_data *data);
#endif