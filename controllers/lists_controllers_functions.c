#include "../push_swap.h"

void	set_lenght(t_lst **stack, int ref);

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
		new->lenght.stack_len = 1;
	}
	else
	{
		new->next = *head;
		new->lenght.stack_len = (*head)->lenght.stack_len;
		new->prev = (*head)->prev;
		((*head)->prev)->next = new;
		(*head)->prev = new;
		set_lenght(head, 1);
	}
}

void	set_lenght(t_lst **stack, int ref)
{
	int		tmp;
	t_lst	*tmp_stack;
	int		i;

	tmp_stack = *stack;
	tmp = tmp_stack->lenght.stack_len;
	i = 0;
	while (i++ < tmp + ref)
	{
		(*stack)->lenght.stack_len = tmp + ref;
		(*stack) = (*stack)->next;
	}
	*stack = tmp_stack;
}

void	del_node(t_lst **head)
{
	t_lst	*tmp;
	int	i;
	int	j;
	i = 0;
	j = (*head)->lenght.stack_len;
	if ((*head)->next == *head)
		return ((*head) = NULL,free (*head));

	tmp = *head;
	// while (i++ < j)
	// {
	// 	printf("{%d}\n",j);
	// 	(*head)->lenght.stack_len--;
	// 	printf("[%d]contetnt[%lld]\n", (*head)->lenght.stack_len, (*head)->content);
	// 	(*head) = (*head)->next;
	// }
	// *head = tmp;
	((*head)->next)->prev = (*head)->prev;
	((*head)->prev)->next = (*head)->next;
	(*head) = (*head)->next;
	free(tmp);
	set_lenght(head, -1);
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
	new->lenght.stack_len = (*head)->lenght.stack_len;
	set_lenght(head, 1);
	((*head)->prev)->next = new;
	(*head)->prev = new;
	(*head) = new;
}
