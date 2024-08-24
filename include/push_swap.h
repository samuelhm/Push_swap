/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 21:55:34 by shurtado          #+#    #+#             */
/*   Updated: 2024/08/24 17:58:52 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
	int				pos;
	int				target;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

int	args_is_ok(char *argv[]);

#endif
