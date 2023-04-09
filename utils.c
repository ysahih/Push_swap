#include "push_swap.h"

void ft_free(char **s)
{
	int	i;

	i = -1;
	while (s[++i])
		free (s[i]);
	free (s);
}
// t_stack	*ft_lstlast(t_stack *lst)
// {
// 	if (!lst)
// 		return (0);
// 	while (lst->next)
// 		lst = lst->next;
// 	return (lst);
// }

// t_stack	*ft_lstnew(int num)
// {
// 	t_stack	*new;

// 	new = malloc(sizeof(t_stack));
// 	if (!new)
// 		return (0);
// 	new->num = num;
// 	new->next = NULL;
// 	return (new);
// }

// void	ft_lstadd_front(t_stack **lst, int	num)
// {
// 	t_stack	*new;

// 	if (!lst)
// 		return ;
// 	new = ft_lstnew(num);
// 	new->next = *lst;
// 	*lst = new;
// }

// void	ft_lstadd_back(t_stack **lst, t_stack *new)
// {
// 	t_stack	*last_node;

// 	if (!lst)
// 		return ;
// 	if (*lst == NULL)
// 	{
// 		*lst = new;
// 		return ;
// 	}
// 	last_node = ft_lstlast(*lst);
// 	last_node->next = new;
// }

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
	s = malloc((sizeof(char *)) * (count + 1));
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