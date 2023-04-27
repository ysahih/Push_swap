#include "../push_swap.h"

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