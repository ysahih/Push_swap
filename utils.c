#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "push_swap.h"

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
	// s[count] = NULL;
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