/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemoula <mlemoula@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:54:56 by mlemoula          #+#    #+#             */
/*   Updated: 2025/02/24 22:09:50 by mlemoula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
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
			return (write(1, "not int", 7), 0);
		j = 1;
		while (j < i)
		{
			if (ft_strncmp(argv[i], argv[j], ft_strlen(argv[j])))
				return (0);
			j++;
		}
		i++;
	}
	// ft_putswap(*argv);
	return (write (1, "ok", 2), 0);
}
