/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 20:57:59 by aahlyel           #+#    #+#             */
/*   Updated: 2023/01/21 01:50:58 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	sort_help(t_fakelst *fake, t_stack *a,  t_stack *b, t_list **garbg)
{
	if (a->stack->content <= fake->sm)
		push_b(garbg, b, a);
	else if (a->stack->content <= fake->bg)
	{
		push_b(garbg, b, a);
		if (b->lenght >= 2)
			rotate_b(b, 1);
	}
	else
		rotate_a(a, 1);
}

int	check_maxb(t_stack *stack, long long *max)
{
	t_lst		*tmp;
	int			pos;
	int			i;

	i = 0;
	pos = 0;
	tmp = stack->stack;
	*max = tmp->content;
	while (i < stack->lenght)
	{
		if (tmp->content > *max)
		{
			*max = tmp->content;
			pos = i;
		}
		i++;
		tmp = tmp->next;
	}
	return (pos);
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
	int	max_pos;
	long long	max;

	i = 0;
	while (b && b->lenght > 1)
	{
		max_pos = check_maxb(b , &max);
		if (max_pos <= b->lenght / 2)
			while (max != b->stack->content)
				rotate_b(b, 1);
		else
			while (max != b->stack->content)
				reverse_b(b, 1);
		if (b->stack->content == max)
			push_a(garbg, a, b);
	}
}

void	fill_table(int **table, t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->lenght)
	{
		(*table)[i] = a->stack->content;
		a->stack = a->stack->next;
		i++;
	}
}

void	ft_sort(t_list **garbg, t_stack *a)
{
	t_stack		*b;
	t_fakelst	*fake;
	int			*table;
	int			i;

	i = 0;
	b = ft_malloc(malloc(sizeof(t_stack)), garbg);
	fake = ft_malloc(malloc(sizeof(t_fakelst)), garbg);
	b->stack = NULL;
	while (a->lenght > 1)
	{
		table = NULL;
		table = ft_malloc(malloc(a->lenght * sizeof(int)), garbg);
		fill_table(&table, a);
		qwick_sort(&table, a->lenght);
		fake->bg = table[a->lenght / 8];
		fake->sm =  table[(a->lenght / 9) / 2];
		sort_help(fake, a, b, garbg);
	}
	fill_stack_a(garbg, a, b);
	if (b->lenght)
		push_a(garbg, a, b);
}
