#include "push_swap.h"
#include "libft.h"

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
		table[i] = ft_latoi(av[i + 1]);
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


long long	*test(char **str, int ac)
{
	long long	*table;

	table = ft_convert(ac, str);
	if (!table)
		return (free(table), NULL);
	if (!ft_check_digits(ac, str) || !ft_check_duplicate(ac, table))
		return (free(table), write(1, "Error", ft_strlen("Error")), NULL);
	return (table);
}

int main(int ac, char *av[])
{
	long long	*table;
	t_lst		*head;
	char		**tmp;

	head = NULL;
	table = NULL;
	if (ac == 2)
	{
		tmp = ft_split_count(av[1], ' ', &ac);
		if (!tmp)
			return (-1);
		table = test(tmp, ac + 1);
		if (!table)
			return (free(tmp), -1);
		free(tmp);
	}
	else
	{
		table = test(av + 1, ac);
			if (!table)
				return (-1);
	}
	ft_listing(&head, table, ac);
	
	return 0;
}
