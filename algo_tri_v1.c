/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_tri_v1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemoula <mlemoula@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 01:34:22 by mlemoula          #+#    #+#             */
/*   Updated: 2025/02/28 02:50:00 by mlemoula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_index(t_list *stack)
{
	int	i;
	int	min_sofar;
	int	index_min_sofar;

	i = 0;
	index_min_sofar = 0;
	if (!stack)
		return (-1);
	min_sofar = stack->content;
	while (stack->next)
	{
		stack = stack->next;
		i++;
		if (stack->content < min_sofar)
		{
			min_sofar = stack->content;
			index_min_sofar = i;
		}
	}
	return (index_min_sofar);
}

void	min_on_top(t_list **stack)
{
	int	n;

	n = get_min_index(*stack);

	if	(n > 0)
	{
		if (n <= (ft_lstsize(*stack) - 1)/2)
			while (n -- > 0)
				ra(stack);
		else
			while (n++ < ft_lstsize(*stack))
				rra(stack);
	}
	
}

void	push_swap(t_list **stack_a, t_list **stack_b)
{
	while (*stack_a)
		pb(stack_a, stack_b);
	while (*stack_b)
	{
		min_on_top(stack_b);
		pa(stack_a, stack_b);
	}
}
