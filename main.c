

// #include <stdarg.h>
// #include <unistd.h>
// #include <string.h>
// #include <stdlib.h>
#include <stdio.h>
#include "libft.h"

// int	ft_isdigit(int c)
// {
// 	return (c >= 0x30 && c <= 0x39);
// }



// char	*ft_strtrim(char const *s1, char const *set)
// {
// 	int	n;

// 	if (!s1)
// 		return (NULL);
// 	if (!set || !*set)
// 		return (ft_strdup(s1));
// 	while (*s1 && ft_strchr(set, *s1))
// 		s1++;
// 	n = ft_strlen(s1);
// 	while (n && ft_strchr(set, *(s1 + n - 1)))
// 		n--;
// 	return (ft_substr(s1, 0, n));
// }


int main(int ac, char *av[])
{
	long long c;
	while (still_digits(av[1]))
	{
		c = ft_atolld_demo(&av[1]);
	}
}
// size_t	ft_strlen(const char *s)
// {
// 	const char	*c;

// 	c = s;
// 	while (*c)
// 		c++;
// 	return ((c - s));
// }


// static size_t	chars_nbr(int n);

// char	*ft_itoa(int n)
// {
// 	char		*nbr;
// 	int			chr_count;
// 	long long	tmp;

// 	// if (!n)
// 	// 	return (ft_strdup("0"));
// 	chr_count = chars_nbr(n);
// 	nbr = (char *)calloc(chr_count + 1, sizeof(char));
// 	if (!nbr)
// 		return (NULL);
// 	tmp = n;
// 	if (tmp < 0)
// 		tmp = -tmp;
// 	while (chr_count && tmp)
// 	{
// 		*(nbr + --chr_count) = tmp % 10 + 0x30;
// 		tmp /= 10;
// 	}
// 	if (chr_count)
// 		*nbr = 0x2D;
// 	return (nbr);
// }

// static size_t	chars_nbr(int n)
// {
// 	size_t	s;

// 	s = 0;
// 	if (n < 0)
// 		s++;
// 	while (n != 0 && ++s)
// 		n /= 10;
// 	return (s);
// }

// int ft_printf(const char *s, ...)
// {
// 	va_list ap;
// 	int count = 0;
// 	char *tmp = NULL;

// 	va_start(ap, s);
// 	while (*s)
// 	{
// 		if (*s != '%')
// 		{
// 			count += write(1, &s[0], 1);
// 			s++;
// 		}
// 		if (*s == '%')
// 		{
// 			if (*(s + 1) == 'd')
// 			{
// 				tmp = ft_itoa(va_arg(ap, int));
// 				count += write(1, tmp ,ft_strlen(tmp));
// 			}
// 			s += 2;
// 		}
// 	}
// 	return (count);
// }

// int main()
// {
// 	ft_printf("test %d str%ding",45, 96);
// }
