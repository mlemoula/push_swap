/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemoula <mlemoula@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 01:43:29 by mlemoula          #+#    #+#             */
/*   Updated: 2025/02/28 01:50:42 by mlemoula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

void	free_stack(t_list **stack)
{
	t_list	*tmp;
	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free (tmp);
	}
	*stack = NULL;
}