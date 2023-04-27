#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack *a;
	t_stack	*b;
	int		size;

	
	if (ac < 2)
		exit (0);
	b = NULL;
	size = 1;
	a = store_up(ac, &size, av);
	if (!sorted(a))
		sort(&a,&b, size);
	free(a);
	return (0);
	
	// while(a)
	// {
	// 	printf("%d\n", a->num);
	// 	a = a->next;
	// }
}