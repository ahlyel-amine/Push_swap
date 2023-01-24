/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 21:42:46 by aahlyel           #+#    #+#             */
/*   Updated: 2023/01/24 04:19:01 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../../lib/get_next_line/include/get_next_line.h"
# include "../../lib/libft/include/libft.h"
# include <limits.h>
# include <sys/errno.h>

typedef struct s_lst
{
	long long		content;
	long long		parse_it;
	long long		LIS;
	struct s_lst	*next;
	struct s_lst	*prev;
}	t_lst;

typedef	struct s_stack
{
	t_lst	*stack;
	int		lenght;
}	t_stack;

void		push_swap(t_list	**garbg, t_list	*instractions, t_stack	*stack);
int			compare_stacks(t_list **garbg, t_stack *a, int *list, int ind);
void		ft_sort_args(t_list **garbg, t_stack *stack, int **table);
void		read_args(t_list **garbg, t_list **instractions);
void		ft_check_dup(t_list **garbg, t_stack *stack);
void		qwik_sort(int **table, int lenght);
void		check_args(t_list **garbg, char *arg);
void		fill_table(int **table, t_stack *a);
char		**ft_split_garbg(char const *s, char c, t_list **garbg);
void		new_node(t_list **garbg, t_stack *head, long long nbr, int ind);
void		del_node(t_stack *head);
int			ft_parse(t_list **garbg, t_stack *stack, char **av, int ac);
void		ft_exit(char *error_msg, t_list **garbg, int status, int ok);
void		*ft_malloc(void *pointer, t_list **garbg);
long long	ft_atolld(t_list **garbg, char *str);
void		check_min_max(t_list **garbg, long long nbr);
int			ft_issign(char c);
void		push_a(t_list **garbg, t_stack *a, t_stack *b);
void		push_b(t_list **garbg, t_stack *b, t_stack *a);
void		reverse_a(t_stack *a);
void		reverse_b(t_stack *b);
void		rrr(t_stack *a, t_stack *b);
void		rotate_a(t_stack *a);
void		rotate_b(t_stack *b);
void		rr(t_stack *a, t_stack *b);
void		swap_a(t_stack *a);
void		swap_b(t_stack *b);
void		ss(t_stack *a, t_stack *b);

# endif
