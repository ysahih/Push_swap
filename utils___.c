#include "push_swap.h"

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
	i = 1;
	k = 0;
	while (i < ac)
	{
		j = 0;
		while(av[i][j])
			str[k++] = av[i][j++];
		if (av[i + 1])
			str[k++] = ' ';
		i++;
	}
	str[k] = 0x0;
	return (str);
}

void	Error()
{
	write(2, "Error\n", 6);
	exit (0);
}


int	Digit(char *s)
{
	int	i;
	int flag = 1;

	i = 0;
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9') && s[i] != ' ' && s[i] != '-' && s[i] != '+')
			flag = 0;
		i++;
	}
	if (!flag)
		return (Error(), 0);
	return (1);
}

int Formed(char **l)
{
	int i = 0;
	int	j;
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
	int i = 0;
	while (l[i])
	{
		if (ft_strlen(l[i]) == 1 && (l[i][0] == '-' || l[i][0] == '+'))
			return (0);
		i++;
	}
	return (1);
}

int	is_duplicate(char **l)
{
	int i;
	for (i = 0; l[i]; i++);
	int k = i;
	int j = 0;
	while (j + 1 < k)
	{
		
		int z = 0;
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
			return(Error(), 0);
	return (1);
}
char **get_info(int ac, char **av)
{
	char *str;
	char **l;
	
	no_empty_args(ac, av);
	str = join_args(ac, av);
	Digit(str);
	l = ft_split(str);
	free(str);
	return (l);
}

int	ft_atoi(char *str)
{
	int			i;
	int			sign;
	long long	res;

	res = 0;
	i = 0;
	sign = 1;
	while (str[i] && (str[i] == 32))
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		res = res * 10 + str[i++] - '0';
	res *= sign;
	if (res < INT32_MIN || res > INT32_MAX)
		return (Error(), 0);
	return (res);
}

int	valid_ellements(int ac, char **l)
{
	if (ac > 1)
	{
		int	i = 0;
		ac --;
		while (i < ac)
		{
			int	j = i;
			while (++j < ac)
				if (ft_atoi(l[i]) == ft_atoi(l[j]))
					return (Error(), 0);
			i++;
		}
		if (!Formed(l) || !is_duplicate(l) || !extra_check(l))
			return (Error(), 0);
		return (1);
	}
	return (Error(), 0);
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

t_stack	*str_to_lst(char **l)
{
	t_stack *lst;
	int		i;

	lst = NULL;
	i = 0;
	while(l[i])
	{
		t_stack	*new = malloc(sizeof(t_stack));
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
	t_stack *a;

	l = get_info(ac, av);
	valid_ellements(ac, l);
	a = str_to_lst(l);
	if (!a)
		return (0);
	if (size)
		*size = ft_lstsize(a);
	return (a);
}
