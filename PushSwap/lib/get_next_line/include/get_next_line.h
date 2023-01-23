/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:59:34 by aahlyel           #+#    #+#             */
/*   Updated: 2022/11/26 23:48:00 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_strfreejoin(char *s1, char *s2);
int		ft_memchr_ind(char *str, char c);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_read(int fd);
char	*ft_line(char *line);
char	*ft_hold(char *line);

#endif
