/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 16:14:28 by shurtado          #+#    #+#             */
/*   Updated: 2024/08/25 18:50:56 by shurtado         ###   ########.fr       */
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

static int	get_max_num(t_node *node)
{
	int	result;

	result = 0;
	while (node)
	{
		if (node->value > result)
			result = node->value;
		node = node->next;
	}
	return (result);
}
/*
void	radix_sort(t_stack *a, t_stack *b, int max_num, int max_bits)
{
	int	i[2];
	int	size;
	int	num;

	max_num = get_max_num(a->top);
	while ((max_num >> max_bits) != 0)
		max_bits++;
	i[0] = 0;
	while (i[0] < max_bits)
	{
		i[1] = 0;
		size = a->size;
		while (i[1] < size)
		{
			num = a->top->value;
			if ((num >> i[0]) & 1)
				ra(a);
			else
				pb(a, b);
			i[1]++;
		}
		while (b->size > 0)
			pa(a, b);
		i[0]++;
	}
}
*/

void	shift_elements(t_stack *a, int i, t_stack *b)
{
	if ((a->top->value >> i) & 1)
	{
		if (direction(a->top, a->top->value, a->size) < 0)
			rra(a);
		else
			ra(a);
	}
	else
		pb(a, b);
}

void	process_bit(t_stack *a, t_stack *b, int i)
{
	int	j;
	int	size;

	j = 0;
	size = a->size;
	while (j < size)
	{
		shift_elements(a, i, b);
		j++;
	}
	while (b->size > 0)
		pa(a, b);
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int	max_num;
	int	max_bits;
	int	i;

	max_num = get_max_num(a->top);
	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		process_bit(a, b, i);
		i++;
	}
}
