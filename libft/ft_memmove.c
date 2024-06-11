/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: traveloa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 07:52:38 by traveloa          #+#    #+#             */
/*   Updated: 2024/03/05 08:48:22 by traveloa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*strsrc;
	char	*strdest;

	strsrc = (char *)src;
	strdest = (char *)dest;
	if (!strsrc && !strdest)
		return (0);
	if (src >= dest)
	{
		ft_memcpy(dest, src, n);
	}
	else
	{
		while (n > 0)
		{
			strdest[n - 1] = strsrc[n - 1];
			n--;
		}
	}
	return (dest);
}
