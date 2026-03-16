/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafechte <vafechte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 16:49:44 by vafechte          #+#    #+#             */
/*   Updated: 2026/03/16 12:46:12 by vafechte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heap.h"
#include <stdbool.h>
#include <stdio.h>

bool	heap_insert(t_heap *heap, int coder_id, long priority)
{
	int			i;
	int			parent;
	t_heap_node	temp;

	i = heap->size;
	heap->size++;
	if (heap->size > heap->capacity)
		return (heap->size--, false);
	heap->nodes[i].coder_id = coder_id;
	heap->nodes[i].priority = priority;
	while (i != 0)
	{
		parent = (i - 1) / 2;
		if (heap->nodes[parent].priority <= heap->nodes[i].priority)
			break ;
		temp = heap->nodes[parent];
		heap->nodes[parent] = heap->nodes[i];
		heap->nodes[i] = temp;
		i = parent;
	}
	return (true);
}

static void	heapify(t_heap_node *nodes, int size)
{
	int			i;
	int			left;
	int			right;
	long		smallest;
	t_heap_node	temp;

	i = 0;
	while (1)
	{
		smallest = i;
		left = 2 * i + 1;
		right = 2 * i + 2;
		if (left < size && nodes[left].priority < nodes[smallest].priority)
			smallest = left;
		if (right < size && nodes[right].priority < nodes[smallest].priority)
			smallest = right;
		if (smallest == i)
			break ;
		temp = nodes[i];
		nodes[i] = nodes[smallest];
		nodes[smallest] = temp;
		i = smallest;
	}
}

int	heap_extract_min(t_heap *heap)
{
	int	coder_id;

	if (heap->size == 0)
		return (-1);
	coder_id = heap->nodes[0].coder_id;
	heap->nodes[0] = heap->nodes[heap->size - 1];
	heap->size--;
	heapify(heap->nodes, heap->size);
	return (coder_id);
}

int	heap_peek_min(t_heap *heap)
{
	return (heap->nodes[0].coder_id);
}
