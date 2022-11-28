/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:47:23 by aahlyel           #+#    #+#             */
/*   Updated: 2022/11/28 16:52:23 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_lst **stack)
{
	*stack = (*stack)->next;
}

void	rr(t_lst **stack_a, t_lst **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}
