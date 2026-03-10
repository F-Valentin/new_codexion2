/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafechte <vafechte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 16:50:06 by vafechte          #+#    #+#             */
/*   Updated: 2026/03/06 16:50:07 by vafechte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAP_H
# define HEAP_H

# include <stdbool.h>

typedef struct s_heap_node
{
	int		coder_id;
	long	priority;
}	t_heap_node;

typedef struct s_heap
{
	t_heap_node	*nodes;
	int			size;
	int			capacity;
}	t_heap;

bool	heap_insert(t_heap *heap, int coder_id, long priority);
int		heap_extract_min(t_heap *heap);
int		heap_peak_min(t_heap *heap);
#endif
