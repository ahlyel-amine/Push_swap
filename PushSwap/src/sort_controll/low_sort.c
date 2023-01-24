/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 18:42:58 by aahlyel           #+#    #+#             */
/*   Updated: 2023/01/24 02:04:00 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	low_sort(t_list **garbg, t_stack *a, t_stack *b)
{
	int			min_pos;
	long long	min;

	if (a->lenght == 2)
		swap_a(a, 1);
	else if (a->lenght == 3)
		sort_3digits(a);
	else
	{
		min_pos = check_listmin(a, &min);
		while (min_pos)
		{
			if (min_pos <= a->lenght / 2)
				rotate_a(a, 1);
			else
				reverse_a(a, 1);
			min_pos = check_listmin(a, &min);
		}
		push_b(garbg, b, a, 1);
		low_sort(garbg, a, b);
		push_a(garbg, a, b, 1);
	}
}

void	sort_3digits(t_stack *a)
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
	else if (max_pos == 2 && min_pos == 1)
		swap_a(a, 1);
}
