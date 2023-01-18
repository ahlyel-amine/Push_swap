/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_controll.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:48:51 by aahlyel           #+#    #+#             */
/*   Updated: 2023/01/18 21:10:54 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

void	new_node(t_list **garbg, t_lst **head, long long nbr, int ind)
{
	t_lst	*new;

	new = ft_malloc(malloc(sizeof(t_lst)), garbg);
	new->content = nbr;
	new->front = INT_MAX;
	new->back = INT_MAX;
	new->LIS = 1;
	new->parse_it = 0;
	new->parse_it_back = 0;
	if (!(*head))
	{
		*head = new;
		new->next = new;
		new->prev = new;
		new->lenght.stack_len = 1;
	}
	else
	{
		new->next = *head;
		new->lenght.stack_len = (*head)->lenght.stack_len;
		new->prev = (*head)->prev;
		((*head)->prev)->next = new;
		(*head)->prev = new;
		set_list_lenght(head, 1);
		if (ind)
			*head = new;
	}
}

void	set_list_lenght(t_lst **stack, int ref)
{
	t_lst	*tmp_stack;
	int		tmp;
	int		i;

	tmp_stack = *stack;
	tmp = tmp_stack->lenght.stack_len;
	i = 0;
	while (i++ < tmp + ref)
	{
		(*stack)->lenght.stack_len = tmp + ref;
		(*stack) = (*stack)->next;
	}
	*stack = tmp_stack;
}

void	del_node(t_lst **head)
{
	if ((*head)->next == *head)
	{
		*head = NULL;
		return ;
	}
	((*head)->next)->prev = (*head)->prev;
	((*head)->prev)->next = (*head)->next;
	(*head) = (*head)->next;
	set_list_lenght(head, -1);
}
