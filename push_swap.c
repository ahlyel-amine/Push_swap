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
int main(int ac, char *av[])
{
	long long	*table;
	t_lst		*head;

	head = NULL;table = NULL;
	table = ft_convert(ac, av);
	if (!table)
		return (free(table), -1);
	// if (!ft_check_duplicate(ac, table))
	// 	return (free(table), write(1, "ft_check_duplicate_Error", ft_strlen("ft_check_duplicate_Error")), -1);
	// else if (!ft_check_digits(ac, av))
	// 	return (free(table), write(1, "check_digits_Error", ft_strlen("check_digits_Error")), -1);
	if (!ft_check_digits(ac, av) || !ft_check_duplicate(ac, table))
		return (free(table), write(1, "Error", ft_strlen("Error")), -1);
	ft_listing(&head, table, ac);

	return 0;
}
