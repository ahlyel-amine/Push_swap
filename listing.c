#include "push_swap.h"
#include "libft.h"

void	new_node(t_lst **head, long long nbr)
{
	t_lst	*new;

	new = malloc(sizeof(t_lst));
	if (!new)
		return ;
	new->content = nbr;
	if (!(*head))
	{
		*head = new;
		new->next = new;
		new->prev = new;
	}
	else
	{
		new->next = *head;
		new->prev = (*head)->prev;
		((*head)->prev)->next = new;
		(*head)->prev = new;
	}

}

void	ft_listing(t_lst **head, long long *table, int ac)
{
	int	i;

	i = 0;
	while (--ac)
		new_node(head, table[i++]);
	free(table);
}
