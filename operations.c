/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemoula <mlemoula@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 23:32:06 by mlemoula          #+#    #+#             */
/*   Updated: 2025/02/27 12:22:49 by mlemoula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

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
}

void	ss(t_list **a, t_list **b)
{
	sa(a);
	sb(b);
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
}

void	ra(t_list **a)
{
	t_list	*second;

	second = (*a)->next;
	(*a)->next = NULL;
	ft_lstadd_back(a, *a);
	*a = second;
}

void	rb(t_list **b)
{
	t_list	*second;

	second = (*b)->next;
	(*b)->next = NULL;
	ft_lstadd_back(b, *b);
	*b = second;
}

void	rr(t_list **a, t_list **b)
{
	ra(a);
	rb(b);
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
}

void	rrr(t_list **a, t_list **b)
{
	rra(a);
	rrb(b);
}
