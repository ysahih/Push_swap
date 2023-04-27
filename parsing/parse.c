/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahih <ysahih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:35:42 by ysahih            #+#    #+#             */
/*   Updated: 2023/04/27 17:43:28 by ysahih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	valid_ellements(int ac, char **l)
{
	int	i;
	int	j;

	if (ac > 1)
	{
		i = 0;
		ac --;
		while (i < ac)
		{
			j = i;
			while (++j < ac)
				if (ft_atoi(l[i]) == ft_atoi(l[j]))
					return (ft_error(), 0);
			i++;
		}
		if (!is_formed(l) || !is_duplicate(l) || !extra_check(l))
			return (ft_error(), 0);
		return (1);
	}
	return (ft_error(), 0);
}

t_stack	*str_to_lst(char **l)
{
	t_stack	*lst;
	int		i;
	t_stack	*new;

	lst = NULL;
	i = 0;
	while (l[i])
	{
		new = malloc(sizeof(t_stack));
		if (!new)
			return (0);
		new->next = NULL;
		new->index = 0;
		new->num = ft_atoi(l[i]);
		ft_lstadd_back(&lst, new);
		i++;
	}
	set_index(&lst);
	ft_free (l);
	return (lst);
}

t_stack	*store_up(int ac, int *size, char **av)
{
	char	**l;
	t_stack	*a;

	l = get_info(ac, av);
	valid_ellements(ac, l);
	a = str_to_lst(l);
	if (!a)
		return (0);
	if (size)
		*size = ft_lstsize(a);
	return (a);
}
