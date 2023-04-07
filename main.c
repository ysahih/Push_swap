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



char* ft_strncpy(char *s, char *s2, int len)
{
	int i = 0;
	while (i < len && s2[i])
	{
		s[i] = s2[i];
		i++;
	}
	s[len] = '\0';
	return s;
}

char    **ft_split(char *str)
{
	char **s;
	int i = 0;
	int count = 0;
	int a = 0;
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i])
			count++;
		while ( str[i] && str[i] != ' ')
			i++;
	}
	s = malloc((sizeof(char *)) * count + 1);
	i = 0;
	int z = 0;
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		a = i;
		while ( str[i] && str[i] != ' ')
			i++;
		if (i > a){
			s[z] = ft_strncpy(malloc(i - a + 1), str + a, i - a);
            z++;
		}
	}
	s[z] = NULL;
	return (s);
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
		k += ft_strlen(av[i++]);
	str = malloc(k + 1);
	i = 1;
	k = 0;
	while (i < ac)
	{
		j = 0;
		while(av[i][j])
			str[k++] = av[i][j++];
		str[k++] = ' ';
		i++;
	}
	str[k] = 0;
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
		return (0);
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
	for( i = 0; l[i]; i++)
		printf("%s\n", l[i]);
	printf("i = %d\n", i);
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

int main(int ac, char **av)
{
	int		i;
	char	*str;
	i = 1;
	while (i < ac)
		if (!ft_strlen(av[i++]))
			return(Error(), 0);
	
	str = join_args(ac, av);

	if (!Digit(str))
		return (Error(), 0);
	  
	// printf("%s\n", str);

	char **l = ft_split(str);

	// for( i = 0; l[i]; i++)
	// 	printf("%s\n", l[i]);
	// printf("i = %d\n", i);
	// int k = i;
	// for (int i = 0; i + 1 < k; i++)
	// {
	// 	for (int j = 0; j + 1 < k; j++)
	// 	{
	// 		if (ft_strcmp(l[i], l[j + 1]) == 0)
	// 			return (Error(), 0);
	// 	}
	// }

	if (!is_duplicate(l))
		return (Error(), 0);

	if (!Formed(l))
		return (Error(), 0);	
	if (!extra_check(l))
		return (Error(), 0);	
}