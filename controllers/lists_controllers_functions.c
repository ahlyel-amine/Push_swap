#include "../push_swap.h"

void	new_node(t_lst **head, long long nbr)
{
	t_lst	*new;

	new = malloc(sizeof(t_lst));
	if (!new)
		return ;
	new->content = nbr;
	new->LIS = 1;
	new->parse_it = 0;
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
		return (free (*head));
	tmp = *head;
	((*head)->next)->prev = (*head)->prev;
	((*head)->prev)->next = (*head)->next;
	(*head) = (*head)->next;
	free(tmp);
}

void	ft_lstdup(t_lst **new_stack, t_lst *stack, int ac)
{
	int i = 0;
	while (i++ < ac)
	{
		new_node(new_stack, stack->content);
		stack = stack->next;
	}
}

void	add_node(t_lst **head, long long nbr)
{
	t_lst	*new;

	new = NULL;
	new_node(&new, nbr);
	new->next = (*head);
	new->prev = (*head)->prev;
	((*head)->prev)->next = new;
	(*head)->prev = new;
	(*head) = new;
}

