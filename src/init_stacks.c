/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 20:03:29 by shurtado          #+#    #+#             */
/*   Updated: 2024/08/26 19:32:14 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_index(t_stack *a)
{
	t_node	*current;
	t_node	*compare;
	int		index;

	current = a->top;
	while (current)
	{
		index = 1;
		compare = a->top;
		while (compare)
		{
			if (current->value > compare->value)
				index++;
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
	}
}

int	get_min(t_stack *a)
{
	t_node	*node;
	int		min;

	node = a->top;
	min = node->value;
	while (node)
	{
		if (node->value < min)
			min = node->value;
		node = node->next;
	}
	return (min);
}

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
	set_index(a);
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
