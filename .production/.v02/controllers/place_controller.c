/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_controller.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:43:16 by aahlyel           #+#    #+#             */
/*   Updated: 2022/12/23 02:46:11 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_max_min(t_lst *stack_a, t_lst *stack_b, int place_b)
{
	int	i;
	int	min;
	int max;
	// int	len_b;

	i = 0;
	// if (stack_b->lenght.stack_len % 2)
	// 	len_b = stack_b->lenght.stack_len / 2 + 1;
	// else
	// 	len_b = stack_b->lenght.stack_len / 2;
	min = small_element(stack_a);
	max = high_element(stack_a);

	if (stack_b->content < min)
	{
		while (i++ < stack_a->lenght.stack_len)
		{
			if (stack_a->content == min)
				break ;
			rotate_a(&stack_a, 0);
		}

		stack_b->parse_it = place_b + i;
		return (1);
	}
	if (stack_b->content > max)
	{
		while (i++ < stack_a->lenght.stack_len)
		{
			if (stack_a->content == max)
				break ;
			rotate_a(&stack_a, 0);
		}
		stack_b->parse_it = place_b + i;
		return (1);
	}
	return (0);
}

void	check_front(t_lst *stack_a, t_lst *stack_b)
{
	int		len_b;
	int		i;
	int		j;

	i = 0;
	if (stack_b->lenght.stack_len % 2)
		len_b = stack_b->lenght.stack_len / 2 + 1;
	else
		len_b = stack_b->lenght.stack_len / 2;
	while (i++ < len_b)
	{
		j = 0;
		if (!check_max_min(stack_a, stack_b, i))
		{
			while (j++ < stack_a->lenght.stack_len)
			{
				if (stack_a->content < stack_b->content
				&& stack_b->content < stack_a->next->content)
					stack_b->parse_it = j + i + 1;
				rotate_a(&stack_a, 0);
			}
		}
		rotate_b(&stack_b, 0);
	}
}

void	check_back(t_lst *stack_a, t_lst *stack_b)
{
	int		i;
	int		j;

	i = 0;
	stack_b = stack_b->prev;
	while (i++ < stack_b->lenght.stack_len / 2)
	{
		j = 0;
		if (!check_max_min(stack_a, stack_b, i + 1))
		{

			while (j++ < stack_a->lenght.stack_len)
			{
				if (stack_a->content < stack_b->content
				&& stack_b->content < stack_a->next->content)
					stack_b->parse_it = j + i + 1;
				rotate_a(&stack_a, 0);
			}
		}
		reverse_b(&stack_b, 0);
	}
}

void	check_places(t_lst *stack_a, t_lst *stack_b)
{
	t_lst	*tmp;
	t_lst	*tmp1;

	tmp = stack_a;
	tmp1 = stack_b;
	check_front(stack_a, stack_b);
	check_back(stack_a, stack_b);
	stack_a = tmp;
	stack_b = tmp1;
	check_front_back(stack_a, stack_b);
	check_back_back(stack_a, stack_b);
}
