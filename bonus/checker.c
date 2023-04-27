#include "../push_swap.h"

void	execute(char *move, t_stack **a, t_stack **b)
{
	if (ft_strcmp(move, "sa") == 0) 
		swap(*a, "", false);
	else if (ft_strcmp(move, "sb")== 0) 
		swap(*b, "", false);
	else if (ft_strcmp(move, "ra" )== 0)
		rotate(a, "", false);
	else if (ft_strcmp(move, "rb")== 0) 
		rotate(b, "", false);
	else if (ft_strcmp(move, "pa")== 0) 
		push(b, a, "", false);
	else if (ft_strcmp(move, "pb")== 0) 
		push(a, b, "", false);
	else if (ft_strcmp(move, "rra")== 0 )
		reverse_rotate(a, "", false);
	else if (ft_strcmp(move, "rrb") == 0)
		reverse_rotate(b, "", false);
	else
		return (free(move));
	free(move); 
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack *b;
	char	*move;

	a = store_up(ac, 0, av);
	b = NULL;
	while (true)
	{
		move = gnl(0);
		if (!move)
			break;
		execute(move, &a, &b);
	}
	if (sorted(a))
		write (1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (free(move), 0);
}