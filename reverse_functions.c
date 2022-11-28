/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:53:03 by aahlyel           #+#    #+#             */
/*   Updated: 2022/11/28 16:53:44 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse(t_lst **stack)
{
	*stack = (*stack)->prev;
}

void	rrr(t_lst **stack_a, t_lst **stack_b)
{
	reverse(stack_a);
	reverse(stack_b);
}
