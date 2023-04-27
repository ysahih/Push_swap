/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahih <ysahih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:04:25 by ysahih            #+#    #+#             */
/*   Updated: 2023/04/27 19:35:04 by ysahih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_stack **a)
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
			while (i-- > 0)
				rotate(a, "ra\n", true);
		else
			while (i++ < ft_lstsize(*a))
				reverse_rotate(a, "rra\n", true);
		push(a, b, "pb\n", true);
		sort_five(a, b);
	}
	sort_three(a);
	while (*b)
		push(b, a, "pa\n", true);
}

void	sort(t_stack **a, t_stack **b, int size)
{
	if (size <= 5)
	{
		if (size <= 3)
		{
			if (size == 2)
			{
				swap(*a, "sa\n", true);
				return ;
			}
			else if (size == 3)
				sort_three(a);
		}
		sort_five(a, b);
	}
	else
	{
		if (size <= 100)
			ft_chunk(a, b, 4, size);
		else
			ft_chunk(a, b, 9, size);
		push_back(b, a);
	}
}
