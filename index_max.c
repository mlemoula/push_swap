/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_max.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemoula <mlemoula@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 23:06:53 by mlemoula          #+#    #+#             */
/*   Updated: 2025/04/03 00:35:05 by mlemoula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_index(t_list *stack)
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

static int	get_nxt_max_i(t_list *stack)
{
	int	i;
	int	max_index;
	int	nxt_max_sofar;
	int	index_nxt_max_sofar;

	i = 0;
	index_nxt_max_sofar = 0;
	if (!stack)
		return (-1);
	max_index = get_max_index(stack);
	nxt_max_sofar = INT_MIN;
	while (stack)
	{
		if (*(int *)stack->content > nxt_max_sofar && i != max_index)
		{
			nxt_max_sofar = *(int *)stack->content;
			index_nxt_max_sofar = i;
		}
		stack = stack->next;
		i++;
	}
	return (index_nxt_max_sofar);
}

static int	rotation_cost(int index, int size)
{
	int	cost_ra;
	int	cost_rra;

	cost_ra = index;
	cost_rra = size - index;
	if (cost_rra < cost_ra)
		return (cost_rra);
	return (cost_ra);
}

static void	push_a_index(t_stacks *stacks, int index, int size)
{
	if (index <= (size - 1) / 2)
	{
		while (index-- > 0)
			rb(stacks);
	}
	else
	{
		while (index++ < size)
			rrb(stacks);
	}
	pa(stacks);
}

void	push_max_pair(t_stacks *stacks)
{
	int		cost_max;
	int		cost_next;
	int		i_max;
	int		i_next;
	int		size;

	size = ft_lstsize(stacks->stack_b);
	i_max = get_max_index(stacks->stack_b);
	i_next = get_nxt_max_i(stacks->stack_b);
	cost_max = rotation_cost(i_max, size);
	cost_next = rotation_cost(i_next, size);
	if (stacks->stack_b && stacks->stack_b->next && (cost_next + 1 < cost_max))
	{
		push_a_index(stacks, i_next, size);
		i_max = get_max_index(stacks->stack_b);
		size = ft_lstsize(stacks->stack_b);
		push_a_index(stacks, i_max, size);
		sa(stacks);
	}
	else
		push_a_index(stacks, i_max, size);
}
