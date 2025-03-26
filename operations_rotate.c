/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemoula <mlemoula@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 23:32:06 by mlemoula          #+#    #+#             */
/*   Updated: 2025/03/26 10:09:46 by mlemoula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stacks *stacks)
{
	t_list	**a;
	t_list	*first;
	t_list	*second;

	a = &stacks->stack_a;
	if (!*a || !(*a)->next)
		return ;
	first = *a;
	second = (*a)->next;
	*a = second;
	first->next = NULL;
	ft_lstadd_back(a, first);
	stock_ope("ra\n", stacks);
}

void	rb(t_stacks *stacks)
{
	t_list	**b;
	t_list	*first;
	t_list	*second;

	b = &stacks->stack_b;
	if (!*b || !(*b)->next)
		return ;
	first = *b;
	second = first->next;
	*b = second;
	first->next = NULL;
	ft_lstadd_back(b, first);
	stock_ope("rb\n", stacks);
}

void	rra(t_stacks *stacks)
{
	t_list	**a;
	t_list	*last;
	t_list	*ante_last;

	a = &stacks->stack_a;
	if (!*a || !(*a)->next)
		return ;
	last = ft_lstlast(*a);
	ante_last = *a;
	while (ante_last->next != last)
		ante_last = ante_last->next;
	ft_lstadd_front(a, last);
	ante_last->next = NULL;
	stock_ope("rra\n", stacks);
}

void	rrb(t_stacks *stacks)
{
	t_list	**b;
	t_list	*last;
	t_list	*ante_last;

	b = &stacks->stack_b;
	if (!*b || !(*b)->next)
		return ;
	last = ft_lstlast(*b);
	ante_last = *b;
	while (ante_last->next != last)
		ante_last = ante_last->next;
	ft_lstadd_front(b, last);
	ante_last->next = NULL;
	stock_ope("rrb\n", stacks);
}
