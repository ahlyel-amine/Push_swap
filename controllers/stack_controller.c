/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_controller.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:50:24 by aahlyel           #+#    #+#             */
/*   Updated: 2022/12/02 12:39:56 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    print_stack(t_lst *sa, t_lst *sb, t_len lenght)
{
    t_lst	*tmp;
    t_lst	*tmp1;
	int		i;
	int		j;

    tmp = sa;
    tmp1 = sb;
	i = 0;
	j = 0;
    printf("~|stack A|~\t\t\t~|stack B|~\n");
    printf("-~-~-~-~--~-~-~-~--~-~-~-~--~-~-~-~-~-~-~-~--~-~-~-~--~-~-~-~--~-~-~-~-\n");
    if (!tmp && !tmp1)
        printf("    |the stacks have been freed|\n");
    while (i < lenght.stack_a || j < lenght.stack_b)
    {
        if (i++ < lenght.stack_a)
        {
            printf("a|%lld| |%lld|\t|%lld|<", tmp->LIS, tmp->content, tmp->parse_it);
            tmp = tmp->next;
        }
		else
		printf("\t\t");
        if (j++ < lenght.stack_b)
        {
            printf("\t\t>|%lld| |%lld|\t|%lld|b", tmp1->LIS, tmp1->content, tmp1->parse_it);
            tmp1 = tmp1->next;
        }
        printf("\n");
    }
    printf("-~-~-~-~--~-~-~-~--~-~-~-~--~-~-~-~-~-~-~-~--~-~-~-~--~-~-~-~--~-~-~-~-\n");
}
