/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 23:41:55 by aahlyel           #+#    #+#             */
/*   Updated: 2023/01/17 16:53:15 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

int main(int ac, char **av)
{
	t_list		*garbg;
	t_lst		*head;

	head = NULL;
	garbg = NULL;
	ft_parse(&head, ++av, ac - 1);
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
