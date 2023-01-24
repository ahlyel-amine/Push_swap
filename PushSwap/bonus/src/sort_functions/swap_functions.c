/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:55:33 by aahlyel           #+#    #+#             */
/*   Updated: 2023/01/24 00:36:35 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker.h"

void	swap_a(t_stack *a)
{
	long long	tmp;

	tmp = a->stack->content;
	a->stack->content = (a->stack->next)->content;
	(a->stack->next)->content = tmp;
}

void	swap_b(t_stack *b)
{
	long long	tmp;

	tmp = b->stack->content;
	b->stack->content = (b->stack->next)->content;
	(b->stack->next)->content = tmp;
}

void	ss(t_stack *a, t_stack *b)
{
	swap_a(a);
	swap_b(b);
}
