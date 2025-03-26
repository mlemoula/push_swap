/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_custom.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemoula <mlemoula@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:22:30 by mlemoula          #+#    #+#             */
/*   Updated: 2025/03/24 21:05:55 by mlemoula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static int	signe(const char *nptr)
{
	int	s;

	s = 1;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			s = -1;
	}
	return (s);
}

long	ft_atoi_custom(const char *nptr)
{
	long	n;
	int		s;

	n = 0;
	s = signe(nptr);
	if (*nptr == '+' || *nptr == '-')
		nptr++;
	if (*nptr < '0' || *nptr > '9')
		return ((long)(INT_MIN) - 1);
	while (*nptr >= '0' && *nptr <= '9')
	{
		n = 10 * n + (*nptr - '0');
		nptr++;
	}
	if (*nptr != '\0')
		return ((long)(INT_MIN) - 1);
	return (s * n);
}
