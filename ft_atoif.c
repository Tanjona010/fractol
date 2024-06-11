/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: traveloa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:50:09 by traveloa          #+#    #+#             */
/*   Updated: 2024/06/11 08:45:25 by traveloa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

static float	space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

void	check_sign(int *i, char *str, float *sign)
{
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			*sign = -1;
		*i += 1;
	}
}

float	ft_atoif(char *str)
{
	float	out;
	int		i;
	float	sign;
	float	tmp;

	i = 0;
	out = 0;
	sign = 1;
	tmp = 1;
	while (space(str[i]) == 1)
		i++;
	check_sign(&i, str, &sign);
	while (str[++i] >= 48 && str[++i] <= 57)
		out = out * 10 + str[i] - 48;
	if (str[i] == '.')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		tmp = tmp / 10;
		out = out + ((str[i] - 48) * tmp);
		i++;
	}
	return (out * sign);
}
