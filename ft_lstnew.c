/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemoula <mlemoula@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:49:55 by mlemoula          #+#    #+#             */
/*   Updated: 2025/02/25 02:29:47 by mlemoula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Allocates (with malloc(3)) and returns a new node.
The member variable ’content’ is initialized with the value of the parameter ’content’.
The variable ’next’ is initialized to NULL.
*/

#include "push_swap.h"

t_node	*ft_lstnew(void *content)
{
	struct s_node	*member;

	member = malloc(sizeof(struct s_node));
	if (!member)
		return (NULL);
	(*member).next = NULL;
	(*member).value = content;
	return (member);
}
