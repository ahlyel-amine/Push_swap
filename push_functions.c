/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:47:26 by aahlyel           #+#    #+#             */
/*   Updated: 2022/11/28 16:47:27 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_lst **stack_a, t_lst **stack_b)
{
	t_lst	*new;

	new_node(stack_a, (*stack_b)->content);
	(*stack_a) = (*stack_a)->prev;
	del_node(stack_b);
}

void	push_b(t_lst **stack_b, t_lst **stack_a)
{
	t_lst	*new;

	new_node(stack_b, (*stack_a)->content);
	(*stack_b) = (*stack_b)->prev;
	del_node(stack_a);
}
