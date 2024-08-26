/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 01:22:27 by shurtado          #+#    #+#             */
/*   Updated: 2024/08/26 01:49:45 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void revboth(t_stack *a, t_stack *b, int *ca, int *cb)
{
	while (*ca < 0 && *cb < 0)
	{
		(*ca)++;
		(*cb)++;
		rrr(a, b);
	}
}

static void	rotboth(t_stack *a, t_stack *b, int *ca, int *cb)
{
	while (*ca > 0 && *cb > 0)
	{
		(*ca)--;
		(*cb)--;
		rr(a, b);
	}
}

static void	rota(t_stack *a, int *ca)
{
	while (*ca)
	{
		if (*ca > 0)
		{
			ra(a);
			(*ca)--;
		}
		else if (*ca < 0)
		{
			rra(a);
			(*ca)++;
		}
	}
}

static void	rotb(t_stack *b, int *cb)
{
	while (*cb)
	{
		if (*cb > 0)
		{
			rb(b);
			(*cb)--;
		}
		else if (*cb < 0)
		{
			rrb(b);
			(*cb)++;
		}
	}
}

void	move(t_stack *a, t_stack *b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		revboth(a, b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		rotboth(a, b, &cost_a, &cost_b);
	rota(a, &cost_a);
	rotb(b, &cost_b);
	pa(a, b);

}
