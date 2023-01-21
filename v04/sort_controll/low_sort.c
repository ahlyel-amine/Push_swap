/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 18:42:58 by aahlyel           #+#    #+#             */
/*   Updated: 2023/01/21 18:54:38 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	low_sort(t_list **garbg, t_stack *a)
{
	if (a->lenght == 2)
		swap_a(a, 1);
	else if (a->lenght == 3)
		sort_3digits(garbg, a);
	else
		sort_5digits(garbg, a);
}

void	sort_3digits(t_list **garbg, t_stack *a)
{
	int			max_pos;
	long long	max;

	max = 0;
	while (!max)
	{
		max_pos = check_maxb(a, &max);
		max = 0;
		sort_check(garbg, a, &max)
		if (max)
			break ;
		else if (!max_pos)
			rotate_a(a, 1);
		else if (max_pos == 1)
			
	}
}
