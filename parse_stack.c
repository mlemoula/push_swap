/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemoula <mlemoula@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 01:57:39 by mlemoula          #+#    #+#             */
/*   Updated: 2025/03/07 18:02:19 by mlemoula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

int	split_argv(char ***argv)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = ft_split((*argv)[1], ' ');
	if (!tmp)
		return (0);
	while (*(tmp + i))
	{
		(*argv)[i + 1] = tmp[i];
		i++;
	}
	(*argv)[i + 1] = NULL;
	free_split(tmp, 1);
	return (1);
}

int	check_param(int argc, char **argv)
{
	int		i;
	int		j;
	long	n;

	i = 1;
	while (i < argc)
	{
		if (!argv[i])
			return (0);
		n = ft_atoi_custom(argv[i]);
		if (n < INT_MIN || n > INT_MAX)
			return (0);
		j = 1;
		while (j < i)
		{
			if (ft_atoi_custom(argv[j]) == n)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	stack_list(char **argv, int n, t_list **stack_a)
{
	int		i;
	int		value;
	// int		error_flag;
	t_list	*new_element;

	i = 1;
	// error_flag = 0;
	while (i < n)
	{
		value = ft_atoi_custom(argv[i]);
		new_element = ft_lstnew(value);
		if (!new_element)
		{
			free_stack(stack_a);
			return (0);
		}
		ft_lstadd_front(stack_a, new_element);
		i++;
	}
	return (1);
}
