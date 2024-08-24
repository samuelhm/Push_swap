/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 21:54:55 by shurtado          #+#    #+#             */
/*   Updated: 2024/08/24 23:18:07 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	t_node *test;

	if (!args_is_ok(argv))
		return (-1);
	a = ft_calloc(sizeof(t_stack), 1);
	b = ft_calloc(sizeof(t_stack), 1);
	init_stack(a, argv, argc - 1);
	test = a->top;
	while (test)
	{
		ft_printf("%d\n", test->value);
		test = test->next;
	}
	free_stack(&a);
	free_stack(&b);
	return (0);
}
