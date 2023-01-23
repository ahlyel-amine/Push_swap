/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:39:46 by aahlyel           #+#    #+#             */
/*   Updated: 2023/01/23 01:38:48 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_memchr_ind(char *str, char c)
{
	int	count;

	if (!str)
		return (-1);
	count = 0;
	while (str[count])
	{
		if (str[count] == c)
			return (count);
		count++;
	}
	return (-1);
}

size_t	ft_strlen_util(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strfreejoin(char *s1, char *s2)
{
	char	*str;
	int		s1_len;
	int		s2_len;
	int		count;

	count = -1;
	if (!s1)
	{
		s1 = ft_strdup_util("");
		if (!s1)
			return (NULL);
	}
	s1_len = ft_strlen_util(s1);
	s2_len = ft_strlen_util(s2);
	str = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (++count < s1_len)
		str[count] = s1[count];
	count = -1;
	while (++count + s1_len < s2_len + s1_len)
		str[s1_len + count] = s2[count];
	str[s1_len + s2_len] = 0;
	return (free(s1), str);
}

char	*ft_strdup_util(const char *s1)
{
	char	*dst;
	int		count;

	count = -1;
	dst = (char *)malloc((ft_strlen_util(s1) + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	while (*(char *)(s1 + ++count))
		*(dst + count) = *(char *)(s1 + count);
	*(dst + count) = (char)0;
	return (dst);
}
