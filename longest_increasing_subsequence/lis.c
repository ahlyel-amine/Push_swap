/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:56:52 by aahlyel           #+#    #+#             */
/*   Updated: 2022/12/02 12:27:49 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	get_lis(t_lst *list, int ac)
{
	t_lst *head;
	t_lst *tmp;
	int	zero;
	int	i;
	int	j;

	i = 1;
	head = list;
	while (i <= ac)
	{
		zero = 0;
		j = 0;
		list = head;
		tmp = list;
		while (zero++ < i)
			tmp = tmp->next;
		while (j < i)
		{
			if (tmp->content > list->content)
				tmp->LIS = max(tmp->LIS, list->LIS + 1);
			list = list->next;
			j++;
		}
		i++;
	}
}

int	get_max_lis(t_lst *list, int ac)
{
	int max_lis;
	int	i;

	max_lis = 1;
	i = 0;
	while (i++ < ac)
	{
		max_lis = max(max_lis, list->LIS);
		list = list->next;
	}
	return (max_lis);
}
