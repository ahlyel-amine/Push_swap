/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:53:03 by aahlyel           #+#    #+#             */
/*   Updated: 2022/12/18 14:38:01 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_a(t_lst **stack, int ind)
{
	*stack = (*stack)->prev;
	if (ind)
	printf("rra\n");
		// write(1, "rra\n", 4);
}

void	reverse_b(t_lst **stack, int ind)
{
	*stack = (*stack)->prev;
	if (ind)
	printf("rrb\n");
		// write(1, "rrb\n", 4);
}

void	rrr(t_lst **stack_a, t_lst **stack_b)
{
	reverse_a(stack_a, 0);
	reverse_b(stack_b, 0);
	printf("rrr\n");
	// write(1, "rrr\n", 4);
}
