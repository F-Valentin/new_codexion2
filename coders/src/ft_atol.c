/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafechte <vafechte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 16:49:37 by vafechte          #+#    #+#             */
/*   Updated: 2026/03/10 11:05:27 by vafechte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>

static inline bool	is_space(const char c)
{
	return (c == ' ' || c == '\t');
}

static inline bool	is_digit(const char c)
{
	return (c >= '0' && c <= '9');
}

long	ft_atol(const char *str)
{
	int		i;
	long	number;

	i = 0;
	number = 0;
	while (is_space(str[i]))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
		return ((void)printf("Error: Negative number.\n"), -1);
	if (!is_digit(str[i]))
		return ((void)printf("Error: Invalid number.\n"), -1);
	while (is_digit(str[i]))
	{
		if (__builtin_mul_overflow(number, 10, &number)
			||__builtin_add_overflow(number, str[i] - 48, &number))
			return ((void)printf("Error: Number too big.\n"), -1);
		i++;
	}
	return (number);
}
