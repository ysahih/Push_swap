#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "push_swap.h"

int	ft_strcmp(char *s1,char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && (s1[i] != '\0' || s2[i] != '\0'))
		i++;
	return (s1[i] - s2[i]);
}



// char* ft_strncpy(char *s, char *s2, int len)
// {
// 	int i = 0;
// 	while (i < len && s2[i])
// 	{
// 		s[i] = s2[i];
// 		i++;
// 	}
// 	s[len] = '\0';
// 	return s;
// }

// char    **ft_split(char *str)
// {
// 	char **s;
// 	int i = 0;
// 	int count = 0;
// 	int a = 0;
// 	while (str[i])
// 	{
// 		while (str[i] && str[i] == ' ')
// 			i++;
// 		if (str[i])
// 			count++;
// 		while ( str[i] && str[i] != ' ')
// 			i++;
// 	}
// 	s = malloc((sizeof(char *)) * count + 1);
// 	i = 0;
// 	int z = 0;
// 	while (str[i])
// 	{
// 		while (str[i] && str[i] == ' ')
// 			i++;
// 		a = i;
// 		while ( str[i] && str[i] != ' ')
// 			i++;
// 		if (i > a){
// 			s[z] = ft_strncpy(malloc(i - a + 1), str + a, i - a);
//             z++;
// 		}
// 	}
// 	s[z] = NULL;
// 	return (s);
// }

void ft_free(char **s)
{
	int	i;

	i = -1;
	while (s[++i])
		free (s[i]);
	free (s);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (i[s])
		i++;
	return (i);
}

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
			// printf("z = %d\n", z);
			z++;
		}
		// printf("j = %d\n", j);	
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
	while (str[i] && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
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

int	valid(int ac, char **av, char ***l)
{
	if (ac > 1)
	{
		*l = get_info(ac, av);
		// for( int i = 0; l[i]; i++)
		// 	printf("%s\n", l[i]);
		for (int i = 0; l[i]; i++)
			ft_atoi(*l[i]);
		if (!Formed(*l) || !is_duplicate(*l) || !extra_check(*l))
			return (Error(), 0);
		return (1);
	}
	return (Error(), 0);
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
		ft_lstadd_back(&lst, new);
		i++;
	}
	ft_free (l);
	return (lst);
}

int	ft_lstsize(t_stack *lst)
{
	int	i;

	i = 0;
	// if (!lst)
	// 	return (0);
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	find_max(t_stack *a)
{
	int	max;
	int i = 0;
	t_stack *lst;

	lst = a;
	max = lst->num;
	while (lst)
	{
		if (max < lst->num)
		{
			max = lst->num;
			i++;
		}
		lst = lst->next;
	}
	// printf("%d", i);
	return (i);
}
void sort_three(t_stack *a)
{
	int	i;

	i = find_max(a);
	if (i == 0)
		rotate(&a);
	else if (i == 1){
		reverse_rotate(&a);

	// while(a != NULL)
	// {
	// 	printf("%d\n", a->num);
	// 	a = a->next;

	// }	
	}

	if (a->num > a->next->num)
		swap(a);
}

// void	sort(t_stack *a, int size)
// {
// 	int	i;

// 	if (size <= 5)
// 	{
// 		if (size <= 3)
// 		{
// 			if (size == 2)
// 			{
// 				if (a->num > a->next->num)
// 					ft_swap(&a->num, &a->next->num);
// 			}
// 			else if (size == 3)
// 			{

// 			}
// 		}
// 	}

// }

int main(int ac, char **av)
{
	int		size;
	char	**l;
	t_stack *a;
	t_stack	*b = NULL;

	valid(ac, av, &l);
	a = str_to_lst(l);

	size = ft_lstsize(a);
	// find_max(a);
	sort_three(a);



	while(a != NULL)
	{
		printf("%d\n", a->num);
		a = a->next;
		size++;
	}

}