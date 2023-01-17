/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:53:47 by aahlyel           #+#    #+#             */
/*   Updated: 2023/01/17 20:36:56 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

int	ft_parse(t_list **garbg, t_lst **stack, char **av, int ac)
{
	ft_check_syntax(garbg, av, ac);
	
}

void	ft_check_syntax(t_list **garbg, char **av, int ac)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (++i < ac)
	{
		j = -1;
		while (av[i][++j])
		{
			if (ft_issign(av[i][j]) && !ft_isdigit(av[i][j + 1]))
				ft_exit("Syntax error", garbg);
			while (av[i][j] == ' ')
				j++;
			if (ft_issign(av[i][j]))
				j++;
			if (av[i][j] && !ft_isdigit(av[i][j]))
				ft_exit("Syntax error", garbg);
		}
	}
}
