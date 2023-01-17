/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 23:41:55 by aahlyel           #+#    #+#             */
/*   Updated: 2022/12/22 15:05:31 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_3(t_lst **head)
{
	int	i;

	i = 0;
	i = min((*head)->content, (*head)->next->content);
	i = min(i, ((*head)->next)->next->content);
	if ((*head)->content < (*head)->next->content < ((*head)->next)->next->content)
		return ;
	if ((*head)->content == i)
	{
		reverse_a(head, 1);
		swap_a(head, 1);
	}
	if ((*head)->prev->content == i)
	{
		if ((*head)->content > (*head)->next->content)
			swap_a(head, 1);
		reverse_a(head, 1);
	}
	if ((*head)->next->content == i)
	{
		if ((*head)->content > (*head)->prev->content)
			rotate_a(head, 1);
		else
			swap_a(head, 1);
	}
}

void	ft_sort_5(t_lst *head)
{
	t_lst	*head_b;
	int		i;
	int		mn;

	i = 0;
	head_b = NULL;
	push_b(&head_b, &head);
	push_b(&head_b, &head);
	ft_sort_3(&head);
	mn = check_place_in_a(head, head_b->content);

	while (i++ < head->lenght.stack_len)
	{
		rotate_a(&head, 1);
		if (head->prev->content == mn)
			break ;
	}
	push_a(&head, &head_b);
	mn = check_place_in_a(head, head_b->content);
	while (i++ < head->lenght.stack_len)
	{
		rotate_a(&head, 1);
		if (head->prev->content == mn)
			break ;
	}
	// print_stack(head, head_b);
}

int main(int ac, char **av)
{
	t_lst		*head;

	head = NULL;
	if (ac <= 1)
		return (0);
	ac = ft_table(&head, ++av, ac - 1);
	if (ac == -1)
		return (ac);
	if (head->lenght.stack_len == 3)
		ft_sort_3(&head);
	// else if (head->lenght.stack_len == 5)
	// 	ft_sort_5(head);
	else
		ft_sort_controller(head, ac);
	return (0);
}
