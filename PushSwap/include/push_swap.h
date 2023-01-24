/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 21:05:34 by aahlyel           #+#    #+#             */
/*   Updated: 2023/01/24 16:21:25 by aahlyel          ###   ########.fr       */
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
	long long		bg;
	long long		sm;
}	t_fakelst;

/// @brief			sort stacks with size greater than 7
/// @param garbg	garbg collector
/// @param a		stack A
void		big_sort(t_list **garbg, t_stack *a);

/// @brief	sort stacks with size less than 8 by
///recursivity and calling sort_3digits()
/// @param garbg	garbg collector
/// @param a		stack A
void		low_sort(t_list **garbg, t_stack *a, t_stack *b);

/// @brief			sort stacks with size less than 8
/// @param garbg	garbg collector
/// @param a		stack A
void		sort_3digits(t_stack *a);

/// @brief			check if stack already sorted
/// @param garbg	garbg collector
/// @param a		stack A
void		sort_check(t_list **garbg, t_stack *a);

/// @brief				exit from th program and show error message
/// in case of error and free the garbg collector
/// @param error_msg	error message in case of error
/// @param garbg		garbg collector to be freed
/// @param status		if true exit success else exit faillure
void		ft_exit(char *error_msg, t_list **garbg, int status);

/// @brief			save a pointer in a linked list
///(garbg collector) and call ft_exit in case of faillure
/// @param pointer	pointer being allocated
/// @param garbg	garbg collector
/// @return			pointer being allocated
void		*ft_malloc(void *pointer, t_list **garbg);

/// @brief			fill stack a from arguments and check syntax
/// @param garbg	garbg collector
/// @param stack	stack a
/// @param av		main arguments
/// @param ac		main argumentd count
void		ft_parse(t_list **garbg, t_stack *stack, char **av, int ac);

/// @brief
/// @param av
/// @param ac
void		ft_check_syntax(char **av, int ac);

/// @brief			translate from ascii to long long
/// and check for syntax input error
/// @param garbg	garbage collector
/// @param str		string to translate it to long long
/// @return			long long
long long	ft_atolld(t_list **garbg, char *str);

/// @brief			if number less than int
/// min or greater than int max call exit
/// @param garbg	garbg collector
/// @param nbr		numer to check
void		check_min_max(t_list **garbg, long long nbr);

/// @brief		check if a char is a sign - or +
/// @param c	char to check
/// @return		true or false
int			ft_issign(char c);

/// @brief			split a string with a seperator to words
/// @param s		string to split
/// @param c		words separator
/// @param garbg	garbg collector
/// @return			words
char		**ft_split_garbg(char const *s, char c, t_list **garbg);

/// @brief
/// @param garbg	garbg collector
/// @param head		list to add new node to it
/// @param nbr		content of the node
/// @param ind		if true put new node in the head else put it in the back
void		new_node(t_list **garbg, t_stack *head, long long nbr, int ind);

/// @brief			delete a node from a stack
/// @param head		head of stack pointing to the node to delete
void		del_node(t_stack *head);

/// @brief			fill a fake stack with elements from stack A
/// @param table	table (fake stack)
/// @param a		stack A
void		fill_table(int **table, t_stack *a);

/// @brief			check if their is any dup in stack if true call exit
/// @param garbg	garbg collector
/// @param stack	stack a
void		ft_check_dup(t_list **garbg, t_stack *stack);

/// @brief			take of the first elements of stack a to b
/// if is less or equal to the sm and bg elemnts from fake stack
/// @param fake		bg and sm
/// @param a		stack A
/// @param b		stack B
/// @param garbg	garbg collector
void		sort_help(t_fakelst fake, t_stack *a, t_stack *b, t_list **garbg);

/// @brief			define the big element in the stack given
///and put their value in pointer max and return hes position
/// @param stack	stack
/// @param max		pointer to store big element
/// @return			big element value
int			check_listmax(t_stack *stack, long long *max);

/// @brief			define the small element in the stack given
/// and put their value in pointer min and return hes position
/// @param stack	stack
/// @param min		pointer to store small element
/// @return			small element value
int			check_listmin(t_stack *stack, long long *min);

/// @brief			fill stack a with elements from stack b
/// selecting the bigest one every loop
/// @param garbg	garbg collector
/// @param a		stack a
/// @param b		stack b
void		fill_stack_a(t_list **garbg, t_stack *a, t_stack *b);

/// @brief			controll sort
/// @param garbg	garbg collector
/// @param stack_a	stack a
void		ft_sort(t_list **garbg, t_stack *a);

/// @brief			sort the fake table using quick sort algorithm
/// @param table	table (fake stack)
/// @param lenght	lenght of stack
void		qwik_sort(int **table, int lenght);

/// @brief			push element from stack b to stack a
/// @param garbg	garbg collector
/// @param a		stack a
/// @param b		stack b
void		push_a(t_list **garbg, t_stack *a, t_stack *b, int ind);

/// @brief			push element from stack a to stack b
/// @param garbg	garbg collector
/// @param b		stack b
/// @param a		stack a
void		push_b(t_list **garbg, t_stack *b, t_stack *a, int ind);

/// @brief		put the last element of stack b in the top
/// @param b	stack b
/// @param ind	if true print rrb
void		reverse_b(t_stack *b, int ind);

/// @brief		put the last element of stack a in the top
/// @param a	stack b
/// @param ind	if true print rra
void		reverse_a(t_stack *a, int ind);

/// @brief		call reverse_b() and reverse_a()
/// @param a	stack a
/// @param b	stack b
void		rrr(t_stack *a, t_stack *b);

/// @brief		put the first element of stack a in the back
/// @param a	stack a
/// @param ind	if true print ra
void		rotate_a(t_stack *a, int ind);

/// @brief		put the first element of stack b in the back
/// @param b	stack b
/// @param ind	if true print rb
void		rotate_b(t_stack *b, int ind);

/// @brief		call rotate_b() and rotate_a()
/// @param a	stack a
/// @param b	stack b
void		rr(t_stack *a, t_stack *b);

/// @brief		swap the two first elements in stack a
/// @param a	stack a
/// @param ind	if true print sa
void		swap_a(t_stack *a, int ind);

/// @brief		swap the two first elements in stack b
/// @param b	stack b
/// @param ind	if true print sb
void		swap_b(t_stack *b, int ind);

/// @brief		call swap_a() and swap_b()
/// @param a	stack a
/// @param b	stack b
void		ss(t_stack *a, t_stack *b);

#endif
