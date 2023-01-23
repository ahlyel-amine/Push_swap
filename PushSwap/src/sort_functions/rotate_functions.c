/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:47:23 by aahlyel           #+#    #+#             */
/*   Updated: 2023/01/23 17:38:26 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

void	rotate_a(t_stack *a, int ind)
{
	a->stack = a->stack->next;
	if (ind)
		write(1, "ra\n", 3);
}

void	rotate_b(t_stack *b, int ind)
{
	b->stack = b->stack->next;
	if (ind)
		write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	rotate_a(a, 0);
	rotate_b(b, 0);
	write(1, "rr\n", 3);
}
