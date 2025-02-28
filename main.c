/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemoula <mlemoula@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:54:56 by mlemoula          #+#    #+#             */
/*   Updated: 2025/02/28 03:33:55 by mlemoula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"
///Pour buildin
#include <unistd.h>
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
		argv = ft_split(*(argv + 1), ' ');
		while (argv[argc])
			argc++;
	}
	if (check_param(argc, argv) == 0)
	{
		if (argc == 2)
			free(argv);
		return (1);
	}
	stack_list(argv, argc, &a);
	push_swap(&a, &b);
	free_stack(&a);
	return (0);
}
