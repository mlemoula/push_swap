/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemoula <mlemoula@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:00:05 by mlemoula          #+#    #+#             */
/*   Updated: 2025/02/25 02:41:47 by mlemoula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>

typedef struct s_list
{
	int				value;
	struct s_list	*next;
}					t_list;

// typedef struct s_stack
// {
// 	t_list	*top;
// }			t_stack;

void	ft_push_swap(char **argv, int n);

#endif