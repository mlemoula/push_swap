/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemoula <mlemoula@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:44:15 by mlemoula          #+#    #+#             */
/*   Updated: 2025/03/25 21:53:56 by mlemoula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_above_piv(t_list *stack, int pivot)
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
	int		n;
	int		stack_size;

	n = get_max_index(stacks->stack_b);
	stack_size = ft_lstsize(stacks->stack_b);
	if (!stacks->stack_b || !(stacks->stack_b)->next)
		return ;
	if (n <= (stack_size - 1) / 2)
	{
		while (n-- > 0)
		{
			rb(stacks);
			if (*(int *)(stacks->stack_b->content) < *(int *)(stacks->stack_b->next->content) && n > 1)
				sb(stacks);
		}
	}
	else
	{
		while (n++ < stack_size)
		{
			rrb(stacks);
			if (*(int *)(stacks->stack_b->content) < *(int *)(stacks->stack_b->next->content) && n > 1)
				sb(stacks);
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
	current = stack;
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
	int	pivot;
	int	loops;

	pivot = get_pivot(stacks->stack_a);
	loops = ft_lstsize(stacks->stack_a);
	while (loops-- && stacks->stack_a && !is_above_piv(stacks->stack_a, pivot))
	{
		if (*(int *)stacks->stack_a->content <= pivot)
		{
			while (*(int *)stacks->stack_a->content > *(int *)stacks->stack_a->next->content)
			{
				sa(stacks);
				pb(stacks);
				loops--;
			}
			pb(stacks);
		}
		else if (stacks->stack_a && stacks->stack_a->next)
			ra(stacks);
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
