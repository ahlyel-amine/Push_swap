/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:47:23 by aahlyel           #+#    #+#             */
/*   Updated: 2023/01/24 00:36:40 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker.h"

void	rotate_a(t_stack *a)
{
	a->stack = a->stack->next;
}

void	rotate_b(t_stack *b)
{
	b->stack = b->stack->next;
}

void	rr(t_stack *a, t_stack *b)
{
	rotate_a(a);
	rotate_b(b);
}
