/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahih <ysahih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:02:55 by ysahih            #+#    #+#             */
/*   Updated: 2023/04/27 17:32:03 by ysahih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	init_var1(int *i, int size, int max, int before_max)
{
	int	j;

	*i = size - max;
	j = before_max;
	return (j);
}

int	init_var(int *i, int size, int max, int before_max)
{
	int	j;

	*i = max;
	j = size - before_max;
	return (j);
}

//i : number of instructions needed to put the max at the top.
//j : number of instructions needed to put the before_max at the top.
int	is_less_instractions(int max, int before_max, int size)
{
	int	mid;
	int	i;
	int	j;

	mid = size / 2;
	if (max <= mid)
	{
		if (before_max > mid)
			j = init_var(&i, size, max, before_max);
		else
			return (max < before_max);
	}
	else
	{
		if (before_max <= mid)
			j = init_var1(&i, size, max, before_max);
		else
			return (max > before_max);
	}
	return (i <= j);
}

void	to_push(int nbr, t_stack **b, t_stack **a)
{
	if (nbr > ft_lstsize(*b) / 2)
		while (nbr++ < ft_lstsize(*b))
			reverse_rotate(b, "rrb\n", true);
	else
		while (nbr--)
			rotate(b, "rb\n", true);
	push(b, a, "pa\n", true);
}

//after finding the position of (max and before max) ->
//check which one needs fewer instractions to be pushed
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
