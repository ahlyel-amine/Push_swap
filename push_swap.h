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

void	ft_calcul(t_lst *stack_a, t_lst *stack_b, t_len length);

void		ft_calcul_comb(t_lst **stack_a, t_lst **stack_b, t_len length);
/*^^^^^^^^^^^^^^^^^^ DIR : longest_increasing_subsequence ^^^^^^^^^^^^^^^^^^*/

/*<<<<<<<<<<<<<<<<<< FILE : lis.c >>>>>>>>>>>>>>>>>>*/
t_len		ft_lis_controll(t_lst **stack_a, t_lst **stack_b, int ac);
void		get_lis(t_lst *list, int ac);
int			get_max_lis(t_lst *list, int ac);
int			check_lis(t_lst *list, int ac);
int			sequence_len(t_lst *stack, int len);
void		lis_divide(t_lst **stack_a, t_lst **stack_b, int ac);
int			define_sequence(t_lst *list, int ac, int max_lis);

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

/*<<<<<<<<<<<<<<<<<< FILE : comb_controller.c >>>>>>>>>>>>>>>>>>*/
int			ft_comb_controll(t_lst **stack_a, t_lst **stack_b, t_len lenght);
void		get_combs_back(t_lst **stack_a, t_lst **stack_b, t_len length);
void		get_combs_front(t_lst **stack_a, t_lst **stack_b, t_len length);
int			combs_conditions(t_lst *stack_a, t_lst *stack_b, t_len length);
int			be_first_comb(t_lst *stack_a, t_lst *stack_b);
int			be_second_comb(t_lst *stack_a, t_lst *stack_b);
int			be_last_comb(t_lst *stack_a, t_lst *stack_b, t_len length);
int			be_secondlast_comb(t_lst *stack_a, t_lst *stack_b);
int			select_small_comb(t_lst *stack, int len);

/*<<<<<<<<<<<<<<<<<< FILE : sort_controller.c >>>>>>>>>>>>>>>>>>*/
void		ft_sort_controller(t_lst *stack_a, int ac);

/*<<<<<<<<<<<<<<<<<< FILE : stack_controller.c >>>>>>>>>>>>>>>>>>*/
void		print_stack(t_lst *sa, t_lst *sb, t_len lenght);

/*<<<<<<<<<<<<<<<<<< FILE : input_controller.c >>>>>>>>>>>>>>>>>>*/
int			ft_table(t_lst **stack, char **av, int ac);
int			ft_check_input_dup(t_lst *stack, int ac);
int			ft_check_input_digits(char **av, int ac);

/*<<<<<<<<<<<<<<<<<< FILE : lists_controllers_functions.c >>>>>>>>>>>>>>>>>>*/
void		new_node(t_lst **head, long long nbr);
void		add_node(t_lst **head, long long nbr);
void		del_node(t_lst **head);
void		ft_lstdup(t_lst **new_stack, t_lst *stack, int ac);

/*<<<<<<<<<<<<<<<<<< FILE : lists_controllers_functions.c >>>>>>>>>>>>>>>>>>*/
void		print_stack(t_lst *sa, t_lst *sb, t_len lenght);

#endif
