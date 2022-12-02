/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_comb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:48:14 by aahlyel           #+#    #+#             */
/*   Updated: 2022/12/02 19:30:14 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_calcul(t_lst *stack_a, t_lst *stack_b, t_len length);
void	ft_comb_front(t_lst **stack_a, t_lst **stack_b, t_len length);
int		get_min_comb(t_lst *stack, int len);
void	get_sorted(t_lst **stack_a, t_lst **stack_b, t_len length);

void	ft_calcul_comb(t_lst **stack_a, t_lst **stack_b, t_len length) //in work
{
	t_lst	*dup_a;
	t_lst	*dup_b;

	dup_b = NULL;
	dup_a = NULL;

	ft_lstdup(&dup_a, *stack_a, length.stack_a);
	ft_lstdup(&dup_b, *stack_b, length.stack_b);
	ft_calcul(dup_a, dup_b, length);
	print_stack(dup_a ,dup_b, length);

}

void	ft_calcul(t_lst *stack_a, t_lst *stack_b, t_len length)
{
	int	i;

	i = 0;
	// while (i++ < length.stack_b)
	// {
		ft_comb_front(&stack_a, &stack_b, length);

		length.min = get_min_comb(stack_b, length.stack_b);
		// get_sorted(&stack_a, &stack_b, length);
	// }
}

// void	get_sorted(t_lst **stack_a, t_lst **stack_b, t_len length)
// {
// 	int i = 0;


// }

int	get_min_comb(t_lst *stack, int len)
{
	t_lst	*tmp;
	int	i;
	int	mn;

	i = 0;
	mn = 1;
	while (i++ < len)
	{
		mn = min(mn, stack->parse_it);
		stack = stack->next;
	}
	return (mn);
}


void	ft_comb_front(t_lst **stack_a, t_lst **stack_b, t_len length)
{
	t_lst	*head_a;
	t_lst	*head_b;
	int		i;
	int		j;
	int		count;

	i = 0;
	j = 0;
	head_a = *stack_a;
	head_b = *stack_b;
	while (i < length.stack_b)
	{
		(*stack_b)->parse_it += i;
		j = 0;
		*stack_a = head_a;
		while (j++ < length.stack_a)
		{
			if ((*stack_b)->content < (*stack_a)->content)
			{
				((*stack_b)->parse_it)++;
				break ;
			}
			else if (((*stack_b)->content > ((*stack_a)->prev)->content)
			|| ((*stack_b)->content > (*stack_a)->content
			&& (*stack_b)->content < ((*stack_a)->next)->content))
			{
				((*stack_b)->parse_it) += 2;
				break ;
			}
			rotate(stack_a);
		}
		(*stack_b) = (*stack_b)->next;
		i++;
	}
	(*stack_a) = head_a;
	(*stack_b) = head_b;
}

void	ft_comb_back(t_lst **stack_a, t_lst **stack_b, t_len length)
{
	t_lst	*head_a;
	t_lst	*head_b;
	int		i;
	int		j;
	int		count;

	i = 0;
	j = 0;
	head_a = *stack_a;
	head_b = *stack_b;
	while (i < length.stack_b)
	{
		(*stack_b)->parse_it += i;
		j = 0;
		*stack_a = head_a;
		while (j++ < length.stack_a)
		{
			if ((*stack_b)->content < (*stack_a)->content)
			{
				((*stack_b)->parse_it)++;
				break ;
			}
			else if (((*stack_b)->content > ((*stack_a)->prev)->content)
			|| ((*stack_b)->content > (*stack_a)->content
			&& (*stack_b)->content < ((*stack_a)->next)->content))
			{
				((*stack_b)->parse_it) += 2;
				break ;
			}
			rotate(stack_a);
		}
		(*stack_b) = (*stack_b)->next;
		i++;
	}
	(*stack_a) = head_a;
	(*stack_b) = head_b;
}
