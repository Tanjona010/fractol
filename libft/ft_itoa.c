/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: traveloa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 08:15:14 by traveloa          #+#    #+#             */
/*   Updated: 2024/03/05 08:47:25 by traveloa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	count_d(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (10);
	if (n < 0)
		n = n * -1;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*putnb(int i, int n, char *out)
{
	int	d;
	int	sign;

	sign = 1;
	d = count_d(n);
	out[i] = '\0';
	while (d > 0)
	{
		if (n < 0)
		{
			out[0] = '-';
			sign = -1;
		}
		out[i - 1] = (n % 10) * sign + 48;
		n = n / 10;
		d--;
		i--;
	}
	return (out);
}

char	*ft_itoa(int n)
{
	char	*out;
	int		i;

	i = count_d(n);
	if (n < 0)
		i = i + 1;
	out = malloc (i + 1);
	if (!out)
		return (0);
	return (putnb(i, n, out));
}
