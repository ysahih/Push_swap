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
		rotate(a, "ra\n");
	if (i == 1)
		reverse_rotate(a, "rra\n");
	if ((*a)->num > (*a)->next->num)
		swap(*a, "sa\n");	
}

void	sort_five(t_stack **a, t_stack **b)
{
	int	i;

	if (ft_lstsize(*a) > 3)
	{
		i = find_min(*a);
		if (i < 3)
		{
			while (i > 0)
			{
				rotate(a, "ra\n");
				i--;
			}
		}
		else
		{
			while (i < ft_lstsize(*a))
			{
				reverse_rotate(a, "rra\n");
				i++;
			}
		}
		push(a, b, "pb\n");
		sort_five(a, b);
	}
	sort_three(a);
	while (*b)
		push(b, a, "pa\n");
}

void	sort_chunk(t_stack **a, t_stack **b, int start, int end)
{
	t_stack	*tmp1;
	// t_stack	*tmp2;


}

void	ft_chunk(t_stack **a, t_stack **b, int x, int size)
{
	int	start;
	int	end;
	int	i;

	i = 1;
	start = 0;
	while (i <= x)
	{
		if (i == x)
		{
			end = size;
			sort_chunk(a, b, start, end);
		}
		else
		{
			end = (size / x) * i - 1;
			sort_chunk(a, b, start, end);
			// printf("start : %d,end : %d\n", start, end);
			start = ++end;
		}
		i++;
	}
	// int	i;


	// while(*a)
	// {
	// 	i = find_min(*a);
	// 	if (i < (size / 2))
	// 	{
	// 		while (i--)
	// 			rotate(a, "ra\n");
	// 	}
	// 	else 
	// 	{
	// 		while (i++ < ft_lstsize(*a))
	// 			reverse_rotate(a, "rra\n");
	// 	}
	// 	push(a, b, "pb\n");
	// }
	
	// while (*b)
	// 	push(b, a, "pa\n");
}



void	sort(t_stack **a, t_stack **b, int size)
{
	int	i;

	if (size <= 5)
	{
		if (size <= 3)
		{
			if (size == 1)
				return ;
			else if (size == 2)
			{
				if ((*a)->num > (*a)->next->num)
					swap(*a, "sa\n");
				else
					return ;
			}
			else if (size == 3)
				sort_three(a);
		}
		sort_five(a, b);
	}
	else
		ft_chunk(a, b, 5, size);
}