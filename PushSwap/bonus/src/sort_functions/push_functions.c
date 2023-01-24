/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:47:26 by aahlyel           #+#    #+#             */
/*   Updated: 2023/01/24 02:32:44 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker.h"

void	push_a(t_list **garbg, t_stack *a, t_stack *b)
{
	if (!b || !b->stack)
		ft_exit(NULL, garbg, 1, 2);
	new_node(garbg, a, b->stack->content, 1);
	if (b->stack == b->stack->next)
	{
		del_node(b);
		b->stack = NULL;
	}
	else
		del_node(b);
}

void	push_b(t_list **garbg, t_stack *b, t_stack *a)
{
	if (!a || !a->stack)
		ft_exit(NULL, garbg, 1, 2);
	new_node(garbg, b, a->stack->content, 1);
	if (a->stack == a->stack->next)
	{
		del_node(a);
		a->stack = NULL;
	}
	else
		del_node(a);
}
