/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 16:51:48 by shurtado          #+#    #+#             */
/*   Updated: 2024/08/25 18:03:20 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	direction(t_node *node, int min, int size)
{
	int		rup;
	int		rdown;
	t_node	*top;

	top = node;
	rup = 0;
	while (top->value != min)
	{
		top = top->next;
		rup++;
	}
	rdown = size - rup;
	return (rup - rdown);
}

void	insert_sort(t_stack *a, t_stack *b)
{
	t_node	*node;
	int		size;

	size = a->size;
	while (b->size < size)
	{
		node = a->top;
		while (node->value != get_min(a))
		{
			if (direction(node, get_min(a), a->size) < 0)
				ra(a);
			else
				rra(a);
			node = a->top;
		}
		pb(a, b);
	}
	while (a->size < size)
		pa(a, b);
}
