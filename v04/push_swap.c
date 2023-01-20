/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 23:41:55 by aahlyel           #+#    #+#             */
/*   Updated: 2023/01/20 21:02:14 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

int main(int ac, char **av)
{
	t_list		*garbg;
	t_stack		*stack;

	garbg = NULL;
	stack = ft_malloc(malloc(sizeof(t_stack)), &garbg);
	stack->stack = NULL;

	// for (size_t i=0; i++ < 10;)
	// {
	// 	new_node(&garbg, stack, i);
	// }
	// printf("%d\n",stack->lenght);
	// del_node(stack);
	// printf("%d\n",stack->lenght);
	// print_stack(stack, NULL);
	// return (0);
	ft_parse(&garbg, stack, ++av, ac - 1);
	ft_sort(&garbg, stack);
	return (0);
}
