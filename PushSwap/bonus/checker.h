/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 21:42:46 by aahlyel           #+#    #+#             */
/*   Updated: 2023/01/23 16:35:06 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "get_next_line/get_next_line.h"
# include "libft_tools/libft.h"

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
void		checker_check(t_list **garbg, t_stack *a, int *list);
void		qwik_sort(int **table, int lenght);
void		fill_table(int **table, t_stack *a);
char		**ft_split_garbg(char const *s, char c, t_list **garbg);
void		new_node(t_list **garbg, t_stack *head, long long nbr, int ind);
void		del_node(t_stack *head);
int			ft_parse(t_list **garbg, t_stack *stack, char **av, int ac);
void		ft_check_dup(t_list **garbg, t_stack *stack);
void		ft_exit(char *error_msg, t_list **garbg, int status);
void		*ft_malloc(void *pointer, t_list **garbg);
long long	ft_atolld(t_list **garbg, char *str);
void		check_min_max(t_list **garbg, long long nbr);
int			ft_issign(char c);
void		push_a(t_list **garbg, t_stack *a, t_stack *b, int ind);
void		push_b(t_list **garbg, t_stack *b, t_stack *a, int ind);
void		reverse_a(t_stack *a, int ind);
void		reverse_b(t_stack *b, int ind);
void		rrr(t_stack *a, t_stack *b);
void		rotate_a(t_stack *a, int ind);
void		rotate_b(t_stack *b, int ind);
void		rr(t_stack *a, t_stack *b);
void		swap_a(t_stack *a, int ind);
void		swap_b(t_stack *b, int ind);
void		ss(t_stack *a, t_stack *b);

# endif
