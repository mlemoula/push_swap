/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemoula <mlemoula@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:54:56 by mlemoula          #+#    #+#             */
/*   Updated: 2025/02/17 19:04:26 by mlemoula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/ft_atoi.c"
//Pour buildin
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc < 2)
		return (0);
	i = 1;
	int	*stack_a[argc];
	while (i < argc)
	{
		if (!(ft_atoi(argv[i]) >= -2147483648 && ft_atoi(argv[i]) <= 2147483647))
			return (write(1, "Salut", 5), 0);
		
		j = 1;
		while (j < i)
		{
			if (*argv[i] == *argv[j])
				return (0);
			j++;
		}
		i++;
	}
	// ft_putswap(*argv);
	return (write (1, "ok", 2), 0);
}
