/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comb_controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:44:21 by aahlyel           #+#    #+#             */
/*   Updated: 2022/12/02 18:32:21 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_comb_controll(t_lst **stack_a, t_lst **stack_b, t_len lenght)
{
	t_lst	*dup_a;
	t_lst	*dup_b;

	dup_b = NULL;
	dup_a = NULL;
	ft_lstdup(&dup_a, *stack_a, lenght.stack_a);
	ft_lstdup(&dup_b, *stack_b, lenght.stack_b);
	get_combs_front(&dup_a, &dup_b, lenght);
	print_stack(dup_a ,dup_b, lenght);
}

void	get_combs_front(t_lst **dup_a, t_lst **dup_b, t_len length)
{
	t_lst	*head_a;
	t_lst	*head_b;
	int		i;
	int		j;
	int		tmp;

	i = 0;
	j = 0;
	head_a = *dup_a;
	head_b = *dup_b;
	ft_calcul(dup_a, dup_b, length);

	// while (i < length.stack_b)
	// {
	// 	(*dup_b)->parse_it += i;
	// 	j = 0;
	// 	(*dup_a) = head_a;
	// 	while (j++ < length.stack_a)
	// 	{
	// 		tmp = combs_conditions(*dup_a, *dup_b);
	// 		if (tmp)
	// 		{
	// 			(*dup_b)->parse_it += tmp;
	// 			break ;
	// 		}
	// 		rotate(dup_b);
	// 	}
	// 	*dup_b = (*dup_b)->next;
	// 	i++;
	// }
}

int	combs_conditions(t_lst *dup_a, t_lst *dup_b)
{
	if (be_first_comb(dup_a, dup_b))
		return (1);
	else if (be_second_last_comb(dup_a, dup_b))
		return (2);
	return (0);
}

int	be_second_last_comb(t_lst *dup_a, t_lst *dup_b)
{
	if (dup_b->content > (dup_a->prev)->content
	|| (dup_b->content > dup_a->content
	&& dup_b->content < (dup_a->next)->content))
		return (2);
	return (0);
}

int	be_first_comb(t_lst *dup_a, t_lst *dup_b)
{
	if (dup_b->content < dup_a->content)
		return (1);
	return (0);
}
