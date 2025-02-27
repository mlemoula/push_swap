/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemoula <mlemoula@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:54:56 by mlemoula          #+#    #+#             */
/*   Updated: 2025/02/27 11:57:44 by mlemoula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"
///Pour buildin
#include <unistd.h>
///

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	int	n;

	if (argc < 2)
		return (0);
	i = 1;
	while (i < argc)
	{
		n = ft_atoi((const char *)argv[i]);
		if (!(n >= -2147483648 && n <= 2147483647))
			return (write(1, "exit l31", 8), 0);
		j = 1;
		while (j < i)
		{
			if (ft_strncmp(argv[i], argv[j], ft_strlen(argv[j])))
				return (0);
			j++;
		}
		i++;
	}
	stack_list(argv, argc);
	return (write (1, "exit l42", 8), 0);
}
