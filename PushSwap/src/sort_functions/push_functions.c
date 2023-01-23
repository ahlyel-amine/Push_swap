/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:47:26 by aahlyel           #+#    #+#             */
/*   Updated: 2023/01/23 17:38:19 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

void	push_a(t_list **garbg, t_stack *a, t_stack *b, int ind)
{
	new_node(garbg, a, b->stack->content, 1);
	if (b->stack == b->stack->next)
	{
		del_node(b);
		b->stack = NULL;
	}
	else
		del_node(b);
	if (ind)
		write(1, "pa\n", 3);
}

void	push_b(t_list **garbg, t_stack *b, t_stack *a, int ind)
{
	new_node(garbg, b, a->stack->content, 1);
	if (a->stack == a->stack->next)
	{
		del_node(a);
		a->stack = NULL;
	}
	else
		del_node(a);
	if (ind)
		write(1, "pb\n", 3);
}
