/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:53:47 by aahlyel           #+#    #+#             */
/*   Updated: 2023/01/24 05:27:51 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

int	ft_parse(t_list **garbg, t_stack *stack, char **av, int ac)
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
	ft_check_dup(garbg, stack);
	return (0);
}

void	ft_check_dup(t_list **garbg, t_stack *stack)
{
	t_lst		*tmp;
	long long	i;
	long long	j;

	i = 0;
	j = 0;
	while (i++ < stack->lenght)
	{
		j = i;
		tmp = stack->stack->next;
		while (j++ < stack->lenght)
		{
			if (tmp->content == stack->stack->content)
				ft_exit("Error", garbg, 0, 0);
			tmp = tmp->next;
		}
		stack->stack = stack->stack->next;
	}
}

void	check_args(t_list **garbg, char *arg)
{
	if (ft_strncmp(arg, "ra\n", 3)
		&& ft_strncmp(arg, "rb\n", 3)
		&& ft_strncmp(arg, "rr\n", 3)
		&& ft_strncmp(arg, "pa\n", 3)
		&& ft_strncmp(arg, "pb\n", 3)
		&& ft_strncmp(arg, "sa\n", 3)
		&& ft_strncmp(arg, "sb\n", 3)
		&& ft_strncmp(arg, "ss\n", 3)
		&& ft_strncmp(arg, "rra\n", 4)
		&& ft_strncmp(arg, "rrb\n", 4)
		&& ft_strncmp(arg, "rrr\n", 4))
		ft_exit("Error", garbg, 0, 0);
}

void	read_args(t_list **garbg, t_list **instractions)
{
	char	*reader;

	reader = NULL;
	reader = get_next_line(STDIN_FILENO, garbg);
	if (reader)
		check_args(garbg, reader);
	while (reader)
	{
		ft_lstadd_back(instractions, ft_malloc(ft_lstnew(reader), garbg));
		reader = get_next_line(STDIN_FILENO, garbg);
		if (reader)
			check_args(garbg, reader);
	}
}
