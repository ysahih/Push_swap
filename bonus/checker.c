#include "../push_swap.h"

void	execute(char *move, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(move, "sa"))
		swap(*a, "", false);
	else if (!ft_strcmp(move, "sb"))
		swap(*b, "", false);
	else if (!ft_strcmp(move, "ra\n"))
		rotate(a, "", false);
	else if (!ft_strcmp(move, "rb"))
		rotate(b, "", false);
	else if (!ft_strcmp(move, "pa"))
		push(b, a, "", false);
	else if (!ft_strcmp(move, "pb"))
		push(a, b, "", false);
	else if (!ft_strcmp(move, "rra"))
		reverse_rotate(a, "", false);
	else if (!ft_strcmp(move, "rrb"))
		reverse_rotate(b, "", false);
	else
		return ;
	free(move); 
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack *b;
	char	*move;

	a = store_up(ac, 0, av);
	while (true)
	{
		move = gnl(0);
		if (!move)
			break;
		printf("|%s|\n", move);
		execute(move, &a, &b);
	}
	while (a) 
	{
		printf("%d\n", a->num);
		a = a->next;
	}
	if (sorted(a))
		write (1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(move);
	return (0);
}