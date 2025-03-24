/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemoula <mlemoula@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 23:32:06 by mlemoula          #+#    #+#             */
/*   Updated: 2025/03/24 18:27:01 by mlemoula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **a)
{
	t_list	*first;
	t_list	*second;

	if (!*a || !(*a)->next)
		return ;
	first = *a;
	second = (*a)->next;
	*a = second;
	first->next = NULL;
	ft_lstadd_back(a, first);
	write(1, "ra\n", 3);
}

void	rb(t_list **b)
{
	t_list	*first;
	t_list	*second;

	if (!*b || !(*b)->next)
		return ;
	first = *b;
	second = first->next;
	*b = second;
	first->next = NULL;
	ft_lstadd_back(b, first);
	write(1, "rb\n", 3);
}

// void	rr(t_list **a, t_list **b)
// {
// 	t_list	*first;
// 	t_list	*second;

// 	if (!*a || !(*a)->next || !*b || !(*b)->next)
// 		return ;
// 	first = *a;
// 	second = (*a)->next;
// 	*a = second;
// 	first->next = NULL;
// 	ft_lstadd_back(a, first);
// 	first = *b;
// 	second = first->next;
// 	*b = second;
// 	first->next = NULL;
// 	ft_lstadd_back(b, first);
// 	write(1, "rr\n", 3);
// }

void	rra(t_list **a)
{
	t_list	*last;
	t_list	*ante_last;

	if (!*a || !(*a)->next)
		return ;
	last = ft_lstlast(*a);
	ante_last = *a;
	while (ante_last->next != last)
		ante_last = ante_last->next;
	ft_lstadd_front(a, last);
	ante_last->next = NULL;
	write(1, "rra\n", 4);
}

void	rrb(t_list **b)
{
	t_list	*last;
	t_list	*ante_last;

	if (!*b || !(*b)->next)
		return ;
	last = ft_lstlast(*b);
	ante_last = *b;
	while (ante_last->next != last)
		ante_last = ante_last->next;
	ft_lstadd_front(b, last);
	ante_last->next = NULL;
	write(1, "rrb\n", 4);
}

// void	rrr(t_list **a, t_list **b)
// {
// 	t_list	*last;
// 	t_list	*ante_last;
// 	if (!*a || !(*a)->next || !*b || !(*b)->next)
// 		return ;
// 	last = ft_lstlast(*a);
// 	ante_last = *a;
// 	while (ante_last->next != last)
// 		ante_last = ante_last->next;
// 	ft_lstadd_front(a, last);
// 	ante_last->next = NULL;
// 	last = ft_lstlast(*b);
// 	ante_last = *b;
// 	while (ante_last->next != last)
// 		ante_last = ante_last->next;
// 	ft_lstadd_front(b, last);
// 	ante_last->next = NULL;
// 	write(1, "rrr\n", 4);
// }
