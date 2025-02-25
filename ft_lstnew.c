/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemoula <mlemoula@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:49:55 by mlemoula          #+#    #+#             */
/*   Updated: 2025/02/25 03:06:34 by mlemoula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Allocates (with malloc(3)) and returns a new node.
The member variable ’content’ is initialized with the value of the parameter ’content’.
The variable ’next’ is initialized to NULL.
*/

#include "push_swap.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*member;

	member = malloc(sizeof(struct s_list));
	if (!member)
		return (NULL);
	(*member).next = NULL;
	(*member).value = content;
	return (member);
}
