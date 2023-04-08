#include "push_swap.h"


t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
// int	ft_lstsize(t_stack *lst)
// {
// 	int	i;

// 	i = 0;
// 	if (!lst)
// 		return (0);
// 	while (lst)
// 	{
// 		lst = lst->next;
// 		i++;
// 		printf("i = %d", i);
// 	}
// 	return (i);
// }

t_stack	*ft_lstnew(int num)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (0);
	new->num = num;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_front(t_stack **lst, int	num)
{
	t_stack	*new;

	if (!lst)
		return ;
	new = ft_lstnew(num);
	new->next = *lst;
	*lst = new;
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last_node;

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