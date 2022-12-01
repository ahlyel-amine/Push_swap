/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 03:26:42 by aahlyel           #+#    #+#             */
/*   Updated: 2022/12/01 23:55:36 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	word_count(char *s, char c);
static int	alloc_fill_strs(char **splited, char *s, char c, int wc);

char	**ft_split_count(char const *s, char c, int *count)
{
	char	**splited;
	int		wc;

	if (!s)
		return (NULL);
	wc = word_count((char *)s, c);
	*count = wc;
	splited = malloc((wc + 1) * sizeof(char *));
	if (!splited)
		return (NULL);
	if (alloc_fill_strs(splited, (char *)s, c, wc))
	{
		while (*splited)
			free(*splited++);
		free(splited);
	}
	return (splited);
}

static int	alloc_fill_strs(char **splited, char *s, char c, int wc)
{
	int	tmp_count;

	while (wc--)
	{
		tmp_count = 0;
		while (*s == c)
			s++;
		while (*(s + tmp_count) != c && *(s + tmp_count))
			tmp_count++;
		if (!tmp_count)
			break ;
		*splited = ft_substr(s, 0, tmp_count);
		if (!splited)
			return (1);
		s += tmp_count;
		splited++;
	}
	*splited = NULL;
	return (0);
}

static int	word_count(char *s, char c)
{
	int	i;

	i = 0;
	while (*(s++))
		if (*(s - 1) != c && (*s == c || !*s))
			i++;
	return (i);
}
