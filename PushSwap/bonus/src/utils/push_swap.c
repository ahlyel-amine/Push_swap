/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 05:29:24 by aahlyel           #+#    #+#             */
/*   Updated: 2023/01/24 05:33:01 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker.h"

void	push_swap(t_list **garbg, t_list *instractions, t_stack *stack)
{
	t_stack	*b;

	b = ft_malloc(malloc(sizeof(t_stack)), garbg);
	b->stack = NULL;
	while (instractions)
	{
		if (!sort_functions(garbg, instractions->content, stack, b))
			break ;
		instractions = instractions->next;
	}
}

int	sort_functions(t_list **garbg, void *content, t_stack *a, t_stack *b)
{
	if (!ft_strncmp(content, "ra\n", 3))
		rotate_a(a);
	else if (!ft_strncmp(content, "rb\n", 3))
		rotate_b(b);
	else if (!ft_strncmp(content, "rr\n", 3))
		rr(a, b);
	else if (!ft_strncmp(content, "pa\n", 3))
		push_a(garbg, a, b);
	else if (!ft_strncmp(content, "pb\n", 3))
		push_b(garbg, b, a);
	else if (!ft_strncmp(content, "sa\n", 3))
		swap_a(a);
	else if (!ft_strncmp(content, "sb\n", 3))
		swap_b(a);
	else if (!ft_strncmp(content, "ss\n", 3))
		ss(a, b);
	else if (!ft_strncmp(content, "rra\n", 4))
		reverse_a(a);
	else if (!ft_strncmp(content, "rrb\n", 4))
		reverse_b(b);
	else if (!ft_strncmp(content, "rrr\n", 4))
		rrr(a, b);
	else
		return (0);
	return (1);
}
