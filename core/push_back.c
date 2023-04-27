#include "../push_swap.h"

// int	find_max(t_stack *a)
// {
// 	int	max;
// 	int i = 0;
// 	t_stack *lst;

// 	lst = a;
// 	max = lst->num;
// 	while (lst)
// 	{
// 		if (max < lst->num)
// 			max = lst->num;
// 		lst = lst->next;
// 	}
// 	lst = a;
// 	while (lst)
// 	{
// 		if (max == lst->num)
// 			return (i);
// 		lst = lst->next;
// 		i++;
// 	}
// 	return (i);
// }

// int	find_before_max(t_stack *b)
// {
// 	t_stack	*lst;
// 	int	    max;
// 	int		before_max;
// 	int		i;

// 	lst = b;
// 	max = lst->num;
// 	while (lst)
// 	{
// 		if (max < lst->num)
// 			max = lst->num;
// 		lst = lst->next;
// 	}
// 	lst = b;
// 	before_max = -2147483648;
// 	while (lst)
// 	{
// 		if (before_max < lst->num && lst->num != max)
// 			before_max = lst->num;
// 		lst = lst->next;
// 	}
// 	lst = b;
// 	i = 0;
// 	while (lst)
// 	{
// 		if (before_max == lst->num)
// 			return (i);
// 		lst = lst->next;
// 		i++;
// 	}
// 	return (i);
// }

int	is_less_instractions(int max, int before_max, int size)
{
	
	int mid;
	int i = 0;
	int	j = 0;

	mid = size / 2;
	if (max <= mid)
	{
		if (before_max > mid)
		{
			i =  max;
			j = size - before_max;
		}
		else
			return (max < before_max);
	}
	else
	{
		if (before_max <= mid)
		{
			i = size - max;
			j = before_max;
		}
		else 
			return (max > before_max);
	}
	//i : number of instructions needed to put the max at the top.
	//j : number of instructions needed to put the before_max at the top.
	return(i <= j);
}

void	to_push(int nbr, t_stack **b, t_stack **a)
{
	if (nbr > ft_lstsize(*b) / 2)
	{
		while (nbr++ < ft_lstsize(*b))
			reverse_rotate(b, "rrb\n", true);
	}
	else
	{
		while (nbr--)
			rotate(b, "rb\n", true);
	}
	push(b, a, "pa\n", true);
}

void	push_back(t_stack **b, t_stack **a)
{
	int	max;
	int	before_max;
	int	size;

	while (*b)
	{
		max = find_max(*b);
		before_max = find_before_max(*b);
		size = ft_lstsize(*b);
		//after finding the position of (max and before max) ->
		//check which one needs fewer instractions to be pushed
		if (is_less_instractions(max, before_max, size))	
			to_push(max, b, a);
		else
		{
			to_push(before_max, b, a);
			max = find_max(*b);
			to_push(max, b, a);
			swap(*a, "sa\n", true);
		}
	}
}
