/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:53:03 by aahlyel           #+#    #+#             */
/*   Updated: 2023/01/24 00:36:27 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker.h"

void	reverse_a(t_stack *a)
{
	a->stack = a->stack->prev;
}

void	reverse_b(t_stack *b)
{
	b->stack = b->stack->prev;
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse_a(a);
	reverse_b(b);
}
