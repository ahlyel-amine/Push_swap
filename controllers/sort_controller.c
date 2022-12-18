/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 12:06:24 by aahlyel           #+#    #+#             */
/*   Updated: 2022/12/18 15:57:28 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		small_element(t_lst *stack)
{
	int		sml;
	int		i;

	sml = INT_MAX;
	i = 0;
	while (i++ < stack->lenght.stack_len)
	{
		sml = min(sml, stack->content);
		stack = stack->next;
	}
	return (sml);
}

int		high_element(t_lst *stack)
{
	int		bg;
	int		i;

	bg = INT_MIN;
	i = 0;
	while (i++ < stack->lenght.stack_len)
	{
		bg = max(bg, stack->content);
		stack = stack->next;
	}
	return (bg);
}

int		define_small(t_lst *stack, int min)
{
	t_lst	*tmp;
	int		i;

	i = 0;
	tmp = stack;
	while (i++ < stack->lenght.stack_len)
	{
		if (tmp->content == min)
		{
			tmp->parse_it = 1;
			break ;
		}
		tmp = tmp->next;
	}
	if ((stack->lenght.stack_len / 2) >= i + 1)
		return (1); // front front
	// if (!(stack->lenght.stack_len % 2)
	// && (stack->lenght.stack_len / 2) >= i)
	// 	return (1); // front front
	// else if ((stack->lenght.stack_len % 2)
	// && (stack->lenght.stack_len / 2) + 1 >= i)
	// 	return (1); // front front
	else
		return (0); // from back
}

int	check_place_in_a(t_lst *stack, int min)
{
	int	i;
	int	small;
	int	bg;

	i = 0;
	small = small_element(stack);
	bg = high_element(stack);
	if (min > bg)
	{
		// while (stack->content != bg)
		// {
		// 	stack = stack->next;
		// 	i++;
		// }
		// if (!i)
		// 	return (1);
		return (bg);
	}
	if (min < small)
	{
		while (i < stack->lenght.stack_len)
		{
			if (stack->content == small)
				return (stack->prev->content);
			stack = stack->next;
			i++;
		}
		// while (i < stack->lenght.stack_len)
		// {
		// 	if (stack->content == small)
		// 		break ;
		// 	stack = stack->next;
		// 	i++;
		// }
		// return (i - 1);
	}
	while (i < stack->lenght.stack_len)
	{
		if (stack->content > min && min > stack->prev->content)
		{
			// break ;
			return (stack->prev->content);
		}
		stack = stack->next;
		i++;
	}
	return (0);
}

void	both_front(t_lst **stack_a, t_lst **stack_b, int a)
{
	int	i;

	i = 0;
	while (i < a && !((*stack_b)->parse_it))
	{
		rr(stack_a, stack_b);
		print_stack(*stack_a, *stack_b);
		i++;
	}
	while (i++ < a)
	{
		rotate_a(stack_a, 1);
		print_stack(*stack_a, *stack_b);
	}
	while (!((*stack_b)->parse_it))
	{
		print_stack(*stack_a, *stack_b);
		rotate_a(stack_b, 1);
	}
	push_a(stack_a, stack_b);
	(*stack_a)->parse_it = 0;
	print_stack(*stack_a, *stack_b);
}

void	both_back(t_lst **stack_a, t_lst **stack_b, int a)
{
	int	i;

	i = 0;
	while (i < a && !((*stack_b)->parse_it))
	{
		rrr(stack_a, stack_b);
		print_stack(*stack_a, *stack_b);
		i++;
	}
	while (!((*stack_b)->parse_it))
	{

	}
	while (i++ < a)
	{
		reverse_a(stack_a, 1);
		print_stack(*stack_a, *stack_b);
	}
	while (!((*stack_b)->parse_it))
	{
		reverse_b(stack_b, 1);
		print_stack(*stack_a, *stack_b);
	}
	push_a(stack_a, stack_b);
	(*stack_a)->parse_it = 0;
	print_stack(*stack_a, *stack_b);
}

void	b_front_a_back(t_lst **stack_a, t_lst **stack_b, int a)
{
	int	i;

	i = 0;
	while (!((*stack_b)->parse_it))
	{
		rotate_b(stack_b, 1);
		print_stack(*stack_a, *stack_b);
	}
	i = 0;
	while (i++ < a)
	{
		reverse_a(stack_a, 1);
		print_stack(*stack_a, *stack_b);
	}
	push_a(stack_a, stack_b);
	(*stack_a)->parse_it = 0;
	print_stack(*stack_a, *stack_b);
}

void	a_front_b_back(t_lst **stack_a, t_lst **stack_b, int a)
{
	int	i;

	i = 0;
	while (i++ < a)
	{
		rotate_a(stack_a, 1);
		print_stack(*stack_a, *stack_b);
	}
	i = 0;
	while (!((*stack_b)->parse_it))
	{
		reverse_b(stack_b, 1);
		print_stack(*stack_a, *stack_b);
	}
	push_a(stack_a, stack_b);
	(*stack_a)->parse_it = 0;
	print_stack(*stack_a, *stack_b);
}

 void define_place(t_lst **stack_a, int	i)
 {
	t_lst *tmp;
	int	j;

	j = 0;
	tmp = *stack_a;
	while (j < tmp->lenght.stack_len)
	{
		if (tmp->content == i)
		{
			tmp->parse_it = 1;
			return (j);
		}
		tmp = tmp->next;
		j++;
	}

 }

void	ft_sort_controller(t_lst *stack_a, int ac)
{
	t_lst	*stack_b;
	t_lst	*tmp;
	t_len	lenght;
	int		min;
	int		i = 0;
	int		j = 0;

	stack_b = NULL;
	print_stack(stack_a, stack_b);
	printf("\n");

	get_lis(stack_a);
	j = check_lis(stack_a);
	if(!j)
		return ;
	else if(j == -1)
		return (ft_sort_rev(stack_a));
	lenght = ft_lis_controll(&stack_a, &stack_b, ac);
	printf("<------------------------>\n\n");
	print_stack(stack_a, stack_b);
	while (stack_b)
	{
		min = small_element(stack_b);
		j = define_small(stack_b, min); // return value 1 if is close to front and 0 if is close to back.
		i = check_place_in_a(stack_a, min);
		min = define_place(stack_a, i);
		printf("next_push {%d}\n", min);
		if (j && stack_a->lenght.stack_len / 2 >= i)
			both_front(&stack_a, &stack_b, i);
		else if (!j &&  stack_a->lenght.stack_len / 2 < i)
			both_back(&stack_a, &stack_b, stack_a->lenght.stack_len - i - 1);
		else if (j && stack_a->lenght.stack_len / 2 < i)
			b_front_a_back(&stack_a, &stack_b, stack_a->lenght.stack_len - i - 1);
		else if (!j && stack_a->lenght.stack_len / 2 >= i)
			a_front_b_back(&stack_a, &stack_b, i + 1);
	}
	min = small_element(stack_a);
	i = check_place_in_a(stack_a, min);
	if (i < (stack_a->lenght.stack_len) / 2)
	{
		while (stack_a->content != min)
		{
			rotate_a(&stack_a, 1);
			print_stack(stack_a, stack_b);
			printf("\n");
		}
	}
	else
	{
		while (stack_a->content != min)
		{
			reverse_a(&stack_a, 1);
			print_stack(stack_a, stack_b);
			printf("\n");
		}

	}
	// // print_stack(stack_a, stack_b);
	// // print_stack(stack_a, stack_b);
	// min = stack_b->lenght.stack_len;
	// while (++i < min)
	// {
	// 	j = 0;
	// 	lenght = ft_comb_controll(&stack_a, &stack_b, lenght);
	// 	sort(&stack_b, &stack_a, lenght);
	// 	(lenght.stack_a)++;
	// 	(lenght.stack_b)--;
	// 	while (j++ < lenght.stack_a)
	// 	{
	// 		if (stack_a->content > stack_a->prev->content)
	// 		{
	// 			reverse(&stack_a);
	// 			write(1, "rra\n", 4);
	// 		}
	// 	}
	// }

	// i = 0;
	// while (i++ < ac)
	// {
	// 	if (stack_a->content > stack_a->prev->content)
	// 	{
	// 		reverse(&stack_a);
	// 		write(1, "rra\n", 4);
	// 	}
	// }
	print_stack(stack_a, stack_b);
	printf("\n");

}

// void	sort(t_lst **head_b, t_lst **head_a, t_len lenght)
// {
// 	int	i;
// 	int	tmp;

// 	i = 0;
// 	tmp = min(lenght.min, lenght.max);
// 	while (tmp && i++ < tmp)
// 	{
// 		rr(head_a, head_b);
// 		write(1, "rr\n", 3);
// 	}
// 	tmp = max(lenght.min, lenght.max);
// 	lenght.min = min(lenght.min, lenght.max);
// 	if (lenght.min < tmp)
// 		while (i++ < tmp)
// 			rotate_a(head_a);
// 	else
// 		while (i++ < lenght.min)
// 			rotate_b(head_b);
// 	push_a(head_a, head_b);
// }

// void	sort_element(t_lst **stack_a, t_lst **stack_b, t_len lenght)
// {
// 	int	i;
// 	int	j;
// 	int	zero;
// 	int	tmp;

// 	i = 0;
// 	while (i++ < lenght.min)
// 		rotate_a(stack_b);
// 	i = 0;
// 	zero = 0;
// 	while (i++ < lenght.stack_a)
// 	{
// 		while (zero++ < i)
// 			reverse_a(stack_a);
// 		while (i < lenght.stack_a)
// 		{
// 			tmp = sort_conditions(*stack_a, *stack_b, lenght);
// 			if (tmp)
// 				break ;
// 			rotate_a(stack_a);
// 		}
// 	}
// }

// int	sort_conditions(t_lst *stack_a, t_lst *stack_b, t_len length)
// {
// 	if (be_first(stack_a, stack_b))
// 		return (1);
// 	else if (be_last_comb(stack_a, stack_b, length))
// 		return (1);
// 	else if (be_secondlast_comb(stack_a, stack_b))
// 		return (1);
// 	else if (be_second_comb(stack_a, stack_b))
// 		return (1);
// 	return (0);
// }


// int	be_second(t_lst *stack_a, t_lst *stack_b)
// {
// 	if (stack_b->content > stack_a->content
// 	&& stack_b->content < (stack_a->next)->content)
// 	{
// 		push_a(&stack_a, &stack_b);
// 		swap(&stack_a);
// 		write (1, "sa\n", 3);
// 		return (2);
// 	}
// 	return (0);
// }

// int	be_secondlast(t_lst *stack_a, t_lst *stack_b)
// {
// 	if (stack_b->content > stack_a->prev->prev->content
// 	&& stack_b->content < stack_a->prev->content)
// 	{
// 		reverse_a(&stack_a);
// 		push_a(&stack_a, &stack_b);
// 		rotate_a(&stack_a);
// 		rotate_a(&stack_a);
// 		return (2);
// 	}
// 	return (0);
// }

// int	be_last(t_lst *stack_a, t_lst *stack_b, t_len length)
// {
// 	int	i;

// 	i = 0;
// 	while (i < length.stack_b || i < length.stack_a)
// 	{
// 		if (stack_b->content <= stack_a->content)
// 			return (0);
// 		stack_a = stack_a->next;
// 		stack_b = stack_b->next;
// 		i++;
// 	}
// 	push_a(&stack_a, &stack_b);
// 	rotate_a(&stack_a);
// 	return (2);
// }

// int	be_first(t_lst *stack_a, t_lst *stack_b)
// {
// 	if (stack_b->content < stack_a->content)
// 	{
// 		push_a(&stack_a, &stack_b);
// 		return (1);
// 	}
// 	return (0);
// }


void	ft_sort_rev(t_lst *stack_a)
{
	t_lst	*stack_b;
	int		i;
	int	 lenght;

	i = 0;
	stack_b = NULL;
	lenght = stack_a->lenght.stack_len;
	while (i++ < lenght)
	{
		push_b(&stack_b, &stack_a);
	}
	i = 0;
	while (i++ < lenght)
	{
		reverse_b(&stack_b, 1);
		push_a(&stack_a, &stack_b);
	}
}
