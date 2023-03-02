/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_garbg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:55:09 by aahlyel           #+#    #+#             */
/*   Updated: 2023/03/02 15:15:47 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static int	word_count(char *s, char c, t_list **garb);

char	**ft_split_garbg(char const *s, char c, t_list **garbg)
{
	char	**splited;
	int		wc;
	int		i;
	int		tmp_count;

	if (!s)
		return (NULL);
	i = 0;
	wc = word_count((char *)s, c, garbg);
	splited = ft_malloc(malloc((wc + 1) * sizeof(char *)), garbg);
	while (i < wc)
	{
		tmp_count = 0;
		while (*s == c)
			s++;
		while (*(s + tmp_count) != c && *(s + tmp_count))
			tmp_count++;
		if (!tmp_count)
			break ;
		splited[i] = ft_malloc(ft_substr(s, 0, tmp_count), garbg);
		s += tmp_count;
		i++;
	}
	splited[i] = NULL;
	return (splited);
}

static int	word_count(char *s, char c, t_list **garbg)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[j++])
		if (s[j - 1] != c && (s[j] == c || !s[j]))
			i++;
	if (!i && *s == c)
		ft_exit("Error", garbg, 0);
	return (i);
}
