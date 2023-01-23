/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_garbg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:55:09 by aahlyel           #+#    #+#             */
/*   Updated: 2023/01/23 20:40:17 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static int	word_count(char *s, char c);
static void	alloc_fill_strs(char **splited, char *s, char c, int wc, t_list **garbg);

char	**ft_split_garbg(char const *s, char c, t_list **garbg)
{
	char	**splited;
	int		wc;

	if (!s)
		return (NULL);
	wc = word_count((char *)s, c);
	splited = ft_malloc(malloc((wc + 1) * sizeof(char *)), garbg);
	alloc_fill_strs(splited, (char *)s, c, wc, garbg);
	return (splited);
}

static void	alloc_fill_strs(char **splited, char *s, char c, int wc, t_list **garbg)
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
		*splited = ft_malloc(ft_substr(s, 0, tmp_count), garbg);
		s += tmp_count;
		splited++;
	}
	*splited = NULL;
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
