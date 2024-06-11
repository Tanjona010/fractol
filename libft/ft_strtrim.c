/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: traveloa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:56:16 by traveloa          #+#    #+#             */
/*   Updated: 2024/03/07 07:15:34 by traveloa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	set_chr(char s, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] && s != set[i])
		i++;
	if (i == ft_strlen(set))
		return (0);
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	char	*str;
	int		len;
	int		count;

	str = (char *)s1;
	len = ft_strlen(str) - 1;
	i = 0;
	count = 0;
	while (set_chr(str[i], set) == 1)
		i++;
	while (set_chr(str[len], set) == 1)
	{
		len--;
		count++;
	}
	str = ft_substr(s1, i, ft_strlen(s1) - i - count);
	return (str);
}
