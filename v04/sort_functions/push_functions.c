/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:47:26 by aahlyel           #+#    #+#             */
/*   Updated: 2023/01/20 17:58:16 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	push_a(t_list **garbg, t_stack *a, t_stack *b)
{
	new_node(garbg, a, b->stack->content, 1);
	// if (*stack_b == (*stack_b)->next)
	// {
	// 	del_node(stack_b);
	// 	*stack_b = NULL;
	// }
	// else
		del_node(b);
	write(1, "pa\n", 3);
}

void	push_b(t_list **garbg, t_stack *b, t_stack *a)
{
	new_node(garbg, b, a->stack->content, 1);
	// if (*stack_a == (*stack_a)->next)
	// {
	// 	del_node(stack_a);
	// 	*stack_a = NULL;
	// }
	// else
		del_node(a);
	write(1, "pb\n", 3);
}
