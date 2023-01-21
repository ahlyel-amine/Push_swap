#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../../libft/libft.h"
# include "sys/errno.h"
# include "limits.h"


// typedef	struct s_len
// {
// 	int	stack_a;
// 	int	stack_len;
// 	int	stack_b;
// 	int	min;
// 	int	max;
// }	t_len;


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
	t_lst	*hold;
	int		lenght;
}	t_stack;

typedef	struct s_fakelst
{
	t_stack			*stack;
	int				*table;
	long long		bg;
	long long		sm;
}	t_fakelst;

/// @brief
/// @param garbg
/// @param a
void	big_sort(t_list **garbg, t_stack *a);

/// @brief
/// @param garbg
/// @param a
void	low_sort(t_list **garbg, t_stack *a);

/// @brief 
/// @param garbg
/// @param a
void	sort_3digits(t_list **garbg, t_stack *a);

/// @brief
/// @param garbg
/// @param a
void	sort_check(t_list **garbg, t_stack *a);

/// @brief
/// @param error_msg
/// @param garbg
void	ft_exit(char *error_msg, t_list **garbg, int status);

/// @brief
/// @param pointer
/// @param garbg
/// @return
void	*ft_malloc(void *pointer, t_list **garbg);


/// @brief
/// @param garbg
/// @param stack
/// @param av
/// @param ac
/// @return
int	ft_parse(t_list **garbg, t_stack *stack, char **av, int ac);

/// @brief
/// @param av
/// @param ac
void	ft_check_syntax(char **av, int ac);

/// @brief translate from ascii to long long and check for syntax input error
/// @param garbg garbage collector
/// @param str	string to translate it to long long
/// @return long long
long long	ft_atolld(t_list **garbg, char *str);

/// @brief
/// @param garbg
/// @param nbr
void	check_min_max(t_list **garbg, long long nbr);

/// @brief
/// @param c
/// @return
int	ft_issign(char c);

/// @brief
/// @param s
/// @param c
/// @param garbg
/// @return
char	**ft_split_garbg(char const *s, char c, t_list **garbg);

/// @brief
/// @param garbg
/// @param head
/// @param nbr
/// @param ind
void	new_node(t_list **garbg, t_stack *head, long long nbr, int ind);

/// @brief
/// @param head
void	del_node(t_stack *head);

/// @brief
/// @param stack
/// @param ref
void	set_list_lenght(t_lst **stack, int ref);

/// @brief
/// @param garbg
/// @param stack
/// @param ac
void	ft_check_dup(t_list **garbg, t_stack *stack);


/// @brief
/// @param garbg
/// @param a
/// @param b
void	push_a(t_list **garbg, t_stack *a, t_stack *b);


/// @brief
/// @param garbg
/// @param b
/// @param a
void	push_b(t_list **garbg, t_stack *b, t_stack *a);

/// @brief
/// @param garbg
/// @param fake
/// @param head
void	ft_lstdup(t_list **garbg, t_stack *fake, t_stack *head);


/// @brief
/// @param fake
/// @param a
/// @param b
/// @param garbg
void	sort_help(t_fakelst *fake, t_stack *a,  t_stack *b, t_list **garbg);



/// @brief
/// @param stack
/// @param max
/// @return
int	check_listmax(t_stack *stack, long long *max);

/// @brief
/// @param stack
/// @param min
/// @return
int	check_listmin(t_stack *stack, long long *min);

/// @brief
/// @param garbg
/// @param a
/// @param b
void	fill_stack_a(t_list **garbg, t_stack *a, t_stack *b);


/// @brief
/// @param stack
/// @return
int	wich_half(t_stack *stack);

/// @brief
/// @param garbg
/// @param stack_a
void	ft_sort(t_list **garbg, t_stack *a);


/// @brief
/// @param table
/// @param lenght
void	qwick_sort(int **table, int lenght);

void		get_lis(t_lst *list); // V
int			get_max_lis(t_lst *list); // V
int			check_lis_sorted(t_lst *list); // V
int			check_lis_rev_sorted(t_lst *list); // V
int			check_lis(t_lst *list); // V
int			sequence_len(t_lst *stack, int len); // V
void		lis_divide(t_lst **stack_a, t_lst **stack_b, int ac); // V
int			define_sequence(t_lst *list, int max_lis); // V

/*^^^^^^^^^^^^^^^^^^ DIR : sort_functions ^^^^^^^^^^^^^^^^^^*/

/*<<<<<<<<<<<<<<<<<< FILE : push_functions.c >>>>>>>>>>>>>>>>>>*/


/*<<<<<<<<<<<<<<<<<< FILE : reverse_functions.c >>>>>>>>>>>>>>>>>>*/
void	reverse_b(t_stack *b, int ind);
void	reverse_a(t_stack *a, int ind);
void	rrr(t_stack *a, t_stack *b);

/*<<<<<<<<<<<<<<<<<< FILE : rotate_functions.c >>>>>>>>>>>>>>>>>>*/
void	rotate_a(t_stack *a, int ind);
void	rotate_b(t_stack *b, int ind);
void	rr(t_stack *a, t_stack *b);

/*<<<<<<<<<<<<<<<<<< FILE : swap_functions.c >>>>>>>>>>>>>>>>>>*/
void	swap_a(t_stack *a, int ind);
void	swap_b(t_stack *b, int ind);
void	ss(t_stack *a, t_stack *b);

/*^^^^^^^^^^^^^^^^^^ DIR : utils ^^^^^^^^^^^^^^^^^^*/

