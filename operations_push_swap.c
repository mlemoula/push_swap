/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push_swap.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemoula <mlemoula@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 19:25:23 by mlemoula          #+#    #+#             */
/*   Updated: 2025/03/24 18:25:42 by mlemoula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **a)
{
	t_list	*first;
	t_list	*second;

	if (*a && (*a)->next)
	{
		first = *a;
		second = first->next;
		first->next = second->next;
		second->next = first;
		*a = second;
	}
	write(1, "sa\n", 3);
}

void	sb(t_list **b)
{
	t_list	*first;
	t_list	*second;

	if (*b && (*b)->next)
	{
		first = *b;
		second = first->next;
		first->next = second->next;
		second->next = first;
		*b = second;
	}
	write(1, "sb\n", 3);
}

// void	ss(t_list **a, t_list **b)
// {
// 	t_list	*first;
// 	t_list	*second;
// 	if (*a && (*a)->next)
// 	{
// 		first = *a;
// 		second = first->next;
// 		first->next = second->next;
// 		second->next = first;
// 		*a = second;
// 	}
// 	if (*b && (*b)->next)
// 	{
// 		first = *b;
// 		second = first->next;
// 		first->next = second->next;
// 		second->next = first;
// 		*b = second;
// 	}
// 	write(1, "ss\n", 3);
// }

void	pa(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (*b)
	{
		tmp = (*b)->next;
		ft_lstadd_front(a, *b);
		*b = tmp;
	}
	write(1, "pa\n", 3);
}

void	pb(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (*a)
	{
		tmp = (*a)->next;
		ft_lstadd_front(b, *a);
		*a = tmp;
	}
	write(1, "pb\n", 3);
}
