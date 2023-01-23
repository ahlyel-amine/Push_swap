/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 21:05:34 by aahlyel           #+#    #+#             */
/*   Updated: 2023/01/23 22:45:57 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/libft/include/libft.h"
# include <sys/errno.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_lst
{
	long long		content;
	long long		parse_it;
	struct s_lst	*next;
	struct s_lst	*prev;
}	t_lst;

typedef struct s_stack
{
	t_lst	*stack;
	int		lenght;
}	t_stack;

typedef struct s_fakelst
{
	t_stack			*stack;
	int				*table;
	long long		bg;
	long long		sm;
}	t_fakelst;

void														print_stack(t_stack *tmp, t_stack *tmp1); // for testiiiiiiing

/// @brief
/// @param garbg
/// @param a
void		big_sort(t_list **garbg, t_stack *a);

/// @brief
/// @param garbg
/// @param a
void		low_sort(t_list **garbg, t_stack *a, t_stack *b);

/// @brief
/// @param garbg
/// @param a
void		sort_3digits(t_stack *a);

/// @brief
/// @param garbg
/// @param a
void		sort_check(t_list **garbg, t_stack *a);

/// @brief
/// @param error_msg
/// @param garbg
void		ft_exit(char *error_msg, t_list **garbg, int status);

/// @brief
/// @param pointer
/// @param garbg
/// @return
void		*ft_malloc(void *pointer, t_list **garbg);

/// @brief
/// @param garbg
/// @param stack
/// @param av
/// @param ac
/// @return
int			ft_parse(t_list **garbg, t_stack *stack, char **av, int ac);

/// @brief
/// @param av
/// @param ac
void		ft_check_syntax(char **av, int ac);

/// @brief translate from ascii to long long and check for syntax input error
/// @param garbg garbage collector
/// @param str	string to translate it to long long
/// @return long long
long long	ft_atolld(t_list **garbg, char *str);

/// @brief
/// @param garbg
/// @param nbr
void		check_min_max(t_list **garbg, long long nbr);

/// @brief
/// @param c
/// @return
int			ft_issign(char c);

/// @brief
/// @param s
/// @param c
/// @param garbg
/// @return
char		**ft_split_garbg(char const *s, char c, t_list **garbg);

/// @brief
/// @param garbg
/// @param head
/// @param nbr
/// @param ind
void		new_node(t_list **garbg, t_stack *head, long long nbr, int ind);

/// @brief
/// @param head
void		del_node(t_stack *head);

/// @brief
/// @param stack
/// @param ref
void		set_list_lenght(t_lst **stack, int ref);

/// @brief
/// @param table
/// @param a
void		fill_table(int **table, t_stack *a);

/// @brief
/// @param garbg
/// @param stack
/// @param ac
void		ft_check_dup(t_list **garbg, t_stack *stack);

/// @brief
/// @param garbg
/// @param fake
/// @param head
void		ft_lstdup(t_list **garbg, t_stack *fake, t_stack *head);

/// @brief
/// @param fake
/// @param a
/// @param b
/// @param garbg
void		sort_help(t_fakelst *fake, t_stack *a, t_stack *b, t_list **garbg);

/// @brief
/// @param stack
/// @param max
/// @return
int			check_listmax(t_stack *stack, long long *max);

/// @brief
/// @param stack
/// @param min
/// @return
int			check_listmin(t_stack *stack, long long *min);

/// @brief
/// @param garbg
/// @param a
/// @param b
void		fill_stack_a(t_list **garbg, t_stack *a, t_stack *b);

/// @brief
/// @param stack
/// @return
int			wich_half(t_stack *stack);

/// @brief
/// @param garbg
/// @param stack_a
void		ft_sort(t_list **garbg, t_stack *a);

/// @brief
/// @param table
/// @param lenght
void		qwik_sort(int **table, int lenght);

/// @brief
/// @param garbg
/// @param a
/// @param b
void		push_a(t_list **garbg, t_stack *a, t_stack *b, int ind);

/// @brief
/// @param garbg
/// @param b
/// @param a
void		push_b(t_list **garbg, t_stack *b, t_stack *a, int ind);

/// @brief
/// @param b
/// @param ind
void		reverse_b(t_stack *b, int ind);

/// @brief
/// @param a
/// @param ind
void		reverse_a(t_stack *a, int ind);

/// @brief
/// @param a
/// @param b
void		rrr(t_stack *a, t_stack *b);

/// @brief
/// @param a
/// @param ind
void		rotate_a(t_stack *a, int ind);

/// @brief
/// @param b
/// @param ind
void		rotate_b(t_stack *b, int ind);

/// @brief
/// @param a
/// @param b
void		rr(t_stack *a, t_stack *b);

/// @brief
/// @param a
/// @param ind
void		swap_a(t_stack *a, int ind);

/// @brief
/// @param b
/// @param ind
void		swap_b(t_stack *b, int ind);

/// @brief
/// @param a
/// @param b
void		ss(t_stack *a, t_stack *b);

#endif
