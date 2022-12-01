/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:47:46 by aahlyel           #+#    #+#             */
/*   Updated: 2022/12/01 20:04:57 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// LIS <=> Longest Increasing Subsequence

void	ft_sort(t_lst *stack_a, int ac)
{
	t_lst	*stack_b;
	t_len	lenght;
	int	len_stack_a;

	stack_b = NULL;
	int i = 0;
	i = 0;
	get_lis(stack_a, ac);
	lenght.max = get_max_lis(stack_a, ac);
	lenght.stack_a = get_parsed(stack_a, ac, lenght.max); // need rework
	lenght.stack_b = ac - lenght.stack_a;
	ft_get_stack_parsed(&stack_a, &stack_b, ac);
	ft_calcul_comb(&stack_a, &stack_b, lenght);
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

void	ft_lstdup(t_lst **new_stack, t_lst *stack, int ac)
{
	int i = 0;
	while (i++ < ac)
	{
		new_node(new_stack, stack->content);
		stack = stack->next;
	}
}

void	ft_get_stack_parsed(t_lst **stack_a, t_lst **stack_b, int ac)
{
	t_lst	*tmp;
	int		i;
	int		j;
	int		count;

	i = 0;
	j = 0;
	count = 0;
	tmp = *stack_a;
	while (i++ < ac)
	{
		if (tmp->LIS)
			count++;
		tmp = tmp->next;
	}
	i = 0;
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
	if ((*stack_a)->content > (*stack_a)->prev->content)
	{
		rotate(stack_a);
		write(1, "ra\n", 3);
	}
}

int	max(int nbr1, int nbr2)
{
	if (nbr1 > nbr2)
		return (nbr1);
	return (nbr2);
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

void	get_lis(t_lst *list, int ac)
{
	t_lst *head;
	t_lst *tmp;
	int	zero;
	int	i;
	int	j;

	i = 0;
	i = 1;
	head = list;
	while (i <= ac)
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

int	get_parsed(t_lst *list, int ac, int max_lis) // need rework
{
	t_lst *head;
	long long tmp;
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	j = 1;
	head = list;
	tmp = LONG_MIN;
	while (i < ac)
	{
		list = head;
		while (j < max_lis + 1)
		{
			if (list->LIS == j)
				break ;
			list = list->next;
		}
		if (list->LIS == j && tmp < list->content)
		{
			tmp = list->content;
			list->parse_it = 1;
			count++;
		}
		j++;
		i++;
	}
	return (count);
}
