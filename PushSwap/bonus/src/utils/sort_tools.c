/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 02:22:31 by aahlyel           #+#    #+#             */
/*   Updated: 2023/01/24 16:43:26 by aahlyel          ###   ########.fr       */
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

void	ft_sort_args(t_list **garbg, t_stack *stack, int **table)
{
	if (stack->stack)
	{
		*table = ft_malloc(malloc(stack->lenght * sizeof(int)), garbg);
		fill_table(table, stack);
		qwik_sort(table, stack->lenght);
	}
}

void	compare_stacks(t_list **garbg, t_stack *a, int *list)
{
	int	i;

	i = 0;
	while (i < a->lenght)
	{
		if (a->stack->content != list[i])
			ft_exit(NULL, garbg, 1, 2);
		i++;
		a->stack = a->stack->next;
	}
	ft_exit(NULL, garbg, 1, 1);
}
