/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:56:52 by aahlyel           #+#    #+#             */
/*   Updated: 2022/12/05 21:59:25 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// LIS <=> Longest Increasing Subsequence

t_len	ft_lis_controll(t_lst **stack_a, t_lst **stack_b, int ac)
{
	t_len	lenght;

	lenght.max = get_max_lis(*stack_a, ac);
	lenght.stack_a = define_sequence(*stack_a, ac, lenght.max);
	lenght.stack_b = ac - lenght.stack_a;
	lis_divide(stack_a, stack_b, ac);
	// if ((*stack_a)->content > (*stack_a)->prev->content) // well see
	// {
	// 	rotate(stack_a);
	// 	write(1, "ra\n", 3);
	// }
	return (lenght);
}

int	define_sequence(t_lst *list, int ac, int max_lis)
{
	t_lst *head;
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	j = max_lis;
	head = list;
	// printf("%d\n",j);
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
			write(1, "pb\n", 3);
		}
		else if (j == count)
			break ;
		else
		{
			rotate(stack_a);
			write(1, "ra\n", 3);
		}
	}
}

void	get_lis(t_lst *list, int ac)
{
	t_lst *head;
	t_lst *tmp;
	int	zero;
	int	i;
	int	j;

	i = 1;
	head = list;
	while (i < ac)
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

int	get_max_lis(t_lst *list, int ac)
{
	int max_lis;
	int	i;

	max_lis = 1;
	i = 0;
	while (i++ < ac)
	{
		max_lis = max(max_lis, list->LIS);
		list = list->next;
	}
	return (max_lis);
}

int	check_lis_rev_sorted(t_lst *list, int ac)
{
	int	i;

	i = 0;
	while (i++ < ac)
	{
		if (list->LIS != 1)
			return (0);
		list = list->next;
	}
	return (1);
}

int	check_lis_sorted(t_lst *list, int ac)
{
	int	i;

	i = 0;
	while (i++ < ac)
	{
		if (list->LIS != i)
		{
			return (0);
		}
		list = list->next;
	}
	return (1);
}

int	check_lis(t_lst *list, int ac)
{
	if (check_lis_sorted(list, ac))
		return (0);
	else if (check_lis_rev_sorted(list, ac))
		return (-1);
	return (1);
}