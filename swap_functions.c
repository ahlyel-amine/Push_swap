#include "push_swap.h"

void	swap_a(t_lst **head)
{
	long long	nbr;

	nbr = (*head)->content;
	(*head)->content = ((*head)->next)->content;
	((*head)->next)->content = nbr;
}

void	swap_b(t_lst **head)
{
	long long	nbr;

	nbr = (*head)->content;
	(*head)->content = ((*head)->next)->content;
	((*head)->next)->content = nbr;
}

void	ss(t_lst **head_a, t_lst **head_b)
{
	swap_a(head_a);
	swap_b(head_b);
}
