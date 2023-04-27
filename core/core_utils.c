#include "../push_swap.h"

int find_min(t_stack *a)
{
	int		min;
	int		i;
	t_stack	*tmp;

	tmp = a;
	i = 0;
	min = tmp->num;
	while (tmp)
	{
		if (tmp->num < min)
			min = tmp->num;
		tmp = tmp->next;
	}
	tmp = a;
	while (tmp)
	{
		if (tmp->num == min)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return i;
}

int	find_max(t_stack *a)
{
	int	max;
	int i = 0;
	t_stack *lst;

	lst = a;
	max = lst->num;
	while (lst)
	{
		if (max < lst->num)
			max = lst->num;
		lst = lst->next;
	}
	lst = a;
	while (lst)
	{
		if (max == lst->num)
			return (i);
		lst = lst->next;
		i++;
	}
	return (i);
}

int	find_before_max(t_stack *b)
{
	t_stack	*lst;
	int	    max;
	int		before_max;
	int		i;

	lst = b;
	max = lst->num;
	while (lst)
	{
		if (max < lst->num)
			max = lst->num;
		lst = lst->next;
	}
	lst = b;
	before_max = -2147483648;
	while (lst)
	{
		if (before_max < lst->num && lst->num != max)
			before_max = lst->num;
		lst = lst->next;
	}
	lst = b;
	i = 0;
	while (lst)
	{
		if (before_max == lst->num)
			return (i);
		lst = lst->next;
		i++;
	}
	return (i);
}