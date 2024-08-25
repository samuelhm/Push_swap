/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 18:37:25 by shurtado          #+#    #+#             */
/*   Updated: 2024/08/25 19:09:24 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	order_three(t_stack *a)
{
	int	node[3];

	node[0] = a->top->value;
	node[1] = a->top->next->value;
	node[2] = a->top->next->next->value;

	if (node[0] > node[1] && node[1] < node[2] && node[0] < node[2])
		sa(a);
	else if (node[0] > node[1] && node[1] > node[2])
	{
		sa(a);
		rra(a);
	}
	else if (node[0] > node[1] && node[1] < node[2] && node[0] > node[2])
		ra(a);
	else if (node[0] < node[1] && node[1] > node[2] && node[0] < node[2])
	{
		sa(a);
		ra(a);
	}
	else if (node[0] < node[1] && node[1] > node[2] && node[0] > node[2])
		rra(a);
}

void	sort(t_stack *a, t_stack *b)
{
	if (a->size == 2)
	{
		if (a->top->value > a->top->next->value)
			sa(a);
	}
	else if (a->size == 3)
		order_three(a);
	else if (a->size < 40)
		insert_sort(a, b);
	else
		radix_sort(a, b);
}
