/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafechte <vafechte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 11:11:17 by vafechte          #+#    #+#             */
/*   Updated: 2026/03/11 15:35:17 by vafechte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "codexion.h"

long	ft_atol(const char *str);
void	log_status(t_coder *coder, const char *status);
void	wake_up_all_coders(t_coder *coders, int size);
#endif