/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: traveloa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:50:09 by traveloa          #+#    #+#             */
/*   Updated: 2024/03/05 08:44:37 by traveloa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int		out;
	char	*str;
	int		i;
	int		tmp;

	i = 0;
	out = 0;
	tmp = 1;
	str = (char *)nptr;
	while (space(str[i]) == 1)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			tmp = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		out = out * 10 + str[i] - 48;
		i++;
	}
	return (out * tmp);
}
