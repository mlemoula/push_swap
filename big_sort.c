/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemoula <mlemoula@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:44:15 by mlemoula          #+#    #+#             */
/*   Updated: 2025/03/24 18:22:50 by mlemoula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_above_piv(t_list *stack, int pivot)
{
	if (!stack)
		return (0);
	while (stack)
	{
		if (stack->content <= pivot)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static void	max_on_top(t_list **stack)
{
	int	n;
	int	stack_size;

	n = get_max_index(*stack);
	stack_size = ft_lstsize(*stack);
	if (!*stack || !(*stack)->next)
		return ;
	if (n <= (stack_size - 1) / 2)
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
}

static int	get_pivot(t_list *stack)
{
	long	min;
	long	max;
	long	pivot;
	t_list	*current;

	if (!stack)
		return (0);
	min = INT_MAX;
	max = INT_MIN;
	current = stack;
	while (current)
	{
		if (current->content > max)
			max = current->content;
		if (current->content < min)
			min = current->content;
		current = current->next;
	}
	pivot = (min + max) / 2;
	return ((int)pivot);
}

static void	divide_by_pivot(t_stacks *stacks)
{
	int	pivot;
	int	loops;

	pivot = get_pivot(stacks->stack_a);
	loops = ft_lstsize(stacks->stack_a);
	while (loops-- && stacks->stack_a && !is_above_piv(stacks->stack_a, pivot))
	{
		if (stacks->stack_a->content <= pivot)
		{
			while (stacks->stack_a->content > stacks->stack_a->next->content)
			{
				sa(&stacks->stack_a);
				pb(&stacks->stack_a, &stacks->stack_b);
				loops--;
			}
			pb(&stacks->stack_a, &stacks->stack_b);
		}
		else if (stacks->stack_a && stacks->stack_a->next)
			ra(&stacks->stack_a);
	}
}

void	big_sort(t_stacks *stacks)
{
	if (stack_is_sorted(stacks->stack_a))
		return ;
	divide_by_pivot(stacks);
	if (!stack_is_sorted(stacks->stack_a))
		sort(stacks);
	while (stacks->stack_b)
	{
		max_on_top(&stacks->stack_b);
		pa(&stacks->stack_a, &stacks->stack_b);
	}
}
