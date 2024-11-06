/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:35:09 by shurtado          #+#    #+#             */
/*   Updated: 2024/11/03 19:01:24 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	do_move(const char *move)
{
	if (!ft_strcmp(move, "sa"))
		return ;
}

static bool	check_sorted(t_stack *a)
{
	t_node	*node;

	node = a->top;
	while (node)
	{
		if (node->next && node->value > node->next->value)
			return (false);
		node = node->next;
	}
	return (true);
}

static void	move_from_stdin(t_stack *a, t_stack *b)
{
	char	*temp;
	char	*move;

	temp = get_next_line(STDIN_FILENO);
	if (!temp)
		return ;
	while (temp)
	{
		move = ft_strtrim(temp,"\n");
		free (temp);
		temp = NULL;
		if (!move)
			return ;
		do_move (move);
		free (move);
		temp = get_next_line(STDIN_FILENO);
	}
	if (temp)
		free(temp);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 3)
		return (0);
	if (args_ok(argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	a = ft_calloc(sizeof(t_stack), 1);
	a->top = NULL;
	b = ft_calloc(sizeof(t_stack), 1);
	b->top = NULL;
	if (init_stack(a, argv, argc - 1) == EXIT_FAILURE)
		ft_printf("Hubo un error al asignar memoria en Stack!!\n");
	else
	{
		move_from_stdin(a, b);
		check_sorted(a);
	}
	free_stack(&a);
	free_stack(&b);
	return (0);
}
