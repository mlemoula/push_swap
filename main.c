/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemoula <mlemoula@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:54:56 by mlemoula          #+#    #+#             */
/*   Updated: 2025/03/10 01:24:07 by mlemoula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

///tests
void	print_stack(t_stacks stacks)
{
printf("stack_a :\n");
t_list *tmp = NULL;
	if (stacks.stack_a)
		tmp = stacks.stack_a;
	while (tmp)
	{
		printf("%d\n", tmp->content);
		tmp = tmp->next;
	}
	printf("stack_b :\n");
	if (stacks.stack_b)
	tmp = stacks.stack_b;
	while (tmp)
	{
		printf("%d\n", tmp->content);
		tmp = tmp->next;
	}
}
///

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
		split_flag = 1;
	}
	if (!check_param(argc, argv))
		return (error(NULL, argv, split_flag), 1);
	if (!stack_list(argv, argc, &stacks.stack_a))
		return (error(&stacks, argv, split_flag), 1);
	push_swap(&stacks);
	// print_stack(stacks);
	free_stacks(&stacks);
	return (0);
}
