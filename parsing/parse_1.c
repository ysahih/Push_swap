/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahih <ysahih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:08:50 by ysahih            #+#    #+#             */
/*   Updated: 2023/04/27 17:43:19 by ysahih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	calculate_size(int ac, char **av)
{
	int	size;
	int	i;

	size = 0;
	i = 1;
	while (i < ac)
	{
		size += ft_strlen(av[i++]);
		size++;
	}
	return (size);
}

char	*join_args(int ac, char **av)
{
	int		i;
	int		k;
	int		j;
	char	*str;

	str = malloc(calculate_size(ac, av));
	if (!str)
		return (0);
	i = 1;
	k = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
			str[k++] = av[i][j++];
		if (av[i + 1])
			str[k++] = ' ';
		i++;
	}
	str[k] = 0x0;
	return (str);
}

int	is_digit(char *s)
{
	int	i;
	int	flag;

	flag = 1;
	i = 0;
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9') && s[i] != ' '
			&& s[i] != '-' && s[i] != '+')
				flag = 0;
		i++;
	}
	if (!flag)
		return (ft_error(), 0);
	return (1);
}

int	is_formed(char **l)
{
	int	i;
	int	j;

	i = 0;
	while (l[i])
	{
		j = 0;
		while (l[i][j])
		{
			if (l[i][j] == '-' || l[i][j] == '+')
				if (j != 0)
					return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	extra_check(char **l)
{
	int	i;

	i = 0;
	while (l[i])
	{
		if (ft_strlen(l[i]) == 1 && (l[i][0] == '-' || l[i][0] == '+'))
			return (0);
		i++;
	}
	return (1);
}
