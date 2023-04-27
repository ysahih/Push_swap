/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahih <ysahih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:45:08 by ysahih            #+#    #+#             */
/*   Updated: 2023/04/27 17:25:45 by ysahih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_min(t_stack *a)
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
	return (i);
}

int	find_max(t_stack *a)
{
	int		max;
	int		i;
	t_stack	*lst;

	i = 0;
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

void	init(t_stack *b, int *max, int *before_max)
{
	t_stack	*lst;

	lst = b;
	*max = lst->num;
	while (lst)
	{
		if (*max < lst->num)
			*max = lst->num;
		lst = lst->next;
	}
	*before_max = -2147483648;
}

int	find_before_max(t_stack *b)
{
	t_stack	*lst;
	int		max;
	int		before_max;
	int		i;

	lst = b;
	init(b, &max, &before_max);
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
