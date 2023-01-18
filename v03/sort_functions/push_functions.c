/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:47:26 by aahlyel           #+#    #+#             */
/*   Updated: 2023/01/18 21:05:59 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	push_a(t_list **garbg, t_lst **stack_a, t_lst **stack_b)
{
	new_node(garbg, stack_a, (*stack_b)->content, 1);
	// if (*stack_b == (*stack_b)->next)
	// {
	// 	del_node(stack_b);
	// 	*stack_b = NULL;
	// }
	// else
		del_node(stack_b);
	write(1, "pa\n", 3);
}

void	push_b(t_list **garbg, t_lst **stack_b, t_lst **stack_a)
{
	new_node(garbg, stack_b, (*stack_a)->content, 1);
	// if (*stack_a == (*stack_a)->next)
	// {
	// 	del_node(stack_a);
	// 	*stack_a = NULL;
	// }
	// else
		del_node(stack_a);
	write(1, "pb\n", 3);
}
