/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 21:20:06 by aahlyel           #+#    #+#             */
/*   Updated: 2023/01/23 17:38:44 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

// void	qwik_sort(t_stack *fake)
// {
// 	t_lst		*n_fake;
// 	long long	tmp;
// 	int			i;
// 	int			j;

// 	i = 0;
// 	while (i < fake->lenght)
// 	{
// 		j = i + 1;
// 		n_fake = fake->stack->next;
// 		while (j++ < fake->lenght)
// 		{
// 			if (n_fake->content < fake->stack->content)
// 			{
// 				tmp = n_fake->content;
// 				n_fake->content = fake->stack->content;
// 				fake->stack->content = tmp;
// 			}
// 			n_fake = n_fake->next;
// 		}
// 		fake->stack = fake->stack->next;
// 		i++;
// 	}
// }

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

int	check_listmax(t_stack *stack, long long *max)
{
	t_lst		*tmp;
	int			pos;
	int			i;

	i = 0;
	pos = 0;
	tmp = stack->stack;
	*max = tmp->content;
	while (i < stack->lenght)
	{
		if (tmp->content > *max)
		{
			*max = tmp->content;
			pos = i;
		}
		i++;
		tmp = tmp->next;
	}
	return (pos);
}

int	check_listmin(t_stack *stack, long long *min)
{
	t_lst		*tmp;
	int			pos;
	int			i;

	i = 0;
	pos = 0;
	tmp = stack->stack;
	*min = tmp->content;
	while (i < stack->lenght)
	{
		if (tmp->content < *min)
		{
			*min = tmp->content;
			pos = i;
		}
		i++;
		tmp = tmp->next;
	}
	return (pos);
}
