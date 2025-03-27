/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemoula <mlemoula@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 01:43:29 by mlemoula          #+#    #+#             */
/*   Updated: 2025/03/26 23:18:09 by mlemoula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_list(t_list **stack, int flag)
{
	t_list	*current;
	t_list	*next;

	current = *stack;
	while (current)
	{
		next = current->next;
		if (flag && current->content)
			free(current->content);
		free(current);
		current = next;
	}
	*stack = NULL;
}

static void	free_stacks(t_stacks *stacks)
{
	free_list(&stacks->stack_a, 1);
	stacks->stack_a = NULL;
	free_list(&stacks->stack_b, 1);
	stacks->stack_b = NULL;
	free_list(&stacks->operations, 0);
	stacks->operations = NULL;
}

static void	free_split(char **argv, int flag)
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

void	clean_ext(t_stacks *stacks, char **argv, int split_flag, int err_flag)
{
	if (split_flag)
		free_split(argv, split_flag);
	if (stacks)
		free_stacks(stacks);
	if (err_flag)
		write(2, "Error\n", 6);
}
