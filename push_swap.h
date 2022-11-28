#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <string.h>
# include <stdlib.h>

typedef struct s_lst
{
	long long		content;
	struct s_lst	*next;
	struct s_lst	*prev;
}	t_lst;
void	ft_listing(t_lst **head, long long *table, int ac);
#endif
