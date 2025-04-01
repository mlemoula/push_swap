/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemoula <mlemoula@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:44:15 by mlemoula          #+#    #+#             */
/*   Updated: 2025/04/01 16:06:51 by mlemoula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static int	above_piv(t_list *stack, int pivot)
// {
// 	if (!stack)
// 		return (0);
// 	while (stack)
// 	{
// 		if (*(int *)stack->content <= pivot)
// 			return (0);
// 		stack = stack->next;
// 	}
// 	return (1);
// }

static void	max_on_top(t_stacks *stacks)
{
	int	n;
	int	size;

	if (!stacks->stack_b || !(stacks->stack_b)->next)
		return ;
	n = get_max_index(stacks->stack_b);
	size = ft_lstsize(stacks->stack_b);
	if (n == 0)
		return ;
	if (n <= (size - 1) / 2)
	{
		while (n-- > 0)
			rb(stacks);
	}
	else
	{
		while (n++ < size)
			rrb(stacks);
	}
}

// static int	get_pivot(t_list *stack)
// {
// 	long	min;
// 	long	max;
// 	long	pivot;
// 	t_list	*current;

// 	if (!stack)
// 		return (0);
// 	current = stack;
// 	max = 0;
// 	min = *(int *)current->content;
// 	max = *(int *)current->content;
// 	while (current)
// 	{
// 		if (*(int *)current->content > max)
// 			max = *(int *)current->content;
// 		if (*(int *)current->content < min)
// 			min = *(int *)current->content;
// 		current = current->next;
// 	}
// 	pivot = (min + max) / 2;
// 	return ((int)pivot);
// }

static void	get_quarts(t_list *stack, int *pivots)
{
	int		*lst;
	int		i;
	int		j;
	int		tmp;
	t_list	*current;

	lst = (int *)malloc(ft_lstsize(stack) * sizeof(int));
	if (!lst)
		return ;
	i = 0;
	current = stack;
	while (current && current->next)
	{
		lst[i++] = *(int *)current->content;
		current = current->next;
	}
	i = 1;
	while (i < ft_lstsize(stack))
	{
		tmp = lst[i];
		j = i - 1;
		while (j >= 0 && lst[j] > tmp)
		{
			lst[j + 1] = lst[j];
			j--;
		}
		lst [j + 1] = tmp;
		i++;
	}
	pivots[0] = lst[ft_lstsize(stack) / 4];
	pivots[1] = lst[ft_lstsize(stack) / 2];
	pivots[2] = lst[(3 * ft_lstsize(stack)) / 4];
	free(lst);
}

// static void	divide_by_pivot(t_stacks *stacks)
// {
// 	int	pivot_a;
// 	int	pivot_b;
// 	int	loops;

// 	pivot_a = get_pivot(stacks->stack_a);
// 	loops = ft_lstsize(stacks->stack_a);
// 	while (loops-- && stacks->stack_a && !above_piv(stacks->stack_a, pivot_a))
// 	{
// 		pivot_b = get_pivot(stacks->stack_b);
// 		if (*(int *)stacks->stack_a->content <= pivot_a)
// 		{
// 			pb(stacks);
// 			if (stacks->stack_b && stacks->stack_b->next &&
// 				*(int *)stacks->stack_b->content > pivot_b)
// 				rb(stacks);
// 		}
// 		else if (stacks->stack_a && stacks->stack_a->next)
// 		{
// 			if (stacks->stack_b && stacks->stack_b->next &&
// 				*(int *)stacks->stack_b->content > pivot_b)
// 				rb(stacks);
// 			ra(stacks);
// 		}
// 	}
// }

static void	divide_by_pivots(t_stacks *stacks)
{
	int	i;
	int	lst[3];
	int	size;

	get_quarts(stacks->stack_a, lst);
	i = 1;
	size = ft_lstsize(stacks->stack_a);
	while (size > 1 && i < 3)
	{
		while (size--)
		{
			if (*(int *)stacks->stack_a->content <= lst[i])
			{
				pb(stacks);
				if (stacks->stack_b && stacks->stack_b->next &&
					*(int *)stacks->stack_b->content <= lst[0])
					rb(stacks);
			}
			else if (stacks->stack_a && stacks->stack_a->next)
				ra(stacks);
		}
		i++;
		size = ft_lstsize(stacks->stack_a);
	}
}

void	big_sort(t_stacks *stacks)
{
	if (stack_is_sorted(stacks->stack_a))
		return ;
	divide_by_pivots(stacks);
	if (!stack_is_sorted(stacks->stack_a))
		sort(stacks);
	while (stacks->stack_b)
	{
		max_on_top(stacks);
		pa(stacks);
	}
}