/*<<<<<<<<<<<<<<<<<< FILE : utils.c >>>>>>>>>>>>>>>>>>*/
int			still_digits(char *str); // V
/*<<<<<<<<<<<<<<<<<< FILE : utils.c >>>>>>>>>>>>>>>>>>*/
int			min(int nbr1, int nbr2);
/*<<<<<<<<<<<<<<<<<< FILE : utils.c >>>>>>>>>>>>>>>>>>*/
int			max(int nbr1, int nbr2); // V
/*<<<<<<<<<<<<<<<<<< FILE : utils.c >>>>>>>>>>>>>>>>>>*/
// long long	ft_atolld(char **str); // V

/*<<<<<<<<<<<<<<<<<< FILE : ft_split_count.c >>>>>>>>>>>>>>>>>>*/
// char		**ft_split_count(char const *s, char c, int *count);

/*^^^^^^^^^^^^^^^^^^ DIR : controllers ^^^^^^^^^^^^^^^^^^*/

/*<<<<<<<<<<<<<<<<<< FILE : input_controller.c >>>>>>>>>>>>>>>>>>*/
// t_len		ft_comb_controll(t_lst **stack_a, t_lst **stack_b, t_len lenght);
/*<<<<<<<<<<<<<<<<<< FILE : input_controller.c >>>>>>>>>>>>>>>>>>*/
// void		get_combs_back(t_lst **stack_a, t_lst **stack_b, t_len length);
/*<<<<<<<<<<<<<<<<<< FILE : input_controller.c >>>>>>>>>>>>>>>>>>*/
// void		get_combs_front(t_lst **stack_a, t_lst **stack_b, t_len length);
/*<<<<<<<<<<<<<<<<<< FILE : input_controller.c >>>>>>>>>>>>>>>>>>*/
// int			combs_conditions(t_lst *stack_a, t_lst *stack_b, t_len length);
/*<<<<<<<<<<<<<<<<<< FILE : input_controller.c >>>>>>>>>>>>>>>>>>*/
// int			be_first_comb(t_lst *stack_a, t_lst *stack_b);
/*<<<<<<<<<<<<<<<<<< FILE : input_controller.c >>>>>>>>>>>>>>>>>>*/
// int			be_second_comb(t_lst *stack_a, t_lst *stack_b);
/*<<<<<<<<<<<<<<<<<< FILE : input_controller.c >>>>>>>>>>>>>>>>>>*/
// int			be_last_comb(t_lst *stack_a, t_lst *stack_b, t_len length);
/*<<<<<<<<<<<<<<<<<< FILE : input_controller.c >>>>>>>>>>>>>>>>>>*/
// int			be_secondlast_comb(t_lst *stack_a, t_lst *stack_b);
/*<<<<<<<<<<<<<<<<<< FILE : input_controller.c >>>>>>>>>>>>>>>>>>*/
// int			select_small_comb(t_lst *stack, int len);
/*<<<<<<<<<<<<<<<<<< FILE :place_controller.c >>>>>>>>>>>>>>>>>>*/
void	check_places(t_lst *stack_a, t_lst *stack_b);
int		check_max_min_back(t_lst *stack_a, t_lst *stack_b, int place_b);
void	check_front_back(t_lst *stack_a, t_lst *stack_b);
void	check_back_back(t_lst *stack_a, t_lst *stack_b);


/*<<<<<<<<<<<<<<<<<< FILE : sort_controller.c >>>>>>>>>>>>>>>>>>*/
void		ft_sort_controller(t_lst *stack_a, int ac); // V
void		define_place(t_lst **stack_a, int i, int ind);
void		ft_sort_rev(t_lst *stack_a); // V
int			small_element(t_lst *stack); // V
int			define_small(t_lst *stack, int min); // V
int			high_element(t_lst *stack); // V
void		both_front(t_lst **stack_a, t_lst **stack_b, int ind); // V
void		both_back(t_lst **stack_a, t_lst **stack_b, int ind); // V
void		b_front_a_back(t_lst **stack_a, t_lst **stack_b, int ind); // V
int			check_place_in_a(t_lst *stack, int min); // V
void		a_front_b_back(t_lst **stack_a, t_lst **stack_b, int ind); // V
/*<<<<<<<<<<<<<<<<<< FILE : sort_controller.c >>>>>>>>>>>>>>>>>>*/

/*<<<<<<<<<<<<<<<<<< FILE : stack_controller.c >>>>>>>>>>>>>>>>>>*/
void		print_stack(t_stack *tmp, t_stack *tmp1);
/*<<<<<<<<<<<<<<<<<< FILE : input_controller.c >>>>>>>>>>>>>>>>>>*/
int			ft_table(t_lst **stack, char **av, int ac); // V
/*<<<<<<<<<<<<<<<<<< FILE : input_controller.c >>>>>>>>>>>>>>>>>>*/
int			ft_check_input_digits(char **av, int ac); // V

/*<<<<<<<<<<<<<<<<<< FILE : lists_controllers_functions.c >>>>>>>>>>>>>>>>>>*/
void		set_lenght(t_lst **stack, int ref); // V
/*<<<<<<<<<<<<<<<<<< FILE : lists_controllers_functions.c >>>>>>>>>>>>>>>>>>*/
// void		add_node(t_lst **head, long long nbr);
/*<<<<<<<<<<<<<<<<<< FILE : lists_controllers_functions.c >>>>>>>>>>>>>>>>>>*/
/*<<<<<<<<<<<<<<<<<< FILE : lists_controllers_functions.c >>>>>>>>>>>>>>>>>>*/
// void		ft_lstdup(t_lst **new_stack, t_lst *stack, int ac);


#endif
