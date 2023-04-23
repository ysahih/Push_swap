#include "push_swap.h"

char	*join_args(int ac, char **av)
{
	int		i;
	int		k;
	int		j;
	char	*str;

	i = 1;
	k = 0;

	while (i < ac)
	{
		k += ft_strlen(av[i++]);
		k++;
	}
	str = malloc(k + 1);
	i = 1;
	k = 0;
	while (i < ac)
	{
		j = 0;
		while(av[i][j])
		{
			// if (av[i][j] == '+')
			// 	j++;
			str[k++] = av[i][j++];
		
		}
		if (av[i + 1])
			str[k++] = ' ';
		i++;
	}
	str[k] = 0x0;
	return (str);
}
void	Error()
{
	printf("Error!\n");
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
	int j;
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
	while (i < ac)
		if (!ft_strlen(av[i++]))
			return(Error(), 0);
	return (1);
}
char **get_info(int ac, char **av)
{
	int	i;
	char *str;
	char **l;
	
	no_empty_args(ac, av);

	str = join_args(ac, av);
	// for(int i = 0; str[i]; i++)
	// printf("%c", str[i]);
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
	long long	nbr;

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
	{
		res = res * 10;
		res = res + str[i] - '0';
		i++;
	}
	nbr = res * sign;
	if (nbr < INT32_MIN || nbr > INT32_MAX)
		return (Error(), 0);
	return (nbr);
}

int	valid(int ac, char **av, char **l)
{
	if (ac > 1)
	{
		// l = get_info(ac, av);
		// for( int i = 0; l[i]; i++)
		int	i = 0;
		ac --;
		while (i < ac)
		{
			int	j = i;
			while (++j < ac)
			{
				// printf("|%d||%d|\n", ft_atoi(l[i]), ft_atoi(l[j]));
				if (ft_atoi(l[i]) == ft_atoi(l[j]))
					return (Error(), 0);
			}
			i++;
		}
		if (!Formed(l) || !is_duplicate(l) || !extra_check(l))
			return (Error(), 0);
		return (1);
	}
	return (Error(), 0);
}

void	init_index(t_stack **lst)
{
	t_stack	*tmp;
	t_stack	*tmp2;
	int		i;
	int		a;

	if (!*lst || !lst)
		return ;
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
	int	i;
	int	j;
	t_stack *lst = NULL;

	i = 0;
	while(l[i])
	{
		t_stack	*new = malloc(sizeof(t_stack));
		new->next = NULL;
		new->num = ft_atoi(l[i]);
		new->index = 0;
		ft_lstadd_back(&lst, new);
		i++;
	}
	init_index(&lst);
	ft_free (l);
	return (lst);
}

int	main(int ac, char **av)
{
	int		size;
	char	**l;
	t_stack *a;
	t_stack	*b = NULL;

	l = get_info(ac, av);
	valid(ac, av, l);
	a = str_to_lst(l);

	size = ft_lstsize(a);
	// sort(&a,&b, size);
	
	while(a)
	{
		printf("%d\n", a->index);
		a = a->next;

	}
}