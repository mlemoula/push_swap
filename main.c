/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemoula <mlemoula@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:54:56 by mlemoula          #+#    #+#             */
/*   Updated: 2025/03/20 19:42:13 by mlemoula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "./libft/libft.h"
#include "push_swap.h"

//////test.c à supprimer du makefile

int	main(int argc, char *argv[])
{
	t_stacks	stacks;
	int			split_flag;

	stacks.stack_a = NULL;
	stacks.stack_b = NULL;
	split_flag = 0;
	if (argc == 1)
		return (error(NULL, argv, split_flag), 1);
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (!argv)
			return (error(NULL, argv, split_flag), 1);
		split_flag = 1;
	}
	if (!check_param(argc, argv))
		return (error(NULL, argv, split_flag), 1);
	if (!is_sorted(argv, split_flag))
	{
		if (!stack_list(argv, argc, &stacks.stack_a))
			return (error(&stacks, argv, split_flag), 1);
		sort(&stacks);
	}
	clean_exit(&stacks, argv, split_flag);
	return (0);
}
