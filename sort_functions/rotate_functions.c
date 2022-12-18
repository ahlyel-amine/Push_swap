/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:47:23 by aahlyel           #+#    #+#             */
/*   Updated: 2022/12/18 14:37:40 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_a(t_lst **stack, int ind)
{
	*stack = (*stack)->next;
	if (ind)
	printf("ra\n");
		// write(1, "ra\n", 3);
}

void	rotate_b(t_lst **stack, int ind)
{
	*stack = (*stack)->next;
	if (ind)
	printf("rb\n");
		// write(1, "rb\n", 3);
}

void	rr(t_lst **stack_a, t_lst **stack_b)
{
	rotate_a(stack_a, 0);
	rotate_b(stack_b, 0);
	printf("rr\n");
	// write(1, "rr\n", 3);
}
