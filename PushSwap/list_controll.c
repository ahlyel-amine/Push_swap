/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_controll.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:48:51 by aahlyel           #+#    #+#             */
/*   Updated: 2023/01/22 16:47:08 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

void	new_node(t_list **garbg, t_stack *head, long long nbr, int ind)
{
	t_lst	*new;

	new = ft_malloc(malloc(sizeof(t_lst)), garbg);
	new->content = nbr;
	new->LIS = 1;
	new->parse_it = 0;
	if (!(head)->stack)
	{
		(head)->stack = new;
		new->next = new;
		new->prev = new;
		(head)->lenght = 1;
	}
	else
	{
		new->next = (head)->stack;
		new->prev = (head)->stack->prev;
		((head)->stack->prev)->next = new;
		(head)->stack->prev = new;
		(head)->lenght++;
		if (ind)
			(head)->stack = new;
	}
}

void	ft_lstdup(t_list **garbg, t_stack *fake, t_stack *head)
{
	int	i;

	i = 0;
	while (i++ < head->lenght)
	{
		new_node(garbg, fake, (head)->stack->content, 0);
		(head)->stack = (head)->stack->next;
	}
}

void	del_node(t_stack *head)
{
	if ((head)->stack->next == head->stack)
	{
		head->stack = NULL;
		return ;
	}
	((head)->stack->next)->prev = (head)->stack->prev;
	((head)->stack->prev)->next = (head)->stack->next;
	(head)->stack = (head)->stack->next;
	head->lenght--;
}
