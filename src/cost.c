/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 23:56:49 by shurtado          #+#    #+#             */
/*   Updated: 2024/08/26 17:58:15 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_cost(t_stack *a, t_stack *b)
{
	t_node	*bnode;

	bnode = b->top;

	while (bnode)
	{
		bnode->cb = bnode->pos;
		if (bnode->pos > b->size / 2)
			bnode->cb = (b->size - bnode->pos) * -1;
		bnode->ca = bnode->target;
		if (bnode->target > a->size / 2)
			bnode->ca = (a->size - bnode->target) * -1;
		bnode = bnode->next;
	}
}

void	cheap_move(t_stack *a, t_stack *b)
{
	t_node	*node;
	int		cheap;
	int		cost_a;
	int		cost_b;

	node = b->top;
	cheap = INT_MAX;
	while (node)
	{
		if (abs(node->ca) + abs(node->cb) < cheap)
		{
			cheap = abs(node->ca) + abs(node->cb);
			cost_a = node->ca;
			cost_b = node->cb;
		}
		node = node->next;
	}
	move(a, b, cost_a, cost_b);
}

int	low_index_pos(t_stack *a)
{
	t_node	*node;
	int		li;
	int		lp;

	node = a->top;
	li = INT_MAX;
	set_pos(a);
	lp = node->pos;
	while (node)
	{
		if (node->index < li)
		{
			li = node->index;
			lp = node->pos;
		}
		node = node->next;
	}
	return (lp);
}

void	set_target_pos(t_stack *a, t_stack *b)
{
	t_node	*node;
	int		target;

	node = b->top;
	set_pos(a);
	set_pos(b);
	target = 0;
	while (node)
	{
		target = set_target(a, node->index, INT_MAX, target);
		node->target = target;
		node = node->next;
	}
}
