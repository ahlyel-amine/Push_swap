/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_controller.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 23:36:10 by aahlyel           #+#    #+#             */
/*   Updated: 2023/01/21 18:40:34 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	ft_table(t_lst **stack, char **av, int ac)
{
	int			i;
	int			j;

	*stack = NULL;
	i = 0;
	j = 0;
	// if (!ft_check_input_digits(av, ac))
	// 	return (write(STDERR_FILENO, "Error",
	// 	ft_strlen("Error")), -1);
	if (!ft_check_input_digits(av, ac))
		ft_exit("Syntax error", NULL, 0);
	while (i < ac)
	{
		while (still_digits(av[i]))
		{
			new_node(stack, ft_atolld(NULL, &av[i]), 0);
			j++;
		}
		i++;
	}
	if (!ft_check_input_dup(*stack, j))
		return (write(2, "Error",
		ft_strlen("Error")), -1);
	return (j);
}

int	ft_check_input_digits(char **av, int ac)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (++i < ac)
	{
		j = -1;
		while (av[i][++j])
		{
			if ((av[i][j] == '-' || av[i][j] == '+') && !ft_isdigit(av[i][j + 1]))
				return (0);
			if (av[i][j] == '-' || av[i][j] == '+')
				j++;
			if (!ft_isdigit(av[i][j]) && av[i][j] != ' ' && av[i][j])
				return (0);
		}
	}
	return (1);
}
