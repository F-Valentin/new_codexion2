/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_simulation.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafechte <vafechte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 10:59:33 by vafechte          #+#    #+#             */
/*   Updated: 2026/03/11 12:48:03 by vafechte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_SIMULATION_H
# define CHECK_SIMULATION_H

# include <stdbool.h>
# include "codexion.h"

bool	check_coders_burnout(t_data *data);
bool	is_simulation_finished(t_data *data);
#endif