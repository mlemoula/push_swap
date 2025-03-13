/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_tri_v1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemoula <mlemoula@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 01:34:22 by mlemoula          #+#    #+#             */
/*   Updated: 2025/03/13 15:44:09 by mlemoula         ###   ########.fr       */
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
	int stack_size;

	n = get_min_index(*stack);
	stack_size = ft_lstsize(*stack);
	if	(n > 0)
	{
		if (n <= (stack_size - 1)/2)
			while (n -- > 0)
				ra(stack);
		else
			while (n++ < stack_size)
				rra(stack);
	}
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
	int stack_size;

	n = get_max_index(*stack);
	stack_size = ft_lstsize(*stack);
	if	(n > 0)
	{
		if (n < (stack_size - 1)/2)
			while (n -- > 0)
				ra(stack);
		else
			while (n++ < stack_size)
				rra(stack);
	}
	
}

// void	big_sort_v1(t_stacks *stacks)
// {
// 	t_list	**stack_a;
// 	t_list	**stack_b;

// 	stack_a = &stacks->stack_a;
// 	stack_b = &stacks->stack_b;
// 	while (*stack_a)
// 		pb(stack_a, stack_b);
// 	while (*stack_b)
// 	{
// 		max_on_top(stack_b);
// 		pa(stack_a, stack_b);
// 	}
// }


void	small_sort(t_list **stack_a, int stack_size)
{
	if ((*stack_a)->content > (*stack_a)->next->content)
		sa(stack_a);
	if (stack_size == 3)
	{
		if ((*stack_a)->next->content > (*stack_a)->next->next->content)
		{
			if ((*stack_a)->next->next->content < (*stack_a)->next->content)
				rra(stack_a);
			if ((*stack_a)->next->content < (*stack_a)->content)
				sa(stack_a);
		}
	}
}

void sort(t_stacks *stacks)
{
	t_list	**stack_a;
	t_list	**stack_b;
	int 	stack_size;

	stack_a = &stacks->stack_a;
	stack_b = &stacks->stack_b;
	stack_size = ft_lstsize(*stack_a);

	if (stack_size == 2 || stack_size == 3)
	{
		small_sort(stack_a, stack_size);
		return ;
	}
	else if (stack_size == 4 || stack_size == 5)
	{
		min_on_top(stack_a);		
		pb(stack_a, stack_b);
		sort(stacks);
		pa(stack_a, stack_b);
	}
	// else if (stack_size == 5)
	// {
	// 	min_on_top(stack_a);		
	// 	pb(stack_a, stack_b);
	// 	sort(stacks);
	// 	pa(stack_a, stack_b);
	// }
	else
		big_sort(stacks);
	// print_stack(*stacks);
}
