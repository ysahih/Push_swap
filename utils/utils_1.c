#include "../push_swap.h"

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

int	ft_strcmp(char *s1,char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && (s1[i] != '\0' || s2[i] != '\0'))
		i++;
	return (s1[i] - s2[i]);
}

void	Error()
{
	write(2, "Error\n", 6);
	exit (0);
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