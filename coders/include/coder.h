/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafechte <vafechte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 14:38:26 by vafechte          #+#    #+#             */
/*   Updated: 2026/03/11 16:05:34 by vafechte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODER_H
# define CODER_H

# include <stdbool.h>
# include "codexion.h"

bool	compiling(t_coder *coder);
void	*one_coder(t_data *data);
void	*coder_simulation(void *arg);
#endif