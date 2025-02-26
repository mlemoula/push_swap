/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemoula <mlemoula@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 23:32:06 by mlemoula          #+#    #+#             */
/*   Updated: 2025/02/27 00:31:04 by mlemoula         ###   ########.fr       */
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
	t_list	*last;
	t_list	*tmp;
	if (*a && (*a)->next)
	{
		last = ft_lstlast(*a);
		tmp = *a;
		(*a) = last;
		(*a)->next = tmp;
	}	
}



void	rb(t_list *b);
void	rr(t_list *a, t_list *b);
void	rra(t_list *a);
void	rrb(t_list *b);
void	rrr(t_list *a, t_list *b);