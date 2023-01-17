/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:56:52 by aahlyel           #+#    #+#             */
/*   Updated: 2023/01/17 16:48:41 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

// LIS <=> Longest Increasing Subsequence

t_len	ft_lis_controll(t_lst **stack_a, t_lst **stack_b, int ac)
{
	t_len	lenght;

	lenght.max = get_max_lis(*stack_a);
	lenght.stack_a = define_sequence(*stack_a, lenght.max);
	lenght.stack_b = ac - lenght.stack_a;
	lis_divide(stack_a, stack_b, ac);
	// if ((*stack_a)->content > (*stack_a)->prev->content) // well see
	// {
	// 	rotate(stack_a);
	// 	write(1, "ra\n", 3);
	// }
	return (lenght);
}

int	define_sequence(t_lst *list, int max_lis)
{
	t_lst *head;
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	j = max_lis;
	head = list;
	while (i < max_lis)
	{
		while (j > 0)
		{
			if (list->LIS == j)
				break ;
			list = list->prev;
		}
		if (list->LIS == j)
		{
			list->parse_it = 1;
			count++;
		}
		j--;
		i++;
	}
	return (count);
}

int	sequence_len(t_lst *stack, int len)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (i++ < len)
	{
		if (stack->LIS)
			count++;
		stack = stack->next;
	}
	return (count);
}

int	still_parse(t_lst *stack)
{
	int i = 0;

	while (i++ < stack->lenght.stack_len)
	{
		if (!(stack->parse_it))
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	lis_divide(t_lst **stack_a, t_lst **stack_b, int ac)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	j = 0;
	count = sequence_len(*stack_a, ac);
	while (i++ < ac)
	{
		if (!((*stack_a)->parse_it) && j < count)
		{
			j++;
			push_b(stack_b, stack_a);
		}
		else if (j == count || still_parse(*stack_a))
			break ;
		else
			rotate_a(stack_a, 1);
	}
}

void	get_lis(t_lst *list)
{
	t_lst *head;
	t_lst *tmp;
	int	zero;
	int	i;
	int	j;

	i = 1;
	head = list;
	while (i < list->lenght.stack_len)
	{
		zero = 0;
		j = 0;
		list = head;
		tmp = list;
		while (zero++ < i)
			tmp = tmp->next;
		while (j < i)
		{
			if (tmp->content > list->content)
				tmp->LIS = max(tmp->LIS, list->LIS + 1);
			list = list->next;
			j++;
		}
		i++;
	}
}

int	get_max_lis(t_lst *list)
{
	int max_lis;
	int	i;

	max_lis = 1;
	i = 0;
	while (i++ < list->lenght.stack_len)
	{
		max_lis = max(max_lis, list->LIS);
		list = list->next;
	}
	return (max_lis);
}

int	check_lis_rev_sorted(t_lst *list) //two
{
	int	i;

	i = 0;
	while (i++ < list->lenght.stack_len)
	{
		if (list->LIS != 1)
			return (0);
		list = list->next;
	}
	return (1);
}

int	check_lis_sorted(t_lst *list) //one
{
	int	i;

	i = 0;
	while (i++ < list->lenght.stack_len)
	{
		if (list->LIS != i)
		{
			return (0);
		}
		list = list->next;
	}
	return (1);
}

int	check_lis(t_lst *list) //three
{
	if (check_lis_sorted(list))
		return (0);
	else if (check_lis_rev_sorted(list))
		return (-1);
	return (1);
}
