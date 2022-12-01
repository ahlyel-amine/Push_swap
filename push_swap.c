#include "push_swap.h"
#include "libft.h"

int	still_digits(char *str);
int	ft_table_demo(t_lst **stack, char **av, int ac);
long long	ft_atolld(char **str);
long long	ft_latoi(const char *str)
{
	long long	sign;
	long long	res;

	sign = 1;
	res = 0;
	while (*str == 0x20 || (*str >= 0x09 && *str <= 0x0d))
		str++;
	if (*str == 0x2D || *str == 0x2B)
		if (*(str++) == 0x2D)
			sign = -1;
	while (*str && ft_isdigit(*str))
		res = (res * 10) + *(str++) - 0x30;

	return (res * sign);
}

long long	*ft_convert(int ac, char **av)
{
	long long	*table;
	int			i;

	i = 0;
	table = malloc(ac * sizeof(long long));
	if (!table)
		return (NULL);
	while (--ac)
	{
		table[i] = ft_latoi(av[i]);
		i++;
	}
	return (table);
}

int	ft_check_digits(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (av[i] && i <= ac)
	{
		j = 0;
		while (av[i][j])
		{
			if ((av[i][j] == '-' || av[i][j] == '+')  && j == 0)
				j++;
			if (av[i][j] && !ft_isdigit(av[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_duplicate(int ac, long long *table)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (table[i] && i < ac)
	{
		j = i + 1;
		while (table[j] && j < ac)
		{
			if (table[i] == table[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
#include <limits.h>


long long	*ft_table(char **str, int ac)
{
	long long	*table;

	table = ft_convert(ac, str);
	if (!table)
		return (free(table), NULL);
	if (!ft_check_digits(ac, str) || !ft_check_duplicate(ac, table))
		return (free(table), write(1, "Error", ft_strlen("Error")), NULL);
	return (table);
}

void	ft_pushswap(t_lst *list, int ac)
{
	// t_lst		*tmp;
	// t_lst		*head;
	// int			count;

	// head = list;
	// count = ac;
	// while (count-- && list)
	// {
	// 	if (count)
	// 		tmp = list->next;
	// 	else
	// 		tmp = NULL;
	// 	if (tmp && list->content > tmp->content)
	// 		ft_sort(head, ac);
	// 	list = list->next;
	// }
	ft_sort(list, ac);
}


int main(int ac, char *av[])
{
	// long long	*table;
	t_lst		*head;
	char		**tmp;

	head = NULL;
	// if (ac == 2)
	// {
	// 	tmp = ft_split_count(av[1], ' ', &ac);
	// 	if (!tmp)
	// 		return (-1);
	// 	table = ft_table(tmp, ++ac);
	// 	free(tmp);
	// 	if (!table)
	// 		return (-1);
	// }
	// else if (ac > 2)
	// {
	// 	table = ft_table(++av, ac);
	// 	if (!table)
	// 		return (-1);
	// }
	if (ac <= 1)
		return (0);
	else
		ac = ft_table_demo(&head, ++av, ac - 1);
	// while (i++ < ac)
	// {
	// 	printf("%lld : [%lld] (%lld) \n",
	// 	 head->LIS, head->content, head->parse_it);
	// 	head = head->next;
	// }
	// else
	// {
	// 	table = ft_table(++av, ac);
	// 	if (!table)
	// 		return (-1);
	// }
	// ft_listing(&head, table, ac);
	ft_pushswap(head, ac);
	return (0);
}

int	ft_table_demo(t_lst **stack, char **av, int ac)
{
	int			i;
	int			j;

	*stack = NULL;
	i = 0;
	j = 0;
	while (i < ac)
	{
		while (still_digits(av[i]))
		{
			new_node(stack, ft_atolld(&av[i]));
			j++;
		}
		i++;
	}
	return (j);
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
