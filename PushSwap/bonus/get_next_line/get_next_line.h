/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:59:34 by aahlyel           #+#    #+#             */
/*   Updated: 2023/01/23 01:32:35 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
// # include "../libtools/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char	*get_next_line(int fd);
char	*ft_strfreejoin(char *s1, char *s2);
int		ft_memchr_ind(char *str, char c);
size_t	ft_strlen_util(const char *s);
char	*ft_strdup_util(const char *s1);
char	*ft_read(int fd);
char	*ft_line(char *line);
char	*ft_hold(char *line);

#endif
