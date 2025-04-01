/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push_swap.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemoula <mlemoula@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 19:25:23 by mlemoula          #+#    #+#             */
/*   Updated: 2025/03/31 23:31:02 by mlemoula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stacks *stacks)
{
	t_list	*first;
	t_list	*second;
	t_list	**a;

	a = &stacks->stack_a;
	if (*a && (*a)->next)
	{
		first = *a;
		second = first->next;
		first->next = second->next;
		second->next = first;
		*a = second;
	}
	stock_ope("sa\n", stacks);
}

void	sb(t_stacks *stacks)
{
	t_list	*first;
	t_list	*second;
	t_list	**b;

	b = &stacks->stack_b;
	if (*b && (*b)->next)
	{
		first = *b;
		second = first->next;
		first->next = second->next;
		second->next = first;
		*b = second;
	}
	stock_ope("sb\n", stacks);
}

void	pa(t_stacks *stacks)
{
	t_list	*tmp;
	t_list	**a;
	t_list	**b;

	a = &stacks->stack_a;
	b = &stacks->stack_b;
	if (*b)
	{
		tmp = (*b)->next;
		ft_lstadd_front(a, *b);
		*b = tmp;
	}
	stock_ope("pa\n", stacks);
}

void	pb(t_stacks *stacks)
{
	t_list	*tmp;
	t_list	**a;
	t_list	**b;

	a = &stacks->stack_a;
	b = &stacks->stack_b;
	if (*a)
	{
		tmp = (*a)->next;
		ft_lstadd_front(b, *a);
		*a = tmp;
	}
	stock_ope("pb\n", stacks);
}
