/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 21:20:06 by aahlyel           #+#    #+#             */
/*   Updated: 2023/01/22 22:14:38 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	qwik_sort(t_lst **fake)
{
	t_lst		*n_fake;
	long long	tmp;
	int			i;
	int			j;

	i = 0;
	while (i < (*fake)->lenght.stack_len)
	{
		j = i + 1;
		n_fake = (*fake)->next;
		while (j++ < (*fake)->lenght.stack_len)
		{
			if (n_fake->content < (*fake)->content)
			{
				tmp = n_fake->content;
				n_fake->content = (*fake)->content;
				(*fake)->content = tmp;
			}
			n_fake = n_fake->next;
		}
		(*fake) = (*fake)->next;
		i++;
	}
}
