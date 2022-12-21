/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 23:41:55 by aahlyel           #+#    #+#             */
/*   Updated: 2022/12/21 13:02:27 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_3(t_lst *head)
{
	int	i;

	i = 0;
	i = min(head->content, head->next->content);
	i = min(i, (head->next)->next->content);
	if (head->content == i)
	{
		reverse_a(&head, 1);
		swap_a(&head, 1);
	}
	if (head->prev->content == i)
	{
		if (head->content > head->next->content)
			swap_a(&head, 1);
		reverse_a(&head, 1);
	}
	if (head->next->content == i)
	{
		if (head->content > head->prev->content)
			rotate_a(&head, 1);
		else
			swap_a(&head, 1);
	}
}

// void	ft_sort_3(t_lst *head)
// {

// }

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
		ft_sort_3(head);
	// if (head->lenght.stack_len == 5)
	// 	ft_sort_5(head);
	else
		ft_sort_controller(head, ac);
	return (0);
}
