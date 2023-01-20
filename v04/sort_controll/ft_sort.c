/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 20:57:59 by aahlyel           #+#    #+#             */
/*   Updated: 2023/01/20 18:06:29 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	sort_help(t_fakelst *fake, t_stack *a,  t_stack *b, t_list **garbg)
{
	if (a->stack->content <= fake->fake_sm->stack->content)
		push_b(garbg, b, a);
	else if (a->stack->content <= fake->fake_bg->stack->content)
	{
		push_b(garbg, b, a);
		if (b->lenght >= 2)
			rotate_b(b, 1);
	}
	else
		rotate_a(a, 1);
}

void	check_maxb(t_stack *stack)
{
	t_lst		*tmp;
	long long	mx;
	int			i;

	i = 0;
	tmp = stack->stack;
	mx = tmp->content;
	while (i++ < stack->lenght)
	{
		mx = max(mx, tmp->content);
		tmp = tmp->next;
	}
	tmp = stack->stack;
	i = 0;
	while (i++ < stack->lenght)
	{
		if (tmp->content == mx)
			tmp->parse_it = 1;
		tmp = tmp->next;
	}
}

int	wich_half(t_stack *stack)
{
	t_lst	*tmp;
	int		i;

	i = 0;
	tmp = stack->stack;
	while (i < stack->lenght)
	{
		if (tmp->LIS)
			break ;
		i++;
	}
	if (i <= stack->lenght / 2)
		return (1);
	else
		return (0);
}

void	fill_stack_a(t_list **garbg, t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	while (a->lenght > 1)
	{
		check_maxb(b);
		if (wich_half(b))
			while (!b->stack->parse_it)
				rotate_b(b, 1);
		else
			while (!b->stack->parse_it)
				reverse_b(b, 1);
		if (b->stack->LIS)
			push_a(garbg, a, b);
	}
}

void	ft_sort(t_list **garbg, t_stack *a)
{
	t_stack		*b;
	t_fakelst	*fake;

	b->stack = NULL;
	while (a->lenght > 1)
	{
		ft_lstdup(garbg, fake->fake_bg, a);
		qwick_sort(fake->fake_bg);
		fake->fake_sm = fake->fake_bg;
		fake->bg = a->lenght / 8;
		fake->sm = a->lenght / 9 / 2;
		while (fake->bg--)
			fake->fake_bg->stack = fake->fake_bg->stack->next;
		while (fake->sm--)
			fake->fake_sm->stack = fake->fake_sm->stack->next;
		sort_help(fake, a, b, garbg);
	}
	fill_stack_a(garbg, a, b);
	push_a(garbg, a, b);
}
