/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:53:03 by aahlyel           #+#    #+#             */
/*   Updated: 2023/01/20 18:00:34 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	reverse_a(t_stack *a, int ind)
{
	a->stack = a->stack->prev;
	if (ind)
		write(1, "rra\n", 4);
}

void	reverse_b(t_stack *b, int ind)
{
	b->stack = b->stack->prev;
	if (ind)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse_a(a, 0);
	reverse_b(b, 0);
	write(1, "rrr\n", 4);
}
