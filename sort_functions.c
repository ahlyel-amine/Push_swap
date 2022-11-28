#include "push_swap.h"
#include <stdio.h>

void	get_lis(t_lst *list, int ac);
// LIS <=> Longest Increasing Subsequence
void	ft_sort(t_lst *list, int ac)
{
	t_lst	*head;

	head = list;
	get_lis(list, ac - 1);
	// get_parsed(list, ac - 1);
	while (--ac)
	{
		printf("[%lld]\n", list->LIS);
		list = list->next;
	}
	list = head;
}

int	max(int nbr1, int nbr2)
{
	if (nbr1 > nbr2)
		return (nbr1);
	return (nbr2);
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
			{
				tmp->LIS = max(tmp->LIS, list->LIS + 1);
			}
			list = list->next;
			j++;
		}
		i++;
	}
}

void	get_parsed(t_lst *list, int ac)
{
	t_lst *head;
	t_lst *tmp;
	int	zero;
	int	i;
	int	j;

	i = 0;
	j = 1;
	head = list;
	tmp = list;
	while (i < ac)
	{
		while (tmp->LIS != i + 1)
			tmp = tmp->next;

		if ()
		i++;
	}
}
