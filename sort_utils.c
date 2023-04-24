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
	else
		return ;	
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

// int	init_hold_butt(t_stack *a, int start, int end)
// {
// 	// int		hold_top;
// 	// int		hold_butt;
// 	int		i;
// 	t_stack	*tmp;

// 	tmp = a;
// 	i = 0;
// 	while (tmp)
// 	{
// 		if (tmp->index >= start && tmp->index <= end)
// 			return (i);
// 		i++;
// 		tmp = tmp->next;
// 	}
// 	return (0);
// }


// int	init_hold_top(t_stack *a, int start, int end)
// {
// 	// int		hold_top;
// 	// int		hold_butt;
// 	int		i;
// 	t_stack	*tmp;

// 	tmp = a;
// 	i = 0;
// 	while (tmp)
// 	{
// 		if (tmp->index >= start && tmp->index <= end)
// 			return (i);
// 		i++;
// 		tmp = tmp->next;
// 	}
// 	return (0);
// }

void	sort_chunk(t_stack **a, t_stack **b, int start, int end)
{
	// t_stack	*a;
	int		mid;
	int		count;

	// a = *a;
	count = 0;
	mid = ((end - start + 1) / 2 ) + start;
	// printf ("%d\n", mid);
	while (*a)
	{
		// printf (" %d\n", count);
		if (count == end - start)
			break ;
		if ((*a)->index < start || (*a)->index > end){
			rotate(a, "ra\n");
			// (*a) = (*a)->next;	
			// continue ;
		}
		else
		{
			if (*b)
			{
				if ((*a)->index < mid){
					push(a, b, "pb\n");
					count++;
				}
				else{
					push(a, b, "pb\n");
					rotate(b, "rb\n");
					count++;
				}
			}
			else{
				push(a, b, "pb\n");
				count++;
			}

		}

		(*a) = (*a)->next;
	}
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

int	sorted(t_stack *a)
{
	t_stack	*tmp;

	tmp = a;
	while (tmp->next)
	{
		if (tmp->num > tmp->next->num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
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
		if (!sorted(*a))
			sort_five(a, b);
	}
	else
		ft_chunk(a, b, 5, size);
}