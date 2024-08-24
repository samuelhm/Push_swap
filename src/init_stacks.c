/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 20:03:29 by shurtado          #+#    #+#             */
/*   Updated: 2024/08/25 00:22:06 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_stack(t_stack *a, char *argv[], int ssize)
{
	t_node	*temp;
	int		i;

	a->size = ssize;
	i = ssize;
	a->size = ssize;
	while (i >= 1)
	{
		temp = ft_calloc(sizeof(t_node), 1);
		temp->value = ft_atoi(argv[i]);
		if (a->top == NULL)
			a->top = temp;
		else
		{
			a->top->prev = temp;
			temp->next = a->top;
			a->top = temp;
		}
		i--;
	}
	return (1);
}

void	free_stack(t_stack **a)
{
	t_node	*node;
	t_node	*next;

	if (!a || !(*a))
		return ;
	node = (*a)->top;
	while (node)
	{
		next = node->next;
		free(node);
		node = next;
	}
	free(*a);
	*a = NULL;
}
