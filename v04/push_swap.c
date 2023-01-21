/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 23:41:55 by aahlyel           #+#    #+#             */
/*   Updated: 2023/01/21 01:53:38 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

int main(int ac, char **av)
{
	t_list		*garbg;
	t_stack		*stack;

	garbg = NULL;
	stack = ft_malloc(malloc(sizeof(t_stack)), &garbg);
	stack->stack = NULL;
	ft_parse(&garbg, stack, ++av, ac - 1);
	ft_sort(&garbg, stack);
	return (0);
}
