/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 12:06:24 by aahlyel           #+#    #+#             */
/*   Updated: 2022/12/02 13:10:22 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sort_rev(t_lst *stack_a, int ac);
void	ft_sort_controller(t_lst *stack_a, int ac)
{
	t_lst	*stack_b;
	t_len	lenght;

	stack_b = NULL;
	lenght.stack_a = ac;
		lenght.stack_b = 0;
		print_stack(stack_a, stack_b, lenght);
		// sleep(1);
		return ;
	get_lis(stack_a, ac);
	// if(!check_lis(stack_a, ac))
	// 	return ;
	// if(check_lis(stack_a, ac) == -1)
	// {
		ft_sort_rev(stack_a, ac);
		// return ;
	// }

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

void	ft_sort_rev(t_lst *stack_a, int ac)
{
	t_lst	*stack_b;
	int		i;
	t_len lenght;

	i = 0;
	stack_b = NULL;
	while (i++ < ac)
	{
		push_b(&stack_b, &stack_a);
		write(1, "pb\n", 3);
	}
	i = 0;
	while (i++ < ac)
	{
		push_a(&stack_a, &stack_b);
		// lenght.stack_a = i;
		// lenght.stack_b = ac - i;
		// print_stack(stack_a, stack_b, lenght);
		// sleep(1);
		// write(1, "pa\n", 3);
	}
}
