/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 12:06:24 by aahlyel           #+#    #+#             */
/*   Updated: 2022/12/02 12:09:40 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sort_controller(t_lst *stack_a, int ac)
{
	t_lst	*stack_b;
	t_len	lenght;

	stack_b = NULL;
	get_lis(stack_a, ac);
	lenght.stack_a = ac;
	lenght.stack_b = 0;
	print_stack(stack_a, stack_b, lenght);

	// lenght.max = get_max_lis(stack_a, ac);
	// lenght.stack_a = get_parsed(stack_a, ac, lenght.max); // need rework
	// lenght.stack_b = ac - lenght.stack_a;
	// ft_get_stack_parsed(&stack_a, &stack_b, ac);
	// ft_calcul_comb(&stack_a, &stack_b, lenght);
	// while (i++ < 2)
	// {
	// 	printf("%lld|%lld|%lld\n", stack_a->LIS, stack_a->content, stack_a->parse_it);
	// 	stack_a = stack_a->next;
	// }
	// printf("<----->\n");
	// while (i++ < ac)
	// {
	// 	printf("%lld|%lld\n", stack_b->content, stack_b->parse_it);
	// 	stack_b = stack_b->next;
	// }
}
