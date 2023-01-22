/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 21:39:13 by aahlyel           #+#    #+#             */
/*   Updated: 2023/01/22 17:02:00 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/checker.h"


void	new_node(t_list **garbg, t_stack *head, long long nbr, int ind)
{
	t_lst	*new;

	new = ft_malloc(malloc(sizeof(t_lst)), garbg);
	new->content = nbr;
	new->LIS = 1;
	new->parse_it = 0;
	if (!(head)->stack)
	{
		(head)->stack = new;
		new->next = new;
		new->prev = new;
		(head)->lenght = 1;
	}
	else
	{
		new->next = (head)->stack;
		new->prev = (head)->stack->prev;
		((head)->stack->prev)->next = new;
		(head)->stack->prev = new;
		(head)->lenght++;
		if (ind)
			(head)->stack = new;
	}
}

void	fill_table(int **table, t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->lenght)
	{
		(*table)[i] = a->stack->content;
		a->stack = a->stack->next;
		i++;
	}
}


void	del_node(t_stack *head)
{
	if ((head)->stack->next == head->stack)
	{
		head->stack = NULL;
		return ;
	}
	((head)->stack->next)->prev = (head)->stack->prev;
	((head)->stack->prev)->next = (head)->stack->next;
	(head)->stack = (head)->stack->next;
	head->lenght--;
}


void	qwick_sort(int **table, int lenght)
{
	int		tmp;
	int		i;
	int		j;

	i = 0;
	while (i < lenght)
	{
		j = i + 1;
		while (j < lenght)
		{
			if ((*table)[i] > (*table)[j])
			{
				tmp = (*table)[i];
				(*table)[i] = (*table)[j];
				(*table)[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	checker_check(t_list **garbg, t_stack *a, int *list)
{
	int	i;

	i = 0;
	while (i < a->lenght)
	{
		if (a->stack->content != list[i])
		{
			write (1, "KO\n", 3);
			exit(EXIT_SUCCESS);
		}
		i++;
		a->stack = a->stack->next;
	}
}

int main(int ac, char **av)
{
	t_list	*garbg;
	t_list	*instractions;
	t_stack	*stack;
	t_stack	*b;
	int		*table;
	char	*reader;

	instractions = NULL;
	b = NULL;
	garbg = NULL;
	stack = ft_malloc(malloc(sizeof(t_stack)), &garbg);
	stack->stack = NULL;
	reader = get_next_line(STDIN_FILENO);
	if (ac <= 1)
		exit(EXIT_SUCCESS);
	ft_parse(&garbg, stack, ++av, ac - 1);
	while (reader)
	{
		ft_lstadd_back(&instractions, ft_malloc(ft_lstnew(reader), &garbg));
		reader = get_next_line(STDIN_FILENO);
	}
	table = ft_malloc(malloc(stack->lenght * sizeof(int)), &garbg);
	fill_table(&table, stack);
	qwick_sort(&table, stack->lenght);
	// while (instractions)
	// {
	// 	printf("%s", instractions->content);
	// 	instractions = instractions->next;
	// }
	if (stack->stack->next == stack->stack && instractions)
	{
		write (1, "KO\n", 3);
		exit(EXIT_SUCCESS);
	}
	if (stack->stack->next == stack->stack && !instractions)
	{
		write (1, "OK\n", 3);
		exit(EXIT_SUCCESS);
	}
	while (instractions)
	{
		if (!ft_strncmp(instractions->content, "ra\n", 3))
			rotate_a(stack, 0);
		else if (!ft_strncmp(instractions->content, "rb\n", 3))
			rotate_b(b, 0);
		else if (!ft_strncmp(instractions->content, "rr\n", 3))
			rr(stack, b);
		else if (!ft_strncmp(instractions->content, "pa\n", 3))
			push_a(&garbg, stack, b, 0);
		else if (!ft_strncmp(instractions->content, "pb\n", 3))
			push_b(&garbg, b, stack, 0);
		else if (!ft_strncmp(instractions->content, "sa\n", 3))
			swap_a(stack, 0);
		else if (!ft_strncmp(instractions->content, "sb\n", 3))
			swap_b(stack, 0);
		else if (!ft_strncmp(instractions->content, "ss\n", 3))
			ss(stack, b);
		else if (!ft_strncmp(instractions->content, "rra\n", 4))
			reverse_a(stack, 0);
		else if (!ft_strncmp(instractions->content, "rrb\n", 4))
			reverse_b(b, 0);
		else if (!ft_strncmp(instractions->content, "rrr\n", 4))
			rrr(stack, b);
		else
			break ;
		instractions = instractions->next;
	}
	checker_check(&garbg, stack, table);
	write (1, "OK\n", 3);
	return 0;
}
