

// #include <stdarg.h>
// #include <unistd.h>
// #include <string.h>
// #include <stdlib.h>

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
