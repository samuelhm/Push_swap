/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 00:25:45 by shurtado          #+#    #+#             */
/*   Updated: 2024/11/03 19:02:49 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack *from, t_stack *to)
{
	t_node	*newtop;

	if (!from || !from->top)
		return ;
	newtop = from->top->next;
	if (newtop)
		newtop->prev = NULL;
	from->top->next = to->top;
	if (to->top)
		to->top->prev = from->top;
	to->top = from->top;
	from->top = newtop;
	from->size--;
	to->size++;
}

void	pa(t_stack *a, t_stack *b)
{
	push(b, a);
}

void	pb(t_stack *a, t_stack *b)
{
	push(a, b);
}