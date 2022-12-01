#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_lst
{
	long long		content;
	long long		LIS;
	long long		parse_it;
	struct s_lst	*next;
	struct s_lst	*prev;
}	t_lst;

typedef	struct s_len
{
	int	stack_a;
	int	stack_b;
	int	min;
	int	max;
}	t_len;

void	ft_listing(t_lst **head, long long *table, int ac);
char	**ft_split_count(char const *s, char c, int *count);
void	new_node(t_lst **head, long long nbr);
void	del_node(t_lst **head);


void	push_a(t_lst **stack_a, t_lst **stack_b);
void	push_b(t_lst **stack_b, t_lst **stack_a);

void	reverse(t_lst **stack);
void	rrr(t_lst **stack_a, t_lst **stack_b);

void	rotate(t_lst **stack);
void	rr(t_lst **stack_a, t_lst **stack_b);

void	swap(t_lst **head);
void	ss(t_lst **head_a, t_lst **head_b);

void	ft_get_stack_parsed(t_lst **stack_a, t_lst **stack_b, int ac);


void	ft_calcul_comb(t_lst **stack_a, t_lst **stack_b, t_len length);


/*		sort_functions.c		*/
void	ft_sort(t_lst *stack_a, int ac);
void	get_lis(t_lst *list, int ac);
int		get_parsed(t_lst *list, int ac, int max_lis); // need rework
int		get_max_lis(t_lst *list, int ac);
void	ft_lstdup(t_lst **new_stack, t_lst *stack, int ac);
#endif
