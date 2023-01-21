/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:53:47 by aahlyel           #+#    #+#             */
/*   Updated: 2023/01/21 18:40:51 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

int	ft_parse(t_list **garbg, t_lst **stack, char **av, int ac)
{
	char	**tmp;
	int		i;
	int		j;

	i = 0;
	tmp = NULL;
	while (i < ac)
	{
		j = -1;
		tmp = ft_split_garbg(av[i++], ' ', garbg);
		while (tmp[++j])
			new_node(garbg, stack, ft_atolld(garbg, tmp[j]), 0);
	}
	ft_check_dup(garbg, *stack);
	return 0;
}


void	ft_check_dup(t_list **garbg, t_lst *stack)
{
	t_lst 		*tmp;
	long long	i;
	long long	j;

	i = 0;
	j = 0;
	while (i++ < stack->lenght.stack_len)
	{
		tmp = stack->next;
		while (++j < stack->lenght.stack_len)
		{
			if (tmp->content == stack->content)
				ft_exit("Error number duplicates", garbg);
			tmp = tmp->next;
		}
		stack = stack->next;
	}
}

// void	ft_check_syntax(char **av, int ac)
// {
// 	size_t	i;
// 	size_t	j;

// 	i = -1;
// 	while (++i < ac)
// 	{
// 		j = -1;
// 		while (av[i][++j])
// 		{
// 			if (ft_issign(av[i][j]) && !ft_isdigit(av[i][j + 1]))
// 				ft_exit("Syntax error", NULL);
// 			while (av[i][j] == ' ')
// 				j++;
// 			if (ft_issign(av[i][j]))
// 				j++;
// 			if (av[i][j] && !ft_isdigit(av[i][j]))
// 				ft_exit("Syntax error", NULL);
// 		}
// 	}
// }
