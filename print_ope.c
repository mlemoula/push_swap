/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ope.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemoula <mlemoula@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:11:34 by mlemoula          #+#    #+#             */
/*   Updated: 2025/04/03 00:32:49 by mlemoula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	compare_ope(char *s1, char *s2, t_list *current)
{
	char	*ope_current;
	char	*ope_next;
	int		l;

	ope_current = (char *)current->content;
	ope_next = (char *)current->next->content;
	l = ft_strlen(ope_current);
	if ((!ft_strncmp(ope_current, s1, l) && !ft_strncmp(ope_next, s2, l))
		|| (!ft_strncmp(ope_current, s2, l) && !ft_strncmp(ope_next, s1, l)))
		return (1);
	else
		return (0);
}

static void	combine_operations(char *s1, char *s2, t_stacks *stacks)
{
	t_list	*current;
	t_list	*next;
	int		l;

	current = stacks->operations;
	l = ft_strlen(s1);
	while (current && current->next)
	{
		next = current->next;
		if (compare_ope(s1, s2, current))
		{
			if (!ft_strncmp(s1, "rra\n", l))
				current->content = "rrr\n";
			else if (!ft_strncmp(s1, "ra\n", l))
				current->content = "rr\n";
			else if (!ft_strncmp(s1, "sa\n", l))
				current->content = "ss\n";
			current->next = next->next;
			free(next);
		}
		else
			current = current->next;
	}
}

static void	erase_operations(char *s1, char *s2, t_stacks *stacks)
{
	t_list	*current;
	t_list	*next;
	t_list	**prev_next;

	current = stacks->operations;
	prev_next = &stacks->operations;
	while (current && current->next)
	{
		next = current->next;
		if (compare_ope(s1, s2, current))
		{
			*prev_next = next->next;
			free(next);
			free(current);
		}
		else
		{
			prev_next = &current->next;
		}
		current = *prev_next;
	}
}

static int	optimize(t_stacks *stacks)
{
	int	size_before;
	int	size_after;

	size_before = ft_lstsize(stacks->operations);
	erase_operations("ra\n", "rra\n", stacks);
	erase_operations("rb\n", "rrb\n", stacks);
	erase_operations("rr\n", "rrr\n", stacks);
	erase_operations("pa\n", "pb\n", stacks);
	erase_operations("sa\n", "sa\n", stacks);
	erase_operations("sb\n", "sb\n", stacks);
	erase_operations("ss\n", "ss\n", stacks);
	combine_operations("ra\n", "rb\n", stacks);
	combine_operations("rra\n", "rrb\n", stacks);
	combine_operations("sa\n", "sb\n", stacks);
	size_after = ft_lstsize(stacks->operations);
	return (size_before - size_after);
}

void	print_list(t_stacks *stacks)
{
	t_list	*tmp;
	int		flag;

	tmp = NULL;
	flag = 1;
	while (flag)
		flag = optimize(stacks);
	if (stacks->operations)
		tmp = stacks->operations;
	while (tmp)
	{
		ft_putstr_fd((char *)tmp->content, 1);
		tmp = tmp->next;
	}
}
