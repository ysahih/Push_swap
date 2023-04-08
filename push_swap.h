#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
// #include <string.h>
// #include <stdio.h>

typedef struct s_list
{
	int				num;
	struct s_list	*next;
}	t_list;





//parssing utils
char	*ft_strncpy(char *s, char *s2, int len);
char	**ft_split(char *str);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);

# endif