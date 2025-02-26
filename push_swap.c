/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemoula <mlemoula@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 01:57:39 by mlemoula          #+#    #+#             */
/*   Updated: 2025/02/25 23:39:39 by mlemoula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

void	ft_push_stack(char **argv, int n)
{
	int		i;
	int		value;
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*new_element;

	stack_a = NULL;
	stack_b = NULL;
	i = 0;
	while (i < n)
	{
		value = ft_atoi(argv[i]);
		new_element = ft_lstnew(&value);
		ft_lstadd_front(&stack_a, new_element);
		i++;
	}
}

// stop ici on sait mettre le dernier argv{i} en haut de stack_a.
// Reste a code les opérations + mettre en place le tri :))))