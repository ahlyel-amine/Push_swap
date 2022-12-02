/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 12:06:24 by aahlyel           #+#    #+#             */
/*   Updated: 2022/12/02 17:43:57 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sort_rev(t_lst *stack_a, int ac);

void	ft_sort_controller(t_lst *stack_a, int ac)
{
	t_lst	*stack_b;
	t_len	lenght;

	stack_b = NULL;
	get_lis(stack_a, ac);
	if(!check_lis(stack_a, ac))
		return ;
	if(check_lis(stack_a, ac) == -1)
		return (ft_sort_rev(stack_a, ac));
	lenght = ft_lis_controll(&stack_a, &stack_b, ac);
	ft_comb_controll(&stack_a, &stack_b, lenght);
	// lenght.stack_a = 16;
	// lenght.stack_b = ac - 16;
	// print_stack(stack_a, stack_b, lenght);

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
		reverse(&stack_b);
		write(1, "rrb\n", 4);
		push_b(&stack_a, &stack_b);
		write(1, "pa\n", 3);
	}
}
