#include "../push_swap.h"

void	set_lenght(t_lst **stack_a, t_lst **stack_b, int ref);

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
		new->lenght.stack_a = 1;
		new->next = new;
		new->prev = new;
	}
	else
	{
		new->next = *head;
		set_lenght(head, NULL, 1);
		new->lenght.stack_a = (*head)->lenght.stack_a;
		new->prev = (*head)->prev;
		((*head)->prev)->next = new;
		(*head)->prev = new;
	}
}

void	set_lenght(t_lst **stack_a, t_lst **stack_b, int ref)
{
	int	tmp;
	int	i;

	if (*stack_a)
	{
		tmp = (*stack_a)->lenght.stack_a + ref;
		i = 0;
		while (i++ < tmp - 1)
		{
			(*stack_a)->lenght.stack_a = tmp;
			(*stack_a) = (*stack_a)->next;
		}
	}
	else if (*stack_b)
	{
		tmp = (*stack_b)->lenght.stack_b + ref;
		i = 0;
		while (i++ < tmp - 1)
		{
			(*stack_b)->lenght.stack_b = tmp;
			(*stack_b) = (*stack_b)->next;
		}
	}
}

void	del_node(t_lst **head)
{
	t_lst	*tmp;

	if ((*head)->next == *head)
		return ((*head) = NULL,free (*head));
	tmp = *head;
	set_lenght(head, NULL, -1);
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

