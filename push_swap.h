#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

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

void	ft_get_stack_parsed(t_lst **stack_a, t_lst **stack_b, int ac);

void	ft_calcul_comb(t_lst **stack_a, t_lst **stack_b, t_len length);

/*		sort_functions.c		*/
void		ft_sort(t_lst *stack_a, int ac);
void		get_lis(t_lst *list, int ac);
int			get_parsed(t_lst *list, int ac, int max_lis); // need rework
int			get_max_lis(t_lst *list, int ac);

/*^^^^^^^^^^^^^^^^^^ DIR : sort_functions ^^^^^^^^^^^^^^^^^^*/
/*<<<<<<<<<<<<<<<<<< FILE : push_functions.c >>>>>>>>>>>>>>>>>>*/
void		push_a(t_lst **stack_a, t_lst **stack_b);
void		push_b(t_lst **stack_b, t_lst **stack_a);
/*<<<<<<<<<<<<<<<<<< FILE : reverse_functions.c >>>>>>>>>>>>>>>>>>*/
void		reverse(t_lst **stack);
void		rrr(t_lst **stack_a, t_lst **stack_b);
/*<<<<<<<<<<<<<<<<<< FILE : rotate_functions.c >>>>>>>>>>>>>>>>>>*/
void		rotate(t_lst **stack);
void		rr(t_lst **stack_a, t_lst **stack_b);
/*<<<<<<<<<<<<<<<<<< FILE : swap_functions.c >>>>>>>>>>>>>>>>>>*/
void		swap(t_lst **head);
void		ss(t_lst **head_a, t_lst **head_b);

/*^^^^^^^^^^^^^^^^^^ DIR : utils ^^^^^^^^^^^^^^^^^^*/
/*<<<<<<<<<<<<<<<<<< FILE : utils.c >>>>>>>>>>>>>>>>>>*/
int			still_digits(char *str);
int			min(int nbr1, int nbr2);
int			max(int nbr1, int nbr2);
long long	ft_atolld(char **str);
/*<<<<<<<<<<<<<<<<<< FILE : ft_split_count.c >>>>>>>>>>>>>>>>>>*/
char		**ft_split_count(char const *s, char c, int *count);

/*^^^^^^^^^^^^^^^^^^ DIR : controllers ^^^^^^^^^^^^^^^^^^*/
/*<<<<<<<<<<<<<<<<<< FILE : input_controller.c >>>>>>>>>>>>>>>>>>*/
int			ft_table(t_lst **stack, char **av, int ac);
int			ft_check_input_dup(t_lst *stack, int ac);
int			ft_check_input_digits(char **av, int ac);
/*<<<<<<<<<<<<<<<<<< FILE : lists_controllers_functions.c >>>>>>>>>>>>>>>>>>*/
void		ft_lstdup(t_lst **new_stack, t_lst *stack, int ac);
void		new_node(t_lst **head, long long nbr);
void		del_node(t_lst **head);
#endif
