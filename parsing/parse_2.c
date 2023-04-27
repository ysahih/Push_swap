/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahih <ysahih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:08:46 by ysahih            #+#    #+#             */
/*   Updated: 2023/04/27 17:43:19 by ysahih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_duplicate(char **l)
{
	int	i;
	int	k;
	int	j;
	int	z;

	i = 0;
	while (l[i])
		i++;
	k = i;
	j = 0;
	while (j + 1 < k)
	{
		z = 0;
		while (j + z + 1 < k)
		{
			if (ft_strcmp(l[j], l[j + z + 1]) == 0)
				return (0);
			z++;
		}
		j++;
	}
	return (1);
}

int	no_empty_args(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac == 1)
		exit (0);
	while (i < ac)
		if (!ft_strlen(av[i++]))
			return (ft_error(), 0);
	return (1);
}

char	**get_info(int ac, char **av)
{
	char	*str;
	char	**l;

	no_empty_args(ac, av);
	str = join_args(ac, av);
	is_digit(str);
	l = ft_split(str);
	free(str);
	return (l);
}
