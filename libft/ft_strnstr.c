/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: traveloa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 08:07:03 by traveloa          #+#    #+#             */
/*   Updated: 2024/03/05 08:51:52 by traveloa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <bsd/string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*sbig;
	size_t	i;
	size_t	length;
	int		test;

	i = 0;
	length = ft_strlen(little);
	sbig = (char *)big;
	if (little[0] == '\0')
		return (sbig);
	if (big[0] == '\0')
		return (0);
	while (i < len)
	{
		if (big[i] == little[0] && i + length - 1 < len)
		{
			test = ft_strncmp(&big[i], little, length);
			if (test == 0 && length + i <= len)
				return (&sbig[i]);
		}
		i++;
	}
	return (0);
}
