/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 20:57:59 by aahlyel           #+#    #+#             */
/*   Updated: 2023/01/19 21:45:01 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	ft_sort(t_list **garbg, t_lst **stack_a)
{
	t_lst	*fake;

	fake = NULL;
	// while ((*stack_a)->lenght.stack_len >= 1)
	// {
		ft_lstdup(garbg, &fake, stack_a);

		qwick_sort(&fake);
		print_stack(*stack_a, fake);
		// print_stack(*stack_a, NULL);

	// }
}
