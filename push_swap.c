/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 23:41:55 by aahlyel           #+#    #+#             */
/*   Updated: 2022/12/14 23:17:38 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	t_lst		*head;
	char		**tmp;

	head = NULL;
	if (ac <= 1)
		return (0);
	ac = ft_table(&head, ++av, ac - 1);
	for (int i = 0; i++ < ac;)
	{
		printf("%lld : %d\n", head->content, head->lenght.stack_a);
		head = head->next;
	}
	return (0);
	if (ac == -1)
		return (ac);
	ft_sort_controller(head, ac);
	return (0);
}
