#include "push_swap.h"
#include <stdio.h>

void	get_lis(t_lst *list, int ac);
void	get_parsed(t_lst *list, int ac, int max_lis);
int	get_mac_lis(t_lst *list, int ac);

// LIS <=> Longest Increasing Subsequence

void	ft_sort(t_lst *list, int ac)
{
	t_lst
	int	max_lis;

	get_lis(list, ac - 1);
	max_lis = get_mac_lis(list, ac);
	get_parsed(list, ac - 1, max_lis);

	while (--ac)
	{
		printf("%lld : [%lld] (%lld)\n", list->LIS, list->content, list->parse_it);
		list = list->next;
	}
}


int	max(int nbr1, int nbr2)
{
	if (nbr1 > nbr2)
		return (nbr1);
	return (nbr2);
}

int	get_mac_lis(t_lst *list, int ac)
{
	int max_lis;
	int	i;

	max_lis = 1;
	i = 0;
	while (i++ < ac)
	{
		max_lis = max(max_lis, list->LIS);
		list = list->next;
	}
	return (max_lis);
}

int	min(int nbr1, int nbr2)
{
	if (nbr1 > nbr2)
		return (nbr2);
	return (nbr1);
}

void	get_lis(t_lst *list, int ac)
{
	t_lst *head;
	t_lst *tmp;
	int	zero;
	int	i;
	int	j;

	i = 1;
	head = list;
	while (i < ac)
	{
		zero = 0;
		j = 0;
		list = head;
		tmp = list;
		while (zero++ < i)
			tmp = tmp->next;
		while (j < i)
		{
			if (tmp->content > list->content)
				tmp->LIS = max(tmp->LIS, list->LIS + 1);
			list = list->next;
			j++;
		}
		i++;
	}
}

void	get_parsed(t_lst *list, int ac, int max_lis)
{
	t_lst *head;
	t_lst *tmp;
	int	zero;
	int	i;
	int	j;

	i = 0;
	j = 1;
	head = list;
	while (i < ac)
	{
		list = head;
		zero = 0;
		tmp = head;
		while (list->LIS != j && j < max_lis + 1)
		{
			list = list->next;
			if (list->LIS == j)
				break ;
		}
		tmp = list->next;
		while (zero++ < ac)
		{
			if (tmp->LIS == j && list->content > tmp->content)
				list = tmp;
			tmp = tmp->next;
		}
		if (list->LIS == j)
			list->parse_it = 0;
		j++;
		i++;
	}
}
