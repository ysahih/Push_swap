/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahih <ysahih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:24:05 by ysahih            #+#    #+#             */
/*   Updated: 2023/04/27 17:24:06 by ysahih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_elmnt(t_stack **a, t_stack **b, int start, int end)
{
	int	mid;

	mid = ((end - start + 1) / 2) + start;
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
	mid = ((end - start + 1) / 2) + start;
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
