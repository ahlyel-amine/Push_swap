#include "push_swap.h"
#include "libft.h"

long long	*ft_convert(int ac, char **av)
{
	long long	*table;
	int			i;

	i = -1;
	table = malloc(ac * sizeof(long long));
	if (!table)
		return (NULL);
	while (av[1][++i])
		table[i] = ft_atoi(av[i + 1]);
	return (NULL);
}

int main(int ac, char *av[])
{
	long long	*table;
	table = ft_convert(ac, av);
	if (!table)
		return (-1);
	return 0;
}

