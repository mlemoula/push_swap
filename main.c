/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemoula <mlemoula@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:54:56 by mlemoula          #+#    #+#             */
/*   Updated: 2025/03/04 00:38:22 by mlemoula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

// static void	print_stack(t_list *stack)
// {
// 	while (stack)
// 	{
// 		printf("%d\n", stack->content);
// 		stack = stack->next;
// 	}
// }

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !(argv[1][0])))
		return (write(2, "Error\n", 6), 1);
	else if (argc == 2)
	{
		argc = 1 + split_counter(argv[1], ' ');
		if(!(split_argv(&argv)))
			return (write(2, "Error\n", 6), 1);
	}
	if (!check_param(argc, argv))
		return (write(2, "Error\n", 6), 1);
	if (!stack_list(argv, argc, &a))
		return (free (argv), write(2, "Error\n", 6), 1);
	// printf("stack_a pré tri :\n");
	// print_stack(a);
	push_swap(&a, &b);
	// printf("stack_a post tri :\n");
	// print_stack(a);
	free_stack(&a);
	return (0);
}
