/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 12:06:24 by aahlyel           #+#    #+#             */
/*   Updated: 2022/12/02 23:07:56 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sort_rev(t_lst *stack_a, int ac);

void	ft_sort_controller(t_lst *stack_a, int ac)
{
	t_lst	*stack_b;
	t_len	lenght;
	int		min;

	stack_b = NULL;
	get_lis(stack_a, ac);
	if(!check_lis(stack_a, ac))
		return ;
	if(check_lis(stack_a, ac) == -1)
		return (ft_sort_rev(stack_a, ac));
	lenght = ft_lis_controll(&stack_a, &stack_b, ac);
	// while (stack_b)
	// {
		lenght.min = ft_comb_controll(&stack_a, &stack_b, lenght);

	// }
	// sort_element(&stack_a, &stack_b, lenght);

	print_stack(stack_a , stack_b, lenght);
}

// void	sort_element(t_lst **stack_a, t_lst **stack_b, t_len lenght)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i++ < lenght.min)
// 	{
// 		rotate(stack_b);
// 		write (1, "rb\n", 3);
// 	}
// 	i = 0;
// 	while (i++ < lenght.stack_a)
// 	{
// 		tmp = sort_conditions(*stack_a, *stack_b, length);
// 		if (tmp)
// 		{
// 			(*stack_b)->parse_it += tmp;
// 			break ;
// 		}
// 		rotate(stack_a);
// 		write (1, "ra\n", 3);
// 	}
// }

// int	sort_conditions(t_lst *stack_a, t_lst *stack_b, t_len length)
// {
// 	if (be_first(stack_a, stack_b))
// 		return (1);
// 	else if (be_last_comb(stack_a, stack_b, length))
// 		return (1);
// 	else if (be_secondlast_comb(stack_a, stack_b))
// 		return (1);
// 	else if (be_second_comb(stack_a, stack_b))
// 		return (1);
// 	return (0);
// }

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
