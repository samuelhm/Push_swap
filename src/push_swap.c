/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 21:54:55 by shurtado          #+#    #+#             */
/*   Updated: 2024/08/26 19:32:42 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 3)
		return (0);
	if (!args_is_ok(argv))
		return (-1);
	a = ft_calloc(sizeof(t_stack), 1);
	b = ft_calloc(sizeof(t_stack), 1);
	init_stack(a, argv, argc - 1);
	sort(a, b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}

void	print_node(t_node *node)
{
	printf("Node Value: %d\n", node->value - 412);
	printf("Node Index: %d\n", node->index);
	printf("Node CA: %d\n", node->ca);
	printf("Node CB: %d\n", node->cb);
	printf("Node POS: %d\n", node->pos);
	printf("Node Target: %d\n", node->target);
}
