/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 17:44:49 by shurtado          #+#    #+#             */
/*   Updated: 2024/10/29 13:48:24 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	all_is_digit(char *argv[]);
static int	all_is_integer(char *argv[]);
static int	none_repeated(char *argv[]);

bool	is_sorted(t_stack *a)
{
	t_node	*node;

	node = a->top;
	while (node)
	{
		if (node->next)
			if (node->value > node->next->value)
				return (false);
		node = node->next;
	}
	return (true);
}

int	args_ok(char *argv[])
{
	if (all_is_digit(argv) && all_is_integer(argv) && none_repeated(argv))
		return (EXIT_FAILURE);
	ft_printf("ERROR\n");
	return (EXIT_SUCCESS);
}

static int	all_is_digit(char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	all_is_integer(char *argv[])
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!ft_is_integer(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	none_repeated(char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 1;
		while (argv[j])
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]) && i != j)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
