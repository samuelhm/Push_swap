/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 21:55:34 by shurtado          #+#    #+#             */
/*   Updated: 2024/10/29 13:51:23 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "libft.h"
# include "limits.h"

typedef struct s_node
{
	int				value;
	int				index;
	int				ca;
	int				cb;
	int				pos;
	int				target;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

//Util Functions
int		args_is_ok(char *argv[]);
int		init_stack(t_stack *a, char *argv[], int ssize);
void	free_stack(t_stack **a);
int		get_min(t_stack *a);
void	sort(t_stack *a, t_stack *b);
void	calculate_cost(t_stack *a, t_stack *b);
void	move(t_stack *a, t_stack *b, int cost_a, int cost_b);
int		is_sorted(t_stack *a);
int		low_index_pos(t_stack *a);
void	set_pos(t_stack *a);
void	set_target_pos(t_stack *a, t_stack *b);
int		set_target(t_stack *a, int ib, int ti, int target);
void	cheap_move(t_stack *a, t_stack *b);

//void	print_node(t_node *node);
//void	print_stack(t_stack *a);

//Legal Moves
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

//Algorhitms
void	order_three(t_stack *a);
void	sort_stack(t_stack *a, t_stack *b);

#endif
