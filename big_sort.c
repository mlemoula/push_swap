/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemoula <mlemoula@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:44:15 by mlemoula          #+#    #+#             */
/*   Updated: 2025/04/03 00:30:22 by mlemoula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fill_array(t_list *stack, int *lst)
{
	int		i;
	int		j;
	int		tmp;
	t_list	*current;

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
}

static void	get_quarts(t_list *stack, int *pivots)
{
	int		*lst;

	lst = (int *)malloc(ft_lstsize(stack) * sizeof(int));
	if (!lst)
		return ;
	fill_array(stack, lst);
	pivots[0] = lst[ft_lstsize(stack) / 4];
	pivots[1] = lst[ft_lstsize(stack) / 2];
	pivots[2] = lst[(3 * ft_lstsize(stack)) / 4];
	free(lst);
}

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
		while (size-- && stacks->stack_a && stacks->stack_a->next)
		{
			if (*(int *)stacks->stack_a->content <= lst[i])
			{
				pb(stacks);
				if (stacks->stack_b && stacks->stack_b->next
					&& *(int *)stacks->stack_b->content <= lst[0])
					rb(stacks);
			}
			else
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
		push_max_pair(stacks);
}
