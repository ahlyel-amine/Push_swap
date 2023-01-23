/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 23:41:55 by aahlyel           #+#    #+#             */
/*   Updated: 2023/01/23 20:40:17 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int main(int ac, char **av)
{
	t_list		*garbg;
	t_lst		*head;

	head = NULL;
	garbg = NULL;
	ft_parse(&garbg, &head, ++av, ac - 1);
	ft_sort(&garbg, &head);
	return (0);
}
