/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 23:31:53 by aahlyel           #+#    #+#             */
/*   Updated: 2023/01/19 16:59:54 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	ft_exit(char *error_msg, t_list **garbg)
{
	if (garbg)
		ft_lstclear(garbg, free);
	if (errno)
		perror(error_msg);
	else
		ft_putendl_fd(error_msg, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	*ft_malloc(void *pointer, t_list **garbg)
{
	t_list	*new;

	new = NULL;
	if (!pointer)
		ft_exit("Allocation failure", garbg);
	new = ft_lstnew(pointer);
	if (!new)
	{
		free(pointer);
		ft_exit("Allocation failure", garbg);
	}
	ft_lstadd_back(garbg, new);
	return (pointer);
}

long long	ft_atolld(t_list **garbg, char *str)
{
	long long	sign;
	long long	res;

	sign = 1;
	res = 0;

	if (ft_issign(*str))
		if (*((str)++) == '-')
			sign = -1;
	if (!ft_isdigit(*str))
		ft_exit("Syntax error", garbg);
	while (*str && ft_isdigit(*str))
		res = (res * 10) + *((str)++) - '0';
	if (*str)
		ft_exit("Syntax error", garbg);
	check_min_max(garbg, res * sign);
	return (res * sign);
}

int			still_digits(char *str)
{
	return 0;
}

void	check_min_max(t_list **garbg, long long nbr)
{
	if (nbr > INT_MAX || nbr < INT_MIN)
		ft_exit("Syntax error", garbg);
}

int	min(int nbr1, int nbr2)
{
	if (nbr1 < nbr2)
		return (nbr1);
	return (nbr2);
}

int	max(int nbr1, int nbr2)
{
	if (nbr1 > nbr2)
		return (nbr1);
	return (nbr2);
}

int	ft_issign(char c)
{
	return (c == '-' || c == '+');
}
