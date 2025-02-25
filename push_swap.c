/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemoula <mlemoula@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 01:57:39 by mlemoula          #+#    #+#             */
/*   Updated: 2025/02/25 02:59:48 by mlemoula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_swap(char **argv, int n)
{
	int		i;
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*new_element;

	stack_a = NULL;
	stack_b = NULL;
	i = 0;
	while (i < n)
	{
		new_element = ft_lstnew(ft_atoi(argv[i]));
		ft_lstadd_front(&stack_a, new_element);
		i++;
	}
}

// stop ici on sait mettre le dernier argv{i} en haut de stack_a.
// Reste a code les opérations + mettre en place le tri :))))