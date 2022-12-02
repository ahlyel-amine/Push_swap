/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comb_controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:44:21 by aahlyel           #+#    #+#             */
/*   Updated: 2022/12/02 20:44:16 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_comb_controll(t_lst **stack_a, t_lst **stack_b, t_len lenght)
{
	t_lst	*head_a;
	t_lst	*head_b;

	head_b = *stack_b;
	head_a = *stack_a;
	get_combs_front(stack_a, stack_b, lenght);
	*stack_b = head_b;
	*stack_a = head_a;
	print_stack(*stack_a , *stack_b, lenght);
}

void	get_combs_front(t_lst **stack_a, t_lst **stack_b, t_len length)
{
	int		i;
	int		j;
	int		tmp;
	t_lst	*head_a;

	i = 0;
	j = 0;
	head_a = *stack_a;
	while (i < length.stack_b)
	{
		(*stack_b)->parse_it += i;
		j = 0;
		(*stack_a) = head_a;
		while (j++ < length.stack_a)
		{
			tmp = combs_conditions(*stack_a, *stack_b, length);
			if (tmp)
			{
				(*stack_b)->parse_it += tmp;
				break ;
			}
			rotate(stack_a);
			(*stack_b)->parse_it += 2;
		}
		*stack_b = (*stack_b)->next;
		i++;
	}
}

void	get_combs_back(t_lst **stack_a, t_lst **stack_b, t_len length)
{
	int		i;
	int		k;
	int		j;
	int		tmp;
	t_lst	*head_a;
	t_lst	*head_b;

	i = 0;
	k = 0;
	j = 0;
	head_a = *stack_a;
	head_b = *stack_b;
	while (i < length.stack_b)
	{
		(*stack_b) = head_b;
		k = 0;
		while (k++ < i + 1)
			reverse(stack_b);
		(*stack_b)->parse_it += i + 1;
		j = 0;
		(*stack_a) = head_a;
		while (j++ < length.stack_a)
		{
			tmp = combs_conditions(*stack_a, *stack_b, length);
			if (tmp)
			{
				(*stack_b)->parse_it += tmp;
				break ;
			}
			rotate(stack_a);
			(*stack_b)->parse_it += 2;
		}
		i++;
	}
}

int	combs_conditions(t_lst *stack_a, t_lst *stack_b, t_len length)
{
	if (be_first_comb(stack_a, stack_b))
		return (1);
	else if (be_last_comb(stack_a, stack_b, length))
		return (2);
	else if (be_last_comb(stack_a, stack_b, length))
		return (2);
	else if (be_secondlast_comb(stack_a, stack_b))
		return (4);
	else if (be_second_comb(stack_a, stack_b))
		return (2);
	return (0);
}

int	be_second_comb(t_lst *stack_a, t_lst *stack_b)
{
	if (stack_b->content > stack_a->content
	&& stack_b->content < (stack_a->next)->content)
		return (2);
	return (0);
}

int	be_secondlast_comb(t_lst *stack_a, t_lst *stack_b)
{
	if (stack_b->content > stack_a->prev->prev->content
	&& stack_b->content < stack_a->prev->content)
		return (2);
	return (0);
}

int	be_last_comb(t_lst *stack_a, t_lst *stack_b, t_len length)
{
	int	i;

	i = 0;
	while (i < length.stack_b || i < length.stack_a)
	{
		if (stack_b->content <= stack_a->content)
			return (0);
		stack_a = stack_a->next;
		stack_b = stack_b->next;
		i++;
	}
	return (2);
}

int	be_first_comb(t_lst *stack_a, t_lst *stack_b)
{
	if (stack_b->content < stack_a->content)
		return (1);
	return (0);
}
