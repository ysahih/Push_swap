#include "push_swap.h"

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

void sort_three(t_stack **a)
{
	int	i;

	i = find_max(*a);
	if (i == 0)
		rotate(a);
	if (i == 1)
		reverse_rotate(a);
	if ((*a)->num > (*a)->next->num)
		swap(*a);	
}

void	sort_five(t_stack **a, t_stack **b)
{
	int	i;
	int	count;

	count = 2;
	if(ft_lstsize(*a) > 3)
	{

		i = find_min(*a);
		if (i < 3)
		{
			while (i > 0)
			{
				rotate(a);
				i--;
			}
		}
		else
		{
			while (i < 5)
			{
				reverse_rotate(a);
				i++;
			}
		}
		push(a, b);
		sort_five(a, b);
	}
	sort_three(a);
 	// while(*a)
	// {	
	// 	printf("%d\n", (*a)->num);
	// 	*a = (*a)->next;

	// }
	while (*b)
	{
		push(b, a);
	}
	// while(*a)
	// {	
	// 	printf("%d\n", (*a)->num);
	// 	*a = (*a)->next;

	// }
	
}
void	sort(t_stack **a, t_stack **b, int size)
{
	int	i;

	if (size <= 5)
	{
		if (size <= 3)
		{
			if (size == 2)
			{
				if ((*a)->num > (*a)->next->num)
					swap(*a);
			}
			else if (size == 3)
				sort_three(a);
		}
		sort_five(a, b);
	}
}