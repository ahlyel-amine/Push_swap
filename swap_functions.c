/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:55:33 by aahlyel           #+#    #+#             */
/*   Updated: 2022/11/28 16:55:34 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_lst **head)
{
	long long	nbr;

	nbr = (*head)->content;
	(*head)->content = ((*head)->next)->content;
	((*head)->next)->content = nbr;
}

void	ss(t_lst **head_a, t_lst **head_b)
{
	swap(head_a);
	swap(head_b);
}