/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_controller.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 23:36:10 by aahlyel           #+#    #+#             */
/*   Updated: 2023/01/17 15:45:27 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_table(t_lst **stack, char **av, int ac)
{
	int			i;
	int			j;

	*stack = NULL;
	i = 0;
	j = 0;
	if (!ft_check_input_digits(av, ac))
		return (write(STDERR_FILENO, "Error",
		ft_strlen("Error")), -1);
	while (i < ac)
	{
		while (still_digits(av[i]))
		{
			new_node(stack, ft_atolld(&av[i]), 0);
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
	long long	i;
	long long	j;

	i = -1;
	while (++i < ac)
	{
		j = -1;
		while (av[i][++j])
		{
			if (av[i][j] == '-' && !ft_isdigit(av[i][j + 1]))
				return (0);
			if (av[i][j] == '-')
				j++;
			if (!ft_isdigit(av[i][j]) && av[i][j] != ' ' && av[i][j])
				return (0);
		}
	}
	return (1);
}

int	ft_check_input_dup(t_lst *stack, int ac)
{
	t_lst 		*tmp;
	long long	i;
	long long	j;

	i = 0;
	j = 0;
	while (i++ < ac)
	{
		tmp = stack->next;
		// if (stack->content > INT_MAX || stack->content < INT_MIN)
		// 	return (0);
		while (++j < ac)
		{
			if (tmp->content == stack->content)
				return (0);
			tmp = tmp->next;
		}
		stack = stack->next;
	}
	return (1);
}