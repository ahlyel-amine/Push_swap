// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   sort_functions_demo.c                              :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/11/29 16:47:51 by aahlyel           #+#    #+#             */
// /*   Updated: 2022/11/29 16:48:01 by aahlyel          ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// // #include "push_swap.h"

// void	get_lis(t_lst *list, int ac);
// void	get_parsed(t_lst *list, int ac, int max_lis);
// int	get_mac_lis(t_lst *list, int ac);
// void	ft_sort_stacks(t_lst **stack_a, t_lst **stack_b, int ac);
// // LIS <=> Longest Increasing Subsequence
// void	sort_tmp(t_lst **sorted_stack, int ac);
// void	ft_lstdup(t_lst **stored_stack, t_lst *stack_a, int ac);

// void	ft_sort(t_lst *stack_a, int ac)
// {
// 	t_lst	*stack_b;
// 	t_lst	*sorted_stack;
// 	int		max_lis;

// 	stack_b = NULL;
// 	ft_lstdup(&sorted_stack, stack_a, ac - 1);
// 	int i = 0;
// 	while (++i < ac)
// 	{
// 		printf("[%lld]\n",sorted_stack->content);
// 		sorted_stack = sorted_stack->next;
// 	}
// 	sort_tmp(&sorted_stack, ac);
// 	sorted_stack = sorted_stack->next;
// }

// void	ft_lstdup(t_lst **stored_stack, t_lst *stack_a, int ac)
// {
// 	int i = 0;
// 	while (i++ < ac)
// 	{
// 		new_node(stored_stack, stack_a->content);
// 		stack_a = stack_a->next;
// 	}
// }

// void	sort_tmp(t_lst **sorted_stack, int ac)
// {
// 	t_lst		*tmp;
// 	long long	temp;
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (i++ < ac)
// 	{
// 		tmp = (*sorted_stack)->next;
// 		j = i + 1;
// 		while (j++ < ac)
// 		{
// 			if ((*sorted_stack)->content > tmp->content)
// 			{
// 				temp = (*sorted_stack)->content;
// 				(*sorted_stack)->content = tmp->content;
// 				tmp->content = temp;
// 			}
// 			tmp = tmp->next;
// 		}
// 		(*sorted_stack) = (*sorted_stack)->next;
// 	}
// 	(*sorted_stack) = (*sorted_stack)->prev;
// }
