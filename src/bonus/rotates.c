/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 00:41:35 by shurtado          #+#    #+#             */
/*   Updated: 2024/11/03 19:03:22 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack *a)
{
	t_node	*first;
	t_node	*last;

	if (!a || !a->top || !a->top->next)
		return ;
	first = a->top;
	last = a->top;
	while (last->next)
		last = last->next;
	a->top = first->next;
	a->top->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	ra(t_stack *a)
{
	rotate(a);
}

void	rb(t_stack *b)
{
	rotate(b);
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
}
