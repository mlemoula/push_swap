/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemoula <mlemoula@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 01:43:29 by mlemoula          #+#    #+#             */
/*   Updated: 2025/03/20 19:18:40 by mlemoula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

void	free_stacks(t_stacks *stacks)
{
	t_list	*stack;
	t_list	*tmp;

	stack = stacks->stack_a;
	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
	stacks->stack_a = NULL;
	stack = stacks->stack_b;
	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
	stacks->stack_b = NULL;
}

void	free_split(char **argv, int flag)
{
	int	i;

	i = 0;
	if (!argv || flag == 0)
		return ;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

void	error(t_stacks *stacks, char **argv, int split_flag)
{
	if (split_flag)
		free_split(argv, split_flag);
	if (stacks)
		free_stacks(stacks);
	write(2, "Error\n", 6);
}

void	clean_exit(t_stacks *stacks, char **argv, int split_flag)
{
	if (split_flag)
		free_split(argv, split_flag);
	if (stacks)
		free_stacks(stacks);
}
