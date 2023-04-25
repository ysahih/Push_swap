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

void	sort_chunk(t_stack **a, t_stack **b, int start, int end)
{
	int		mid;
	int		count;

		printf("end : %d, start : %d\n", end ,  start);
	int size = ft_lstsize(*a);
	count = start;
	mid = ((end - start + 1) / 2 ) + start;
	while (count <= end)
	{
		if (*a)
		{
			// if ((*a))
			// printf("|%d|\n", (*a)->index);
			if (start <= size)
				while ((*a)->index < start || (*a)->index > end)
					rotate(a, "ra\n");
			else if ( start > size)
				while ((*a)->index < start || (*a)->index > end)
					reverse_rotate(a, "rra\n");
			if ((*a)->index >= start || (*a)->index <= end)
			{
				if (!*b)
					push(a, b, "pb\n");
				else
				{
					if ((*a)->index < mid)
						push(a, b, "pb\n");
					else
					{
						push(a, b, "pb\n");
						rotate(b, "rb\n");
					}
				}
			}
		}
			count++;
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
			end = size - 1;
			sort_chunk(a, b, start, end);
			return ;
		}
		else
		{
			int j;
			int k = size / x;
			j = i;
			if (k == 1 && i == 1)
			{	
				k = 5;
				i = x - 1;
			}
			end = k * j - 1;
			sort_chunk(a, b, start, end);
			start = ++end;
		}
		i++;
	}
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

int	find_before_max(t_stack *b)
{
	t_stack	*tmp;
	int		before_max;
	int		i;

	tmp = b;
	before_max = tmp->index;
	while (tmp)
	{
		if (before_max < tmp->index)
			before_max = tmp->index;
		tmp = tmp->next;
	}
	tmp = b;
	i = 0;
	before_max--;
	while (tmp)
	{
		if (before_max == tmp->index)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int	is_less_instractions(int max, int before_max, int size)
{
	// t_stack	*tmp;
	int mid;
	int i = 0;
	int	j = 0;

	mid = size / 2;
	// if (max > mid && before_max <= mid)
	// {
	// 	i = size - max;
	// 	j = before_max;
	
	// }
	// else if (max > mid && before_max > mid)
	// {
	// 	i = size - max;
	// 	j = size - before_max;
	// }
	// else if (max < mid && before_max >= mid)
	// {
	// 	i = max;
	// 	j = size - before_max;	
	// }
	// else if (max < mid && before_max < mid)
	// {
	// 	i = max;
	// 	j = before_max;
	// }
	// else if (max == mid && before_max < mid)
	// {
	// 	i =  max;
	// 	j = before_max;
	// }
	// else if (max == mid && before_max > mid)
	// {
	// 	i = max;
	// 	j = size - before_max;
	// }
	printf("max |%d|, be max |%d|\n", max, before_max);
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
	else if (max > mid)
	{
		if (before_max <= mid)
		{
			i = size - max;
			j = before_max;
		}
		else 
			return (max > before_max);
	}
	// printf("|i = %d||j = %d|\n", i , j);
	return(i <= j);
}

void	to_push(int nbr, t_stack **b, t_stack **a)
{
	printf("|i = %d||j = %d|\n", nbr, ft_lstsize(*b) / 2);
	if (nbr > ft_lstsize(*b) / 2)
	{
		while (nbr++ < ft_lstsize(*b))
			reverse_rotate(b, "rrb\n");
	}
	else
	{
		while (nbr--)
			rotate(b, "rb\n");
	}
	push(b, a, "pa\n");
}

void	push_back(t_stack **b, t_stack **a)
{

	t_stack	*tmp;
	tmp = *b;

	while (tmp)
	{
		printf("%d\n", tmp->num);
		tmp = tmp->next;

	}
	
	int	max;
	int	before_max;
	int	size;

	while (*b)
	{
		max = find_max(*b);
		before_max = find_before_max(*b);
		size = ft_lstsize(*b);

		//check which number needs fewer instractions to be pushed (max or before max)
		if (is_less_instractions(max, before_max, size))
		{	
			//check if be max needs less instractions.
			//i : number of instructions needed to put the max at the top.
			//j : number of instructions needed to put the before_max at the top.

			to_push(max, b, a);
			// if (max > ft_lstsize(*b) / 2)
			// {
			// 	while (max++ < ft_lstsize(*b))
			// 		reverse_rotate(b, "rrb\n");
			// }
			// else
			// {
			// 	while (max--)
			// 		rotate(b, "rb\n");
			// }
			// push(b, a, "pa\n");
		}
		else
		{
			to_push(before_max, b, a);
			to_push(max, b, a);
			swap(*a, "sa\n");
		}
	}
}

void	sort(t_stack **a, t_stack **b, int size)
{
	// int	i;

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
	{
		if (!sorted(*a))
		{
			ft_chunk(a, b, 5, size);
			puts("pushing back \n");
			push_back(b, a);
		}
	}
}
