#include "push_swap.h"
#include "libft.h"

void	new_node(t_lst **head, long long nbr)
{
	t_lst	*new;

	new = malloc(sizeof(t_lst));
	if (!new)
		return ;
	new->content = nbr;
	new->LIS = 1;
	new->parse_it = 1;
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

void	del_node(t_lst **head)
{
	t_lst	*tmp;

	if ((*head)->next == *head)
	{
		free (*head);
		return ;
	}
	tmp = *head;
	((*head)->next)->prev = (*head)->prev;
	((*head)->prev)->next = (*head)->next;
	(*head) = (*head)->next;
	free(tmp);
}

void	ft_listing(t_lst **head, long long *table, int ac)
{
	int	i;

	i = 0;
	while(--ac)
		new_node(head, table[i++]);
	free(table);
}
