/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 21:20:06 by aahlyel           #+#    #+#             */
/*   Updated: 2023/01/21 01:34:22 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

// void	qwick_sort(t_stack *fake)
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

void	qwick_sort(int **table, int lenght)
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
