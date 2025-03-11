/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemoula <mlemoula@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 01:57:39 by mlemoula          #+#    #+#             */
/*   Updated: 2025/03/11 02:20:04 by mlemoula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

// int	split_argv(char ***argv, int *flag, int argc)
// {
// 	int		i;
// 	char	**tmp;

// 	i = 0;
// 	tmp = ft_split((*argv)[1], ' ');
// 	if (!tmp)
// 		return (0);
// 	if (argc > 500)
// 	{
// 		*argv = malloc(sizeof(char **));
// 		*flag = 1;
// 	}
// 	while (tmp[i])
// 	{
// 		(*argv)[i + 1] = tmp[i];
// 		i++;
// 	}
// 	(*argv)[i + 1] = NULL;
// 	free(tmp);
// 	return (1);
// }

int	check_param(int argc, char **argv)
{
	int		i;
	int		j;
	long	n;

	i = 1;
	if (argc == 2)
		i = 0;
	if	(!argv[i])
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

int	is_sorted(char **argv, int split_flag)
{
	int	i;

	if (split_flag)
		i = 0;
	else
		i = 1;
	while(argv[i] && argv[i + 1])
	{
		if (ft_atoi_custom(argv[i + 1]) < ft_atoi_custom(argv[i]))
			return (0);
		i++;
	}
	return (1);
}