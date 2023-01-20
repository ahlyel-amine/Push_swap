/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_controller2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 01:11:27 by aahlyel           #+#    #+#             */
/*   Updated: 2023/01/17 16:48:59 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	check_max_min_back(t_lst *stack_a, t_lst *stack_b, int place_b)
{
	int	i;
	int	min;
	int max;

	i = 0;
	min = small_element(stack_a);
	max = high_element(stack_a);
	if (stack_b->content < min)
	{
		while (i++ < stack_a->lenght.stack_len)
		{
			if (stack_a->content == min)
				break ;
			reverse_a(&stack_a, 0);
		}
		stack_b->parse_it_back = place_b + i;
		return (1);
	}
	if (stack_b->content > max)
	{
		while (i++ < stack_a->lenght.stack_len)
		{
			if (stack_a->content == max)
				break ;
			reverse_a(&stack_a, 0);
		}
		stack_b->parse_it_back = place_b + i;
		return (1);
	}
	return (0);
}

void	check_front_back(t_lst *stack_a, t_lst *stack_b)
{
	int		len_b;
	int		i;
	int		j;

	i = 0;
	stack_a = stack_a->prev;
	if (stack_b->lenght.stack_len % 2)
		len_b = stack_b->lenght.stack_len / 2 + 1;
	else
		len_b = stack_b->lenght.stack_len / 2;
	while (i < len_b)
	{
		j = 0;
		if (!check_max_min_back(stack_a, stack_b, i++))
		{
			while (j++ < stack_a->lenght.stack_len)
			{

				if (stack_a->content < stack_b->content
				&& stack_b->content < stack_a->prev->content)
				{
					stack_b->parse_it_back = j + i + 1;
				}
				reverse_a(&stack_a, 0);
			}
		}
		rotate_b(&stack_b, 0);
	}
}

void	check_back_back(t_lst *stack_a, t_lst *stack_b)
{
	int		i;
	int		j;

	i = 0;
	stack_a = stack_a->prev;
	stack_b = stack_b->prev;
	while (i < stack_b->lenght.stack_len / 2)
	{
		j = 0;
		if (!check_max_min_back(stack_a, stack_b, i++))
		{
			while (j++ < stack_a->lenght.stack_len)
			{
				if (stack_a->content > stack_b->content
				&& stack_b->content > stack_a->prev->content)
				{

					stack_b->parse_it_back = j + i + 1;
				}
				reverse_a(&stack_a, 0);
			}
		}
		reverse_b(&stack_b, 0);
	}
}
