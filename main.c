/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemoula <mlemoula@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:54:56 by mlemoula          #+#    #+#             */
/*   Updated: 2025/03/30 17:21:16 by mlemoula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stacks	stacks;
	int			split_flag;

	stacks.stack_a = NULL;
	stacks.stack_b = NULL;
	stacks.operations = NULL;
	split_flag = 0;
	if (argc == 1)
		return (clean_ext(NULL, argv, split_flag, 1), 1);
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (!argv)
			return (clean_ext(NULL, argv, split_flag, 1), 1);
		split_flag = 1;
	}
	if (!check_param(argc, argv))
		return (clean_ext(NULL, argv, split_flag, 1), 1);
	if (!args_are_sorted(argv, split_flag))
	{
		if (!stack_list(argv, argc, &stacks.stack_a))
			return (clean_ext(&stacks, argv, split_flag, 1), 1);
		sort(&stacks);
	}
	return (print_list(&stacks), clean_ext(&stacks, argv, split_flag, 0), 0);
}
