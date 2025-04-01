/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemoula <mlemoula@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 01:34:22 by mlemoula          #+#    #+#             */
/*   Updated: 2025/04/01 17:09:15 by mlemoula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_min_index(t_list *stack)
{
	int	i;
	int	min_sofar;
	int	index_min_sofar;

	i = 0;
	index_min_sofar = 0;
	if (!stack)
		return (-1);
	min_sofar = *(int *)stack->content;
	while (stack->next)
	{
		stack = stack->next;
		i++;
		if (*(int *)stack->content < min_sofar)
		{
			min_sofar = *(int *)stack->content;
			index_min_sofar = i;
		}
	}
	return (index_min_sofar);
}

int	get_max_index(t_list *stack)
{
	int	i;
	int	max_sofar;
	int	index_max_sofar;

	i = 0;
	index_max_sofar = 0;
	if (!stack)
		return (-1);
	max_sofar = *(int *)stack->content;
	while (stack)
	{
		if (*(int *)stack->content > max_sofar)
		{
			max_sofar = *(int *)stack->content;
			index_max_sofar = i;
		}
		stack = stack->next;
		i++;
	}
	return (index_max_sofar);
}

static void	min_on_top(t_stacks *stacks)
{
	int		n;
	int		stack_size;
	t_list	**stack;

	stack = &stacks->stack_a;
	n = get_min_index(*stack);
	stack_size = ft_lstsize(*stack);
	if (n > 0)
	{
		if (n <= (stack_size - 1) / 2)
			while (n -- > 0)
				ra(stacks);
		else
			while (n++ < stack_size)
				rra(stacks);
	}
}

static void	small_sort(t_stacks *stacks, int stack_size)
{
	t_list	**stack_a;

	stack_a = &stacks->stack_a;
	if ((*(int *)(*stack_a)->content > *(int *)(*stack_a)->next->content)
		&& (*(int *)(*stack_a)->content > *(int *)(*stack_a)->next->content))
		sa(stacks);
	if (*(int *)(*stack_a)->content > *(int *)(*stack_a)->next->content)
		sa(stacks);
	if (stack_size == 3)
	{
		if (*(int *)(*stack_a)->next->content
			> *(int *)(*stack_a)->next->next->content)
		{
			if (*(int *)(*stack_a)->next->next->content
				< *(int *)(*stack_a)->next->content)
				rra(stacks);
			if (*(int *)(*stack_a)->next->content < *(int *)(*stack_a)->content)
				sa(stacks);
		}
	}
}

void	sort(t_stacks *stacks)
{
	t_list	**stack_a;
	int		stack_size;

	stack_a = &stacks->stack_a;
	stack_size = ft_lstsize(*stack_a);
	if (stack_size == 2 || stack_size == 3)
	{
		small_sort(stacks, stack_size);
		return ;
	}
	else if (stack_size == 4 || stack_size == 5)
	{
		min_on_top(stacks);
		pb(stacks);
		sort(stacks);
		pa(stacks);
		return ;
	}
	else
		big_sort(stacks);
}
