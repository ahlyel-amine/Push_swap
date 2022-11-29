#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_lst
{
	long long		content;
	long long		LIS;
	long long		parse_it;
	struct s_lst	*next;
	struct s_lst	*prev;
}	t_lst;

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

void	ft_sort(t_lst *stack_a, int ac);
void	ft_get_stack_parsed(t_lst **stack_a, t_lst **stack_b, int ac);

#endif
