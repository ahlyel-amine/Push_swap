/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:53:03 by aahlyel           #+#    #+#             */
/*   Updated: 2022/12/16 21:32:41 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_a(t_lst **stack)
{
	*stack = (*stack)->prev;
	write(1, "rra\n", 4);
}

void	reverse_b(t_lst **stack)
{
	*stack = (*stack)->prev;
	write(1, "rrb\n", 4);
}

void	rrr(t_lst **stack_a, t_lst **stack_b)
{
	reverse_a(stack_a);
	reverse_b(stack_b);
	write(1, "rrr\n", 4);
}
