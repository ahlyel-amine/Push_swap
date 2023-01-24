/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 21:39:13 by aahlyel           #+#    #+#             */
/*   Updated: 2023/01/24 03:10:19 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"



int main(int ac, char **av)
{
	t_list	*garbg;
	t_list	*instractions;
	t_stack	*stack;
	int		*table;

	garbg = NULL;
	instractions = NULL;
	stack = ft_malloc(malloc(sizeof(t_stack)), &garbg);
	stack->stack = NULL;
	ft_parse(&garbg, stack, ++av, ac - 1);
	if (!stack->stack)
		ft_exit(NULL, &garbg, 1, 0);
	read_args(&garbg, &instractions);
	ft_sort_args(&garbg, stack, &table);
	if (stack->stack->next == stack->stack)
			ft_exit(NULL, &garbg, 1, 1);
	push_swap(&garbg, instractions, stack);
	compare_stacks(&garbg, stack, table, 1);
	return 0;
}
