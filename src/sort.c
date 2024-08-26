/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 18:37:25 by shurtado          #+#    #+#             */
/*   Updated: 2024/08/26 17:49:28 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	t_node	*node;

	node = a->top;
	while (node)
	{
		if (node->next)
			if (node->index > node->next->index)
				return (0);
		node = node->next;
	}
	return (1);
}

void	order_three(t_stack *a)
{
	t_node	*node;
	int	max;

	node = a->top;
	max = 0;
	while (node)
	{
		if (node->index > max)
			max = node->index;
		node = node->next;
	}
	if (is_sorted(a))
		return ;
	if (a->top->index == max)
		ra(a);
	else if (a->top->next->index == max)
		rra(a);
	if (a->top->index > a->top->next->index)
		sa(a);
}

void	sort(t_stack *a, t_stack *b)
{
	if (a->size == 2)
	{
		if (!is_sorted(a))
			sa(a);
	}
	else if (a->size == 3)
		order_three(a);
	else if (!is_sorted(a))
		sort_stack(a, b);
}
