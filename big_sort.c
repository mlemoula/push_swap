/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemoula <mlemoula@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:44:15 by mlemoula          #+#    #+#             */
/*   Updated: 2025/04/01 02:52:20 by mlemoula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	above_piv(t_list *stack, int pivot)
{
	if (!stack)
		return (0);
	while (stack)
	{
		if (*(int *)stack->content <= pivot)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static void	max_on_top(t_stacks *stacks)
{
	int	n;
	int	size;

	if (!stacks->stack_b || !(stacks->stack_b)->next)
		return ;
	n = get_max_index(stacks->stack_b);
	size = ft_lstsize(stacks->stack_b);
	if (n == 0)
		return ;
	if (n <= (size - 1) / 2)
	{
		while (n-- > 0)
			rb(stacks);
	}
	else
	{
		while (n++ < size)
			rrb(stacks);
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
	current = stack;
	max = 0;
	min = *(int *)current->content;
	max = *(int *)current->content;
	while (current)
	{
		if (*(int *)current->content > max)
			max = *(int *)current->content;
		if (*(int *)current->content < min)
			min = *(int *)current->content;
		current = current->next;
	}
	pivot = (min + max) / 2;
	return ((int)pivot);
}

static void	divide_by_pivot(t_stacks *stacks)
{
	int	pivot_a;
	int	pivot_b;
	int	loops;

	pivot_a = get_pivot(stacks->stack_a);
	loops = ft_lstsize(stacks->stack_a);
	while (loops-- && stacks->stack_a && !above_piv(stacks->stack_a, pivot_a))
	{
		pivot_b = get_pivot(stacks->stack_b);
		if (*(int *)stacks->stack_a->content <= pivot_a)
		{
			pb(stacks);
			if (stacks->stack_b && stacks->stack_b->next &&
				*(int *)stacks->stack_b->content > pivot_b)
				rb(stacks);
		}
		else if (stacks->stack_a && stacks->stack_a->next)
		{
			if (stacks->stack_b && stacks->stack_b->next &&
				*(int *)stacks->stack_b->content > pivot_b)
				rb(stacks);
			ra(stacks);
		}
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
		max_on_top(stacks);
		pa(stacks);
	}
}
