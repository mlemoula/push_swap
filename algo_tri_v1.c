/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_tri_v1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemoula <mlemoula@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 01:34:22 by mlemoula          #+#    #+#             */
/*   Updated: 2025/02/27 11:56:39 by mlemoula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_list **stack_a, t_list **stack_b)
{
	while (*stack_a)
		pb(stack_a, stack_b);
	while (*stack_b)
	{
		
	}
}

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