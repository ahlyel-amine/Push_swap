/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:55:33 by aahlyel           #+#    #+#             */
/*   Updated: 2023/01/23 20:19:12 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker.h"

void	swap_a(t_stack *a, int ind)
{
	long long	tmp;

	tmp = a->stack->content;
	a->stack->content = (a->stack->next)->content;
	(a->stack->next)->content = tmp;
	if (ind)
		write(1, "sa\n", 3);
}

void	swap_b(t_stack *b, int ind)
{
	long long	tmp;

	tmp = b->stack->content;
	b->stack->content = (b->stack->next)->content;
	(b->stack->next)->content = tmp;
	if (ind)
		write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	swap_a(a, 0);
	swap_b(b, 0);
	write(1, "ss\n", 3);
}
