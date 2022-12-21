/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:55:33 by aahlyel           #+#    #+#             */
/*   Updated: 2022/12/21 13:02:38 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// void	swap(t_lst **head)
// {
// 	long long	tmp;

// 	tmp = (*head)->content;
// 	(*head)->content = ((*head)->next)->content;
// 	((*head)->next)->content = tmp;
// }

void	swap_a(t_lst **head, int ind)
{
	long long	tmp;

	tmp = (*head)->content;
	(*head)->content = ((*head)->next)->content;
	((*head)->next)->content = tmp;
	if (ind)
		write(1, "sa\n", 3);
}

void	swap_b(t_lst **head, int ind)
{
	long long	tmp;

	tmp = (*head)->content;
	(*head)->content = ((*head)->next)->content;
	((*head)->next)->content = tmp;
	if (ind)
		write(1, "sb\n", 3);
}

void	ss(t_lst **stack_a, t_lst **stack_b)
{
	swap_a(stack_a, 0);
	swap_b(stack_b, 0);
	write(1, "ss\n", 3);
}
