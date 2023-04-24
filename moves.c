#include "push_swap.h"


//Take the first element at the top of stack a and put it at the top of stack b.
void	push(t_stack **stack_a, t_stack **stack_b, char *s)
{
	t_stack	*tmp;

	if (!stack_a || !*stack_a)
	  	return ;
	ft_lstadd_front(stack_b, (*stack_a)->num, (*stack_a)->index);
	tmp = (*stack_a)->next;
	*stack_a = tmp;
	write(1, s, 3);
}

//Swap the first 2 elements at the top of the stack.
void	swap(t_stack *stack, char *s)
{
	int tmp;
	int i;
	// t_stack *stack;

	// stack = *stack;
	if(!stack)
		return ;
	tmp = stack->num;
	i = stack->index;
	stack->num = stack->next->num;
	stack->index = stack->next->index;
	stack->next->num = tmp;
	stack->next->index = i;
 
	write(1, s, 3);
}

//Shift up all elements of the stack by 1, The first element becomes the last one.
void	rotate(t_stack **stack, char *s)
{
	int		tmp;
	int		i;
	t_stack *list;

	list = *stack;
	if (!list)
		return ;
	tmp = list->num;
	i = list->index;
	while (list && list->next)
	{
		list->num = list->next->num;
		list->index = list->next->index;
		list = list->next;
	}
	list->num = tmp;
	list->index = i;
	write(1, s, 3);
}

//Shift down all elements of the stack by 1, the last element 
void reverse_rotate(t_stack **stack, char *s)
{
	t_stack *list;

	list = *stack;
	if (!list)
	  	return ;
	while (list && list ->next && list ->next->next)
		list = list ->next;
	ft_lstadd_front(stack , list->next->num, list->next->index);
	free(list->next);
	list->next = NULL;
	write(1, s, 4);
}