/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 23:31:53 by aahlyel           #+#    #+#             */
/*   Updated: 2023/01/17 16:50:43 by aahlyel          ###   ########.fr       */
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

long long	ft_atolld(char **str)
{
	long long	sign;
	long long	res;

	sign = 1;
	res = 0;
	while (**str == 0x20 || (**str >= 0x09 && **str <= 0x0d))
		(*str)++;
	if (**str == 0x2D || **str == 0x2B)
		if (*((*str)++) == 0x2D)
			sign = -1;
	while (**str && ft_isdigit(**str))
		res = (res * 10) + *((*str)++) - 0x30;
	return (res * sign);
}

int	still_digits(char *str)
{
	while (*str)
	{
		if (ft_isdigit(*str))
			return (1);
		str++;
	}
	return (0);
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
