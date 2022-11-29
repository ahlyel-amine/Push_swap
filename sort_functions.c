/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:47:46 by aahlyel           #+#    #+#             */
/*   Updated: 2022/11/29 17:55:07 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_lis(t_lst *list, int ac);
void	get_parsed(t_lst *list, int ac, int max_lis);
int	get_mac_lis(t_lst *list, int ac);
void	ft_sort_stacks(t_lst **stack_a, t_lst **stack_b, int ac);

// LIS <=> Longest Increasing Subsequence

void	ft_sort(t_lst *stack_a, int ac)
{
	t_lst	*stack_b;
	int	max_lis;

	stack_b = NULL;
	int i = 0;
	get_lis(stack_a, ac - 1);
	max_lis = get_mac_lis(stack_a, ac);
	get_parsed(stack_a, ac - 1, max_lis);
	// ft_get_stack_parsed(&stack_a, &stack_b, ac);
	while (++i < ac)
	{
		printf("%lld : [%lld] (%lld) \n",
		 stack_a->LIS, stack_a->content, stack_a->parse_it);
		stack_a = stack_a->next;
	}
	// ft_sort_stacks(&stack_a, &stack_b, ac);
	// i = 0;
	// while (i++ < ac)
	// {
	// 	printf("%lld : [%lld] (%lld) \n",
	// 	 stack_b->LIS, stack_b->content, stack_b->parse_it);
	// 	stack_b = stack_b->next;
	// }
}

// void	ft_sort_stacks(t_lst **stack_a, t_lst **stack_b, int ac)
// {
// 	int	i;

// 	i = 0;
// 	while (i++ < ac)
// 	{
// 		if ()
// 	}
// }

void	ft_get_stack_parsed(t_lst **stack_a, t_lst **stack_b, int ac)
{
	t_lst	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	while (i++ < ac)
	{
		if ((*stack_a)->parse_it)
		{
			push_b(stack_b, stack_a);
			write(1, "pb\n", 3);
		}
		else
		{
			rotate(stack_a);
			write(1, "ra\n", 3);
		}
	}
}

int	max(int nbr1, int nbr2)
{
	if (nbr1 > nbr2)
		return (nbr1);
	return (nbr2);
}

int	get_mac_lis(t_lst *list, int ac)
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

void	get_parsed(t_lst *list, int ac, int max_lis)
{
	t_lst *head;
	t_lst *tmp;
	int	zero;
	int	i;
	int	j;

	i = 0;
	j = 1;
	head = list;
	while (i < ac)
	{
		list = head;
		zero = 0;
		tmp = head;
		while (list->LIS != j && j < max_lis + 1)
		{
			list = list->next;
			if (list->LIS == j)
				break ;
		}
		tmp = list->next;
		while (zero++ < ac)
		{
			if (tmp->LIS == j && list->content > tmp->content)
				list = tmp;
			tmp = tmp->next;
		}
		if (list->LIS == j)
			list->parse_it = 0;
		j++;
		i++;
	}
}
