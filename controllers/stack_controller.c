/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_controller.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:50:24 by aahlyel           #+#    #+#             */
/*   Updated: 2022/12/18 14:16:53 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    print_stack(t_lst *tmp, t_lst *tmp1)
{
	int		i;
	int		j;
	int		len_a = 0;
	int		len_b = 0;

	i = 0;
	if (tmp)
		len_a = tmp->lenght.stack_len;
	if (tmp1)
		len_b = tmp1->lenght.stack_len;
	j = 0;
	printf("~|stack A|~\t\t\t~|stack B|~\n");
	printf("-~-~-~-~--~-~-~-~--~-~-~-~--~-~-~-~-~-~-~-~--~-~-~-~--~-~-~-~--~-~-~-~-\n");
	if (!tmp && !tmp1)
	 printf("	|the stacks have been //freed|\n");
	while (i < len_a || j < len_b)
	{
		if (tmp && i < len_a)
		{
			printf("a|%lld|\t|%lld|\t|%lld|%d|<", tmp->LIS, tmp->content, tmp->parse_it, tmp->lenght.stack_len);
			tmp = tmp->next;
		}
		else
			printf("\t\t");
		if (tmp1 && j < len_b)
		{
			printf("\t\t>|%lld|\t|%lld|\t|%lld|%d|b", tmp1->LIS, tmp1->content, tmp1->parse_it, tmp1->lenght.stack_len);
			tmp1 = tmp1->next;
		}
		i++;
		j++;
		printf("\n");
	}
	printf("-~-~-~-~--~-~-~-~--~-~-~-~--~-~-~-~-~-~-~-~--~-~-~-~--~-~-~-~--~-~-~-~-\n");
}
