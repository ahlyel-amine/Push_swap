/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comb_controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:44:21 by aahlyel           #+#    #+#             */
/*   Updated: 2022/12/09 17:15:28 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	get_combs(t_lst **stack_a, t_lst **stack_b, t_len lenght);

t_len	ft_comb_controll(t_lst **stack_a, t_lst **stack_b, t_len lenght)
{
	t_lst	*head_a;
	t_lst	*head_b;

	lenght.min = 0;
	lenght.max = INT_MAX;
	head_b = *stack_b;
	head_a = *stack_a;
	get_combs(stack_a, stack_b, lenght);
	*stack_a = head_a;
	*stack_b = head_b;
	while ((lenght.min)++ < lenght.stack_b)
	{
		lenght.max = min(lenght.max , (*stack_b)->LIS);
		(*stack_b) = (*stack_b)->next;
	}
	lenght.min = 0;
	*stack_b = head_b;
	while (lenght.min < lenght.stack_b)
	{
		if (lenght.max == (*stack_b)->LIS)
			break ;
		(*stack_b) = (*stack_b)->next;
		(lenght.max)++;
	}
	return (lenght);
}

void	get_combs(t_lst **stack_a, t_lst **stack_b, t_len lenght)
{
	t_lst	*head_a;
	int		i;
	int		j;

	i = 0;
	j = 0;
	head_a = (*stack_a);
	while (i < lenght.stack_b)
	{
		j = 0;
		(*stack_a) = head_a;
		if ((*stack_b)->content < (*stack_a)->content
		&& (*stack_b)->content < (*stack_a)->prev->content)
		{
			(*stack_b)->LIS = 0;
			j = lenght.stack_a;
		}
		if ((*stack_b)->content > (*stack_a)->prev->content)
		{
			(*stack_b)->LIS = lenght.stack_a;
			j = lenght.stack_a;
		}
		while (j++ < lenght.stack_a)
		{
			if ((*stack_b)->content > (*stack_a)->content
			&& (*stack_b)->content < (*stack_a)->next->content)
			{
				(*stack_b)->LIS = j;
				break ;
			}
			(*stack_a) = (*stack_a)->next;
		}
		(*stack_b) = (*stack_b)->next;
		i++;
	}
}

int	select_small_comb(t_lst *stack, int len)
{
	t_lst *head;
	int	mn;
	int	i;

	i = 0;
	mn = 0;
	head = stack;
	while (i++ < len)
	{
		mn = min(mn, stack->parse_it);
		stack = stack->next;
	}
	i = 0;
	while (i++ < len)
	{
		if (head->parse_it == mn)
			return (mn);
		head = head->next;
	}
	return (-1);
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
	// else if (be_last_comb(stack_a, stack_b, length))
	// 	return (2);
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
