/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 18:42:58 by aahlyel           #+#    #+#             */
/*   Updated: 2023/01/21 19:32:27 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	low_sort(t_list **garbg, t_stack *a)
{
	if (a->lenght == 2)
		swap_a(a, 1);
	else if (a->lenght == 3)
		sort_3digits(garbg, a);
	// else
	// 	sort_5digits(garbg, a);
	print_stack(a, NULL);
}

void	sort_3digits(t_list **garbg, t_stack *a)
{
	int			max_pos;
	int			min_pos;
	long long	max;
	long long	min;

	max_pos = check_listmax(a, &max);
	min_pos = check_listmin(a, &min);
	if (!max_pos && min_pos == 1)
		rotate_a(a, 1);
	else if (!max_pos && min_pos == 2)
	{
		rotate_a(a, 1);
		swap_a(a, 1);
	}
	else if (max_pos == 1 && !min_pos)
	{
		swap_a(a, 1);
		rotate_a(a, 1);
	}
	else if (max_pos == 1 && min_pos == 2)
		reverse_a(a, 1);
	else
		swap_a(a, 1);
}
