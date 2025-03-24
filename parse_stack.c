/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemoula <mlemoula@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 01:57:39 by mlemoula          #+#    #+#             */
/*   Updated: 2025/03/24 18:27:15 by mlemoula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_param(int argc, char **argv)
{
	int		i;
	int		j;
	long	n;

	i = 1;
	if (argc == 2)
		i = 0;
	if (!argv[i])
		return (0);
	while (argv[i])
	{
		n = ft_atoi_custom(argv[i]);
		if (n < INT_MIN || n > INT_MAX)
			return (0);
		j = 1;
		if (argc == 2)
			j = 0;
		while (j < i)
		{
			if (ft_atoi_custom(argv[j++]) == n)
				return (0);
		}
		i++;
	}
	return (1);
}

int	stack_list(char **argv, int n, t_list **stack_a)
{
	int		i;
	int		value;
	t_list	*new_element;

	i = 1;
	if (n == 2)
		i = 0;
	while (argv[i])
	{
		value = ft_atoi_custom(argv[i]);
		new_element = ft_lstnew(value);
		if (!new_element)
			return (0);
		ft_lstadd_back(stack_a, new_element);
		i++;
	}
	return (1);
}

int	args_are_sorted(char **argv, int split_flag)
{
	int	i;

	if (split_flag)
		i = 0;
	else
		i = 1;
	while (argv[i] && argv[i + 1])
	{
		if (ft_atoi_custom(argv[i + 1]) < ft_atoi_custom(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

int	stack_is_sorted(t_list *stack)
{
	if (!stack || !(stack->next))
		return (1);
	while (stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}
