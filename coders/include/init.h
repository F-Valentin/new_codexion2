/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafechte <vafechte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 11:11:21 by vafechte          #+#    #+#             */
/*   Updated: 2026/03/10 11:23:50 by vafechte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include <stdbool.h>
# include "codexion.h"

bool	parsing_input(t_data *data, char **av);
bool	init(t_data *data);
#endif