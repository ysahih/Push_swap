/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahih <ysahih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:46:52 by ysahih            #+#    #+#             */
/*   Updated: 2023/04/27 18:26:39 by ysahih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		size;
	
	if (ac < 2)
		exit (0);
	b = NULL;
	size = 1;
	a = store_up(ac, &size, av);
	if (!sorted(a))
		sort(&a,&b, size);
	// while (a)
	// {
	// 	printf("%d\n", a->num);
	// 	a = a->next;/* code */
	// }
	while(a)
	{
		b = a->next;
		free(a);
		a = b;
	}
	// system("leaks push_swap");
	// exit(1);
	// free(a);
	return (0);
}