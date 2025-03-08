/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemoula <mlemoula@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:54:56 by mlemoula          #+#    #+#             */
/*   Updated: 2025/03/08 02:16:53 by mlemoula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"


// #include <stdio.h>
// static void	print_stack(t_list *stack)
// {
// printf("stack_a post tri :\n");
// 	while (stack)
// 	{
// 		printf("%d\n", stack->content);
// 		stack = stack->next;
// 	}
// }

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;

	// a = malloc(sizeof(t_list));
	// b = malloc(sizeof(t_list));
	a = NULL;
	b = NULL;
	if (argc == 1)
		return (write(2, "Error\n", 6), 1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	if (!check_param(argc, argv))
		return (write(2, "Error\n", 6), 1);
	if (!stack_list(argv, argc, &a))
	//stack_a est cleanée dans stack_list si pb d'allocation
		return (write(2, "Error\n", 6), 1);
	push_swap(&a, &b);
	// print_stack(a);
	free_stack(&a);
	return (0);
}
