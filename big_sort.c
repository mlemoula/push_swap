/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemoula <mlemoula@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:44:15 by mlemoula          #+#    #+#             */
/*   Updated: 2025/03/18 23:23:39 by mlemoula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	stack_is_sorted (t_list *stack)
{
	if (!stack || !(stack->next))
		return (1);
	while (stack->next)
	{
		if (stack->next->content < stack->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static int	get_max_index(t_list *stack)
{
	int	i;
	int	max_sofar;
	int	index_max_sofar;

	i = 0;
	index_max_sofar = 0;
	if (!stack)
		return (-1);
	max_sofar = stack->content;
	while (stack->next)
	{
		stack = stack->next;
		i++;
		if (stack->content > max_sofar)
		{
			max_sofar = stack->content;
			index_max_sofar = i;
		}
	}
	return (index_max_sofar);
}

static void	max_on_top(t_list **stack)
{
	int	n;
	int stack_size;

	n = get_max_index(*stack);
	stack_size = ft_lstsize(*stack);
	// if	(n > 0 && stack_letter == 'a')
	// {
	// 	if (n <= (stack_size - 1)/2)
	// 		while (n -- > 0)
	// 				ra(stack);
	// 	else
	// 		while (n++ < stack_size)
	// 			rra(stack);
	// }
	// else if	(n > 0 && stack_letter == 'b')
	// {
	if (n <= (stack_size - 1)/2)
	{
		while (n -- > 0)
		{
			rb(stack);
			if ((*stack)->content < (*stack)->next->content && n > 1)
				sb(stack);
		}
	}
	else
	{
		while (n++ < stack_size)
		{
			rrb(stack);
			if ((*stack)->content < (*stack)->next->content && n > 1)
				sb(stack);
		}
	}
	// }
}

int	get_pivot(t_list *stack)
{
	int	min;
	int	max;
	t_list *current;

	min = INT_MAX;
	max = INT_MIN;
	if (!stack)
		return 0;
	current = stack;
	while (current)
	{
		if (current->content > max)
			max = current->content;
		if (current->content < min)
			min = current->content;
		current = current->next;
	}
	return ((min + max) / 2);
}

void	big_sort(t_stacks *stacks)
{
	int		stack_size;
	int		pivot;

	if (stack_is_sorted(stacks->stack_a))
		return ;
	stack_size = ft_lstsize(stacks->stack_a);
	pivot = get_pivot(stacks->stack_a);
	while (stack_size-- > 1)
	{
		if (stacks->stack_a->content < pivot)
		{
			if (stacks->stack_a->content > stacks->stack_a->next->content)
				sa(&stacks->stack_a);
			// else
			pb(&stacks->stack_a, &stacks->stack_b);
		}
		else if (stack_size > 1 && !stack_is_sorted(stacks->stack_a) && stacks->stack_a->content > pivot)
			ra(&stacks->stack_a);
		else
		//if (stacks->stack_a->content > pivot)
			break;
		// if (stacks->stack_b && stacks->stack_b->next && (stacks->stack_b->content > stacks->stack_b->next->content))
		// 	sb(&stacks->stack_b);
	}
	if (ft_lstsize(stacks->stack_a) > 5 && !stack_is_sorted(stacks->stack_a))
		big_sort(stacks);
	else if (!stack_is_sorted(stacks->stack_a))
		small_sort(&stacks->stack_a, ft_lstsize(stacks->stack_a));
	while (stacks->stack_b)
	{
		max_on_top(&stacks->stack_b);
		pa(&stacks->stack_a, &stacks->stack_b);
	}
}
