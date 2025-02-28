/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemoula <mlemoula@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 01:57:39 by mlemoula          #+#    #+#             */
/*   Updated: 2025/02/28 03:24:17 by mlemoula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

int	check_param(int argc, char **argv)
{
	int		i;
	int		j;
	int		n;

	i = 1;
	while (i < argc)
	{
		n = ft_atoi(argv[i]);
		if (n < -2147483648 || n > 2147483647)
			return (0);
		j = 1;
		while (j < i)
		{
			if (ft_strncmp(argv[i], argv[j], ft_strlen(argv[j])) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	stack_list(char **argv, int n, t_list **stack_a)
{
	int		i;
	int		value;
	t_list	*new_element;

	i = 0;
	while (i < n)
	{
		value = ft_atoi(argv[i]);
		new_element = ft_lstnew(value);
		ft_lstadd_front(stack_a, new_element);
		i++;
	}
}