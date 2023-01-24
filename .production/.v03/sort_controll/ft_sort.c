/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 20:57:59 by aahlyel           #+#    #+#             */
/*   Updated: 2023/01/24 16:11:40 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

void	check_maxb(t_lst **stack)
{
	t_lst		*tmp;
	long long	mx;
	int			i;

	i = 0;
	tmp = *stack;
	mx = tmp->content;
	while (i++ < tmp->lenght.stack_len)
	{
		mx = max(mx, tmp->content);
		tmp = tmp->next;
	}
	tmp = *stack;
	i = 0;
	while (i++ < tmp->lenght.stack_len)
	{
		if (tmp->content == mx)
			tmp->parse_it = 1;
		tmp = tmp->next;
	}
}

int	wich_half(t_lst *stack)
{
	t_lst	*tmp;
	int		i;

	i = 0;
	tmp = stack;
	while (i < tmp->lenght.stack_len)
	{
		if (tmp->LIS)
		{
			break ;
		}
		i++;
	}
	if (i <= tmp->lenght.stack_len / 2)
		return (1);
	else
		return (0);
}

void	fill_stack_a(t_list **garbg, t_lst **stack_a, t_lst **stack_b)
{
	int	i;

	i = 0;
	while ((*stack_b)->lenght.stack_len > 1)
	{
		check_maxb(stack_b);
		if (wich_half(*stack_b))
			while (!(*stack_b)->parse_it)
				rotate_b(stack_b, 1);
		else
			while (!(*stack_b)->parse_it)
				reverse_b(stack_b, 1);
		if ((*stack_b)->LIS)
			push_a(garbg, stack_a, stack_b);
	}
}

void	ft_sort(t_list **garbg, t_lst **stack_a)
{
	t_lst		*fake;
	t_lst		*stack_b;
	t_fakelst	*fk;

	stack_b = NULL;
	while ((*stack_a)->lenght.stack_len > 1)
	{
		fake = NULL;
		ft_lstdup(garbg, &fake, stack_a);
		qwik_sort(&fake);
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
	fill_stack_a(garbg, stack_a, &stack_b);
	push_a(garbg, stack_a, &stack_b);
}
