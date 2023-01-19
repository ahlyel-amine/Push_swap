/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 20:57:59 by aahlyel           #+#    #+#             */
/*   Updated: 2023/01/19 23:51:49 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	sort_help(t_fakelst *fk, t_lst **stack_a,  t_lst **stack_b, t_list **garbg)
{
	if ((*stack_a)->content <= fk->fake_sm->content)
		push_b(garbg, stack_b, stack_a);
	else if ((*stack_a)->content <= fk->fake_bg->content)
	{
		push_b(garbg, stack_b, stack_a);
		if ((*stack_b)->lenght.stack_len >= 2)
			rotate_b(stack_b, 1);
	}
	else
		rotate_a(stack_a, 1);
}

void	ft_sort(t_list **garbg, t_lst **stack_a)
{
	t_lst		*fake;
	t_lst		*stack_b;
	t_fakelst	*fk;

	stack_b = NULL;
	while ((*stack_a)->lenght.stack_len >= 1)
	{
		fake = NULL;
		ft_lstdup(garbg, &fake, stack_a);
		qwick_sort(&fake);
		fk->fake_bg = fake;
		fk->fake_sm = fake;
		fk->bg = (*stack_a)->lenght.stack_len / 8;
		fk->sm = (*stack_a)->lenght.stack_len / 9 / 2;
		while (fk->bg--)
			fk->fake_bg = fk->fake_bg->next;
		while (fk->sm--)
			fk->fake_sm = fk->fake_sm->next;
		sort_help(fk, stack_a, &stack_b, garbg);
	}
		// print_stack(*stack_a, NULL);
		// print_stack(*stack_a, fake);
}
