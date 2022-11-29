#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <string.h>
# include <stdlib.h>

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




void	ft_sort(t_lst *list, int ac);

#endif
