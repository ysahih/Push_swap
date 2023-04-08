#include "push_swap.h"

void	swap(t_list **lst, char c)
{
	int tmp;

	t_list *list = *lst;
	tmp = list->num;
	list->num = list->next->num;
	list->next->num	= tmp;
	
	*lst = list;

}