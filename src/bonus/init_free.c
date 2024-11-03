#include "push_swap_bonus.h"

int	init_stack(t_stack *a, char *argv[], int ssize)
{
	t_node	*temp;
	int		i;

	i = ssize;
	a->size = ssize;
	while (i >= 1)
	{
		temp = ft_calloc(sizeof(t_node), 1);
		if (!temp)
			exit(EXIT_FAILURE);
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
	return (EXIT_SUCCESS);
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