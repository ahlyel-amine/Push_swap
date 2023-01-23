/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 20:57:59 by aahlyel           #+#    #+#             */
/*   Updated: 2023/01/23 22:26:40 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

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
	t_lst	*tmp1;
	int		i;

	i = 0;
	tmp1 = a->stack;
	while (i++ < a->lenght - 1)
	{
		tmp = tmp1->next;
		if (tmp1->content > tmp->content)
			return ;
		tmp1 = tmp1->next;
	}
	ft_exit(NULL, garbg, 1);
}
