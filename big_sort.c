/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemoula <mlemoula@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:44:15 by mlemoula          #+#    #+#             */
/*   Updated: 2025/03/13 16:34:38 by mlemoula         ###   ########.fr       */
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

	stack_size = ft_lstsize(stacks->stack_a);
	pivot = get_pivot(stacks->stack_a);
	// printf("pivot : %d\n", pivot);
	if (stack_is_sorted(stacks->stack_a))
	{
		// printf("Hello");
		return ;
	}
	while (stack_size-- > 0)
	{
		if (stacks->stack_a->content < pivot)
			pb(&stacks->stack_a, &stacks->stack_b);
		else
			ra(&stacks->stack_a);
	}
	if (ft_lstsize(stacks->stack_b) > 3)
		big_sort(stacks);
	else
		small_sort(&stacks->stack_b, ft_lstsize(stacks->stack_a));
	while (stacks->stack_b)
		pa(&stacks->stack_a, &stacks->stack_b);
	if (!stack_is_sorted(stacks->stack_a))
	{
		min_on_top(&stacks->stack_a);
		// big_sort(stacks);
	}
	// print_stack(*stacks);
}
