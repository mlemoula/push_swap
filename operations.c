/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemoula <mlemoula@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 23:32:06 by mlemoula          #+#    #+#             */
/*   Updated: 2025/03/13 13:48:58 by mlemoula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
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

void	ss(t_list **a, t_list **b)
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
	if (*b && (*b)->next)
	{
		first = *b;
		second = first->next;
		first->next = second->next;
		second->next = first;
		*b = second;
	}
	write(1, "ss\n", 3);
}

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

void	ra(t_list **a)
{
	t_list	*first;
	t_list	*second;

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

	first = *b;
	second = first->next;
	*b = second;
	first->next = NULL;
	ft_lstadd_back(b, first);
	write(1, "rb\n", 3);
}

void	rr(t_list **a, t_list **b)
{
	t_list	*first;
	t_list	*second;

	first = *a;
	second = (*a)->next;
	*a = second;
	first->next = NULL;
	ft_lstadd_back(a, first);
	first = *b;
	second = first->next;
	*b = second;
	first->next = NULL;
	ft_lstadd_back(b, first);
	write(1, "rr\n", 3);
}

void	rra(t_list **a)
{
	t_list	*last;
	t_list	*ante_last;
	if (*a && (*a)->next)
	{
		last = ft_lstlast(*a);
		ante_last = *a;
		while (ante_last->next != last)
			ante_last = ante_last->next;
		ft_lstadd_front(a, last);
		ante_last->next = NULL;
	}
	write(1, "rra\n", 4);
}

void	rrb(t_list **b)
{
	t_list	*last;
	t_list	*ante_last;
	if (*b && (*b)->next)
	{
		last = ft_lstlast(*b);
		ante_last = *b;
		while (ante_last->next != last)
			ante_last = ante_last->next;
		ft_lstadd_front(b, last);
		ante_last->next = NULL;
	}
	write(1, "rrb\n", 4);
}

void	rrr(t_list **a, t_list **b)
{
	t_list	*last;
	t_list	*ante_last;
	if (*a && (*a)->next)
	{
		last = ft_lstlast(*a);
		ante_last = *a;
		while (ante_last->next != last)
			ante_last = ante_last->next;
		ft_lstadd_front(a, last);
		ante_last->next = NULL;
	}
	if (*b && (*b)->next)
	{
		last = ft_lstlast(*b);
		ante_last = *b;
		while (ante_last->next != last)
			ante_last = ante_last->next;
		ft_lstadd_front(b, last);
		ante_last->next = NULL;
	}
	write(1, "rrr\n", 4);
}
