/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:47:46 by aahlyel           #+#    #+#             */
/*   Updated: 2022/11/30 16:43:37 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_lis(t_lst *list, int ac);
int		get_parsed(t_lst *list, int ac, int max_lis);
int		get_max_lis(t_lst *list, int ac);
void	ft_sort_stacks(t_lst **stack_a, t_lst **stack_b, int ac);
void	sort_tmp(t_lst **sorted_stack, int ac);
void	ft_lstdup(t_lst **new_stack, t_lst *stack, int ac);
void	ft_calcul_comb(t_lst **stack_a, t_lst **stack_b, int len_stack_a, int len_stack_b);

// LIS <=> Longest Increasing Subsequence

void	ft_sort(t_lst *stack_a, int ac)
{
	t_lst	*stack_b;
	int	max_lis;
	int	len_stack_b;

	stack_b = NULL;
	int i = 0;
	get_lis(stack_a, ac - 1);
	max_lis = get_max_lis(stack_a, ac);
	len_stack_b = get_parsed(stack_a, ac - 1, max_lis);
	ft_get_stack_parsed(&stack_a, &stack_b, ac - 1);
	ft_calcul_comb(&stack_a, &stack_b, ac - len_stack_b - 1, len_stack_b);
	// while (++i < 7)
	// {
	// 	printf("%lld : [%lld] (%lld) \n",
	// 	 stack_a->LIS, stack_a->content, stack_a->parse_it);
	// 	stack_a = stack_a->next;
	// }
	// printf("<--------------------------->\n");
	// while (++i < ac)
	// {
	// 	printf("%lld : [%lld] (%lld) \n",
	// 	 stack_b->LIS, stack_b->content, stack_b->parse_it);
	// 	stack_b = stack_b->next;
	// }
}

void	ft_calcul_comb(t_lst **stack_a, t_lst **stack_b, int len_stack_a, int len_stack_b) //in work
{
	t_lst	*dup_a;
	t_lst	*dup_b;

	dup_b = NULL;
	dup_a = NULL;
	ft_lstdup(&dup_a, *stack_a, len_stack_a);
	ft_lstdup(&dup_b, *stack_b, len_stack_b);

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

void	sort_tmp(t_lst **sorted_stack, int ac)
{
	t_lst		*tmp;
	long long	temp;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i++ < ac)
	{
		tmp = (*sorted_stack)->next;
		j = i + 1;
		while (j++ < ac)
		{
			if ((*sorted_stack)->content > tmp->content)
			{
				temp = (*sorted_stack)->content;
				(*sorted_stack)->content = tmp->content;
				tmp->content = temp;
			}
			tmp = tmp->next;
		}
		(*sorted_stack) = (*sorted_stack)->next;
	}
	(*sorted_stack) = (*sorted_stack)->prev;
}

void	ft_sort_stacks(t_lst **stack_a, t_lst **stack_b, int ac)
{
	t_lst	*tmp;
	int	i;

	i = 0;
	ft_lstdup(&tmp, *stack_b, ac - 7);
	sort_tmp(&tmp, ac - 7);
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
		if ((*stack_a)->parse_it && j < count)
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

int	get_parsed(t_lst *list, int ac, int max_lis)
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
			list->parse_it = 0;
			count++;
		}
		j++;
		i++;
	}
	return (count);
}

// void	get_parsed(t_lst *list, int ac, int max_lis)
// {
// 	t_lst *head;
// 	long long tmp;
// 	int	zero;
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 1;
// 	head = list;
// 	tmp = LONG_MIN;
// 	while (i < ac)
// 	{
// 		list = head;
// 		zero = 0;
// 		while (list->LIS != j && j < max_lis + 1)
// 		{
// 			list = list->next;
// 			if (list->LIS == 1 && j == 1)
// 			{
// 				while (list->next->LIS == 1)
// 					list = list->next;
// 				break ;
// 			}
// 			if (list->LIS == j)
// 				break ;
// 		}
// 		if (list->LIS == j && tmp < list->content)
// 		{
// 			tmp = list->content;
// 			list->parse_it = 0;
// 		}
// 		j++;
// 		i++;
// 	}
// }
