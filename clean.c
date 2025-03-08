/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemoula <mlemoula@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 01:43:29 by mlemoula          #+#    #+#             */
/*   Updated: 2025/03/08 01:35:49 by mlemoula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

void	free_stack(t_list **stack)
{
	t_list	*tmp;

	if (!stack)
		return ;
	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free (tmp);
	}
	*stack = NULL;
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
