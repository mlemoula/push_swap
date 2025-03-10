/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_tri_v1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemoula <mlemoula@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 01:34:22 by mlemoula          #+#    #+#             */
/*   Updated: 2025/03/10 00:58:34 by mlemoula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	get_min_index(t_list *stack)
// {
// 	int	i;
// 	int	min_sofar;
// 	int	index_min_sofar;

// 	i = 0;
// 	index_min_sofar = 0;
// 	if (!stack)
// 		return (-1);
// 	min_sofar = stack->content;
// 	while (stack->next)
// 	{
// 		stack = stack->next;
// 		i++;
// 		if (stack->content < min_sofar)
// 		{
// 			min_sofar = stack->content;
// 			index_min_sofar = i;
// 		}
// 	}
// 	return (index_min_sofar);
// }

// void	min_on_top(t_list **stack)
// {
// 	int	n;

// 	n = get_min_index(*stack);
// 	if	(n > 0)
// 	{
// 		if (n <= (ft_lstsize(*stack) - 1)/2)
// 			while (n -- > 0)
// 				ra(stack);
// 		else
// 			while (n++ < ft_lstsize(*stack))
// 				rra(stack);
// 	}
	
// }


int	get_max_index(t_list *stack)
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

void	max_on_top(t_list **stack)
{
	int	n;

	n = get_max_index(*stack);
	if	(n > 0)
	{
		if (n < (ft_lstsize(*stack) - 1)/2)
			while (n -- > 0)
				ra(stack);
		else
			while (n++ < ft_lstsize(*stack))
				rra(stack);
	}
	
}

void	push_swap(t_stacks *stacks)
{
	t_list	**stack_a;
	t_list	**stack_b;

	stack_a = &stacks->stack_a;
	stack_b = &stacks->stack_b;
	while (*stack_a)
		pb(stack_a, stack_b);
	while (*stack_b)
	{
		max_on_top(stack_b);
		pa(stack_a, stack_b);
	}
}
