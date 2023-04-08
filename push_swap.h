#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
}	t_stack;





//parssing utils
char	*ft_strncpy(char *s, char *s2, int len);
char	**ft_split(char *str);

//lst_utils
void	ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_lstlast(t_stack *lst);
int		ft_lstsize(t_stack *lst);
void	ft_lstadd_front(t_stack **lst, int	num);

//moves
void	swap(t_stack **stack);
void	rotate(t_stack **stack);
void	push(t_stack **stack_a, t_stack **stack_b);
void	reverse_rotate(t_stack **stack);

# endif