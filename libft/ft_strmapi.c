/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: traveloa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 09:47:28 by traveloa          #+#    #+#             */
/*   Updated: 2024/03/01 10:08:09 by traveloa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	len;
	unsigned int	i;

	i = 0;
	len = ft_strlen(s);
	str = malloc (len + 1);
	if (str == 0)
		return (0);
	if (str == NULL)
		return (0);
	while (len > 0)
	{
		str[i] = (*f)(i, s[i]);
		i++;
		len--;
	}
	str[i] = '\0';
	return (str);
}
