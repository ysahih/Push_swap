/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahih <ysahih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:40:02 by ysahih            #+#    #+#             */
/*   Updated: 2023/04/27 19:40:03 by ysahih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_stack
{
	int				index;
	int				num;
	struct s_stack	*next;
}	t_stack;

//parssing utils
t_stack	*store_up(int ac, int *size, char **av);
int		extra_check(char **l);
int		is_formed(char **l);
int		is_digit(char *s);
char	*join_args(int ac, char **av);
int		calculate_size(int ac, char **av);

char	**get_info(int ac, char **av);
int		no_empty_args(int ac, char **av);
int		is_duplicate(char **l);
int		valid_ellements(int ac, char **l);
t_stack	*store_up(int ac, int *size, char **av);
t_stack	*str_to_lst(char **l);

//lst_utils
void	ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_lstlast(t_stack *lst);
int		ft_lstsize(t_stack *lst);
void	ft_lstadd_front(t_stack **lst, int num, int i);
t_stack	*ft_lstnew(int num, int i);

//moves
void	swap(t_stack *stack, char *s, bool flag);
void	rotate(t_stack **stack, char *s, bool flag);
void	push(t_stack **stack_a, t_stack **stack_b, char *s, bool flag);
void	reverse_rotate(t_stack **stack, char *s, bool flag);

//sorting
void	sort(t_stack **a, t_stack **b, int size);
void	sort_three(t_stack **a);
void	sort_five(t_stack **a, t_stack **b);
void	sort_chunk(t_stack **a, t_stack **b, int start, int end);
void	ft_chunk(t_stack **a, t_stack **b, int x, int size);
void	push_elmnt(t_stack **a, t_stack **b, int start, int end);
int		sorted(t_stack *a);

int		is_less_instractions(int max, int before_max, int size);
void	to_push(int nbr, t_stack **b, t_stack **a);
void	push_back(t_stack **b, t_stack **a);

//utils
char	*ft_strncpy(char *s, char *s2, int len);
char	**ft_split(char *str);
void	ft_free(char **s);
int		ft_strlen(char *s);
int		count_len(char *str);
int		ft_strcmp(char *s1, char *s2);
void	ft_error(void);
int		ft_atoi(char *str);

void	set_index(t_stack **lst);
int		find_before_max(t_stack *b);
int		find_max(t_stack *a);
int		find_min(t_stack *a);

//bonus utils
char	*gnl(int fd);

#endif
