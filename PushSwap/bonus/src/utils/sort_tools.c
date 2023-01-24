/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 02:22:31 by aahlyel           #+#    #+#             */
/*   Updated: 2023/01/24 03:20:08 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker.h"

void	fill_table(int **table, t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->lenght)
	{
		(*table)[i] = a->stack->content;
		a->stack = a->stack->next;
		i++;
	}
}

void	qwik_sort(int **table, int lenght)
{
	int		tmp;
	int		i;
	int		j;

	i = 0;
	while (i < lenght)
	{
		j = i + 1;
		while (j < lenght)
		{
			if ((*table)[i] > (*table)[j])
			{
				tmp = (*table)[i];
				(*table)[i] = (*table)[j];
				(*table)[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	push_swap(t_list **garbg, t_list *instractions, t_stack *stack)
{
	t_stack	*b;

	b = ft_malloc(malloc(sizeof(t_stack)), garbg);
	b->stack = NULL;
	while (instractions)
	{
		if (!ft_strncmp(instractions->content, "ra\n", 3))
			rotate_a(stack);
		else if (!ft_strncmp(instractions->content, "rb\n", 3))
			rotate_b(b);
		else if (!ft_strncmp(instractions->content, "rr\n", 3))
			rr(stack, b);
		else if (!ft_strncmp(instractions->content, "pa\n", 3))
			push_a(garbg, stack, b);
		else if (!ft_strncmp(instractions->content, "pb\n", 3))
			push_b(garbg, b, stack);
		else if (!ft_strncmp(instractions->content, "sa\n", 3))
			swap_a(stack);
		else if (!ft_strncmp(instractions->content, "sb\n", 3))
			swap_b(stack);
		else if (!ft_strncmp(instractions->content, "ss\n", 3))
			ss(stack, b);
		else if (!ft_strncmp(instractions->content, "rra\n", 4))
			reverse_a(stack);
		else if (!ft_strncmp(instractions->content, "rrb\n", 4))
			reverse_b(b);
		else if (!ft_strncmp(instractions->content, "rrr\n", 4))
			rrr(stack, b);
		else
			break ;
		instractions = instractions->next;
	}
}

void	ft_sort_args(t_list **garbg, t_stack *stack, int **table)
{
	if (stack->stack)
	{
		*table = ft_malloc(malloc(stack->lenght * sizeof(int)), garbg);
		fill_table(table, stack);
		qwik_sort(table, stack->lenght);
	}
}

int	compare_stacks(t_list **garbg, t_stack *a, int *list, int ind)
{
	int	i;

	i = 0;
	while (i < a->lenght)
	{
		if (ind && a->stack->content != list[i])
			ft_exit(NULL, garbg, 1, 2);
		else if (!ind &&  a->stack->content != list[i])
			return  (0);
		i++;
		a->stack = a->stack->next;
	}
	if (ind)
		ft_exit(NULL, garbg, 1, 1);
	return (1);
}
