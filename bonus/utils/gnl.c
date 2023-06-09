/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahih <ysahih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:35:55 by ysahih            #+#    #+#             */
/*   Updated: 2023/04/27 17:19:20 by ysahih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

char	*get_ret(char *s)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = -1;
	while (s[i])
		i++;
	ret = malloc(i + 1);
	if (!ret)
		return (0);
	while (s[++j])
		ret[j] = s[j];
	ret[j] = 0;
	free(s);
	return (ret);
}

char	*new_str(char *s, char c)
{
	int		i;
	char	*ret;
	int		j;

	i = 0;
	j = -1;
	while (s[i])
		i++;
	if (c == '\n')
		return (get_ret(s));
	else
	{
		ret = malloc (i + 2);
		if (!ret)
			return (0);
		while (s[++j])
			ret[j] = s[j];
		ret[i++] = c;
		ret[i] = 0;
	}
	free (s);
	return (ret);
}

char	*join(char *s, char c)
{
	if (!s)
	{
		s = malloc(2);
		if (!s)
			return (0);
		if (c == '\n')
			exit (0);
		s[0] = c;
		s[1] = 0x0;
		return (s);
	}
	return (new_str(s, c));
}

char	init_vars(char **buff, char r)
{
	*buff = join(*buff, r);
	return (r);
}

char	*gnl(int fd)
{
	char		r;
	int			i;
	char		*buff;
	static char	previous;

	buff = 0;
	while (1)
	{
		i = read(fd, &r, 1);
		if (i == -1)
			return (0);
		else if (i == 0)
			break ;
		previous = init_vars (&buff, r);
		if (r == '\n')
			break ;
	}
	if (!buff || *buff == '\0')
		return (0);
	return (buff);
}
