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
		rotate(a, "ra\n", true);
	if (i == 1)
		reverse_rotate(a, "rra\n", true);
	if ((*a)->num > (*a)->next->num)
		swap(*a, "sa\n", true);
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
				rotate(a, "ra\n", true);
				i--;
			}
		}
		else
		{
			while (i < ft_lstsize(*a))
			{
				reverse_rotate(a, "rra\n", true);
				i++;
			}
		}
		push(a, b, "pb\n", true);
		sort_five(a, b);
	}
	sort_three(a);
	while (*b)
		push(b, a, "pa\n", true);
}

void	push_elmnt(t_stack **a, t_stack **b, int start, int end)
{
	int	mid;

	mid = ((end - start + 1) / 2 ) + start;
	if ((*a)->index >= start || (*a)->index <= end)
			{
				if (!*b)
					push(a, b, "pb\n", true);
				else
				{
					if ((*a)->index < mid)
						push(a, b, "pb\n", true);
					else
					{
						push(a, b, "pb\n", true);
						rotate(b, "rb\n", true);
					}
				}
			}
}

void	sort_chunk(t_stack **a, t_stack **b, int start, int end)
{
	int		mid;
	int		count;

	count = start;
	mid = ((end - start + 1) / 2 ) + start;
	while (count <= end)
	{
		if (*a)
		{
			while ((*a)->index < start || (*a)->index > end)
				rotate(a, "ra\n", true);
			push_elmnt(a, b, start, end);
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
	if (size < 10)
		x = 2;
	while (i <= x)
	{
		if (i == x)
		{
			end = size - 1;
			sort_chunk(a, b, start, end);
		}
		else
		{
			end = size / x * i - 1;
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
	t_stack	*lst;
	int	max;
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
		
		//check which number needs fewer instractions to be pushed (max or before max)
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

void	sort(t_stack **a, t_stack **b, int size)
{
	if (size <= 5)
	{
		if (size <= 3)
		{
			if (size == 1)
				return ;
			else if (size == 2)
			{
				if ((*a)->num > (*a)->next->num)
					swap(*a, "sa\n", true);
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
			if (size <= 100)
				ft_chunk(a, b, 4, size);
			else
				ft_chunk(a, b, 9, size);
			push_back(b, a);
		}
	}
}
