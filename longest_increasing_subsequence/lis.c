/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:56:52 by aahlyel           #+#    #+#             */
/*   Updated: 2022/12/02 12:53:42 by aahlyel          ###   ########.fr       */
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
	while (i < ac)
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



int	check_lis_rev_sorted(t_lst *list, int ac)
{
	int	i;

	i = 0;
	while (i++ < ac)
	{
		if (list->LIS != 1)
			return (0);
		list = list->next;
	}
	return (1);
}

int	check_lis_sorted(t_lst *list, int ac)
{
	int	i;

	i = 0;
	while (i++ < ac)
	{
		if (list->LIS != i)
			return (0);
		list = list->next;
	}
	return (1);
}

int	check_lis(t_lst *list, int ac)
{
	if (check_lis_sorted(list, ac))
		return (0);
	else if (check_lis_rev_sorted(list, ac))
		return (-1);
	return (1);
}
