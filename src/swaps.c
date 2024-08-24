/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 23:40:41 by shurtado          #+#    #+#             */
/*   Updated: 2024/08/25 00:56:35 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_nodes(t_node *one, t_node *two)
{
	one->next = two->next;
	if (two->next)
		two->next->prev = one;
	two->prev = NULL;
	two->next = one;
	one->prev = two;
}

static void	swap(t_stack *a)
{
	if (!a || !a->top || !a->top->next)
		return ;
	swap_nodes(a->top, a->top->next);
	a->top = a->top->prev;
	return ;
}

void	sa(t_stack *a)
{
	swap(a);
	ft_printf("sa\n");
}

void	sb(t_stack *b)
{
	swap(b);
	ft_printf("sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}
