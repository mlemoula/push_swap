/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemoula <mlemoula@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:54:56 by mlemoula          #+#    #+#             */
/*   Updated: 2025/02/28 23:50:43 by mlemoula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"
///Pour buildin
#include <unistd.h>
#include <stdio.h>
///

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !(argv[1][0])))
		return (1);
	else if (argc == 2)
	{
		argc = 1 + split_counter(argv[1], ' ');
		split_argv(&argv);
	}
	if (check_param(argc, argv) == 1)
	{
		stack_list(argv, argc, &a);
		push_swap(&a, &b);
		free_stack(&a);
	}
	return (0);
}