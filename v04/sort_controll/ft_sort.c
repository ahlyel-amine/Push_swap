/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 20:57:59 by aahlyel           #+#    #+#             */
/*   Updated: 2023/01/21 20:36:06 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	ft_sort(t_list **garbg, t_stack *a)
{
	t_stack	*b;

	b = NULL;
	sort_check(garbg, a);
	if (a->lenght > 5)
		big_sort(garbg, a);
	else
	{
		b = ft_malloc(malloc(sizeof(t_stack)), garbg);
		b->stack = NULL;
		low_sort(garbg, a, b);
	}
}

void	sort_check(t_list **garbg, t_stack *a)
{
	t_lst	*tmp;
	int		i;

	i = 0;
	while (i++ < a->lenght - 1)
	{
		tmp = a->stack->next;
		if (a->stack->content > tmp->content)
			return ;
		a->stack = a->stack->next;
	}
	ft_exit(NULL, garbg, 1);
}
