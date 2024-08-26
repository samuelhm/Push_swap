/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 00:04:04 by shurtado          #+#    #+#             */
/*   Updated: 2024/08/26 17:58:21 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_sort(t_stack *a, t_stack *b)
{
	int	pushes;
	int	size;
	int	i;

	size = a->size;
	pushes = 0;
	i = 0;
	while (size > 6 && i < size && pushes < size / 2)
	{
		if (a->top->index <= size / 2)
		{
			pb(a, b);
			pushes++;
		}
		else
		{
			ra(a);
		}
		i++;
	}
	while (size - pushes > 3)
	{
		pb(a, b);
		pushes++;
	}
}

void	set_pos(t_stack *a)
{
	t_node	*node;
	int		i;

	node = a->top;
	i = 0;
	while (node)
	{
		node->pos = i;
		node = node->next;
		i++;
	}
}

int	set_target(t_stack *a, int ib, int ti, int target)
{
	t_node	*node;

	node = a->top;
	while (node)
	{
		if (node->index > ib && node->index < ti)
		{
			ti = node->index;
			target = node->pos;
		}
		node = node->next;
	}
	if (ti != INT_MAX)
		return (target);
	node = a->top;
	while (node)
	{
		if (node->index < ti)
		{
			ti = node->index;
			target = node->pos;
		}
		node = node->next;
	}
	return (target);
}

static void	re_sort(t_stack *a)
{
	int	lp;
	int	ssize;

	ssize = a->size;
	lp = low_index_pos(a);
	if (lp > ssize / 2)
	{
		while (lp < ssize)
		{
			rra(a);
			lp++;
		}
	}
	else
	{
		while (lp > 0)
		{
			ra(a);
			lp--;
		}
	}
}

void	sort_stack(t_stack *a, t_stack *b)
{
	init_sort(a, b);
	order_three(a);
	while (b->top)
	{
		set_target_pos(a, b);
		calculate_cost(a, b);
		cheap_move(a, b);
	}
	if (!is_sorted(a))
		re_sort(a);
}
