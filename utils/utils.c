#include "../push_swap.h"

// void ft_free(char **s)
// {
// 	int	i;

// 	i = -1;
// 	while (s[++i])
// 		free (s[i]);
// 	free (s);
// }

// int	ft_strlen(char *s)
// {
// 	int	i;

// 	i = 0;
// 	while (i[s])
// 		i++;
// 	return (i);
// }

// int	ft_strcmp(char *s1,char *s2)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s1[i] == s2[i] && (s1[i] != '\0' || s2[i] != '\0'))
// 		i++;
// 	return (s1[i] - s2[i]);
// }

int	sorted(t_stack *a)
{
	t_stack	*tmp;

	if (!a)
		return (0);
	tmp = a;
	while (tmp->next)
	{
		if (tmp->num > tmp->next->num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

char	*ft_strncpy(char *s, char *s2, int len)
{
	int	i;

	i = 0;
	while (i < len && s2[i])
	{
		s[i] = s2[i];
		i++;
	}
	s[len] = '\0';
	return s;
}

int	count_len(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i])
			count++;
		while ( str[i] && str[i] != ' ')
			i++;
	}
	return (++count);
}

char	**ft_split(char *str)
{
	char	**s;
	int		i;
	int		j;
	int		a;

	s = malloc((sizeof(char *)) * (count_len(str)));
	if (!s)
		return (0);
	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		a = i;
		while ( str[i] && str[i] != ' ')
			i++;
		if (i > a)
			s[j++] = ft_strncpy(malloc (i - a + 1), str + a, i - a);
	}
	s[j] = NULL;
	return (s);
}

void	set_index(t_stack **lst)
{
	t_stack	*tmp;
	t_stack	*tmp2;
	int		i;
	int		a;

	i = 0;
	tmp = *lst;
	while (tmp)
	{
		a = i;
		tmp2 = *lst;
		while (tmp2 && a--)
		{
			if (tmp2->num > tmp->num)
				tmp2->index++;
			else
				tmp->index++;
			tmp2 = tmp2->next;
		}
		i++;
		tmp = tmp->next;
	}
}