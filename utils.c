#include "push_swap.h"


t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_node;

	if (!lst)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last_node = ft_lstlast(*lst);
	last_node->next = new;
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
	// for (int i = 0; str[i] ; i++)
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
	s = malloc((sizeof(char *)) * (count + 1));
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
		if (i > a)
		{
			s[z] = malloc (i - a + 1);
			s[z] = ft_strncpy(s[z], str + a, i - a);
            z++;
		}
	}
	s[z] = NULL;
	return (s);
}