/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack_for_debuging.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 22:45:01 by aahlyel           #+#    #+#             */
/*   Updated: 2023/01/27 16:22:00 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void    print_stack(t_stack *tmp, t_stack *tmp1)
{
	int		i;
	int		j;
	int		len_a = 0;
	int		len_b = 0;

	i = 0;
	if (!tmp && !tmp1)
		printf("lol\n");
	if (tmp && tmp->stack)
		len_a = tmp->lenght;
	if (tmp1 && tmp1->stack)
		len_b = tmp1->lenght;
	j = 0;
	printf("~|stack A|~\t\t\t~|stack B|~\n");
	printf("-~-~-~-~--~-~-~-~--~-~-~-~--~-~-~-~-~-~-~-~--~-~-~-~--~-~-~-~--~-~-~-~-\n");
	if (!tmp && !tmp1)
	 printf("	|the stacks holder have been //freed|\n");
	if (!tmp->stack && !tmp1->stack)
	 printf("	|the stacks have been //freed|\n");
	while (i < len_a || j < len_b)
	{
		if (tmp && tmp->stack && i < len_a)
		{
			printf("a\t|%lld|\t<",tmp->stack->content);
			tmp->stack = tmp->stack->next;
		}
		else
			printf("\t\t");
		if (tmp1 && tmp1->stack && j < len_b)
		{
			printf("\t>\t|%lld|\tb",tmp1->stack->content);
			tmp1->stack = tmp1->stack->next;
		}
		i++;
		j++;
		printf("\n");
	}
	printf("-~-~-~-~--~-~-~-~--~-~-~-~--~-~-~-~-~-~-~-~--~-~-~-~--~-~-~-~--~-~-~-~-\n");
}
