/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:47:26 by aahlyel           #+#    #+#             */
/*   Updated: 2022/12/16 19:50:20 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_a(t_lst **stack_a, t_lst **stack_b)
{
	// if (*stack_a)
	// 	add_node(stack_a, (*stack_b)->content);
	// else
	new_node(stack_a, (*stack_b)->content);
	if (*stack_b == (*stack_b)->next)
	{
		del_node(stack_b);
		*stack_b = NULL;
	}
	else
		del_node(stack_b);
	write(1, "pa\n", 3);
}

void	push_b(t_lst **stack_b, t_lst **stack_a)
{
	// if (*stack_b)
	// 	add_node(stack_b, (*stack_a)->content);
	// else
	new_node(stack_b, (*stack_a)->content);
	if (*stack_a == (*stack_a)->next)
	{
		del_node(stack_a);
		*stack_a = NULL;
	}
	else
		del_node(stack_a);
	write(1, "pb\n", 3);
}
