/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverses.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 00:59:51 by shurtado          #+#    #+#             */
/*   Updated: 2024/08/26 03:15:54 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rrotate(t_stack *a)
{
	t_node	*ultimo;
	t_node	*penultimo;

	if (!a || !a->top || !a->top->next)
		return ;
	ultimo = a->top;
	penultimo = NULL;
	while (ultimo->next)
	{
		penultimo = ultimo;
		ultimo = ultimo ->next;
	}
	if (penultimo)
		penultimo->next = NULL;
	ultimo->prev = NULL;
	ultimo->next = a->top;
	a->top->prev = ultimo;
	a->top = ultimo;
}

void	rra(t_stack *a)
{
	rrotate(a);
	ft_printf("rra\n");
}

void	rrb(t_stack *b)
{
	rrotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_stack *a, t_stack *b)
{
	rrotate(a);
	rrotate(b);
	ft_printf("rrr\n");
}
