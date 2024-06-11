/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: traveloa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 10:19:53 by traveloa          #+#    #+#             */
/*   Updated: 2024/03/07 07:17:29 by traveloa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

static int	len(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != c)
			i++;
		else
			return (i);
	}
	return (i);
}

static void	ft_free(char **ptr, int row)
{
	while (row > 0)
	{
		free(ptr[row]);
		row--;
	}
}

static char	**split_str(char const *s, char c, char **ptr)
{
	int	row;
	int	i;
	int	length;

	row = 0;
	i = 0;
	while (row < count(s, c))
	{
		if (s[i] == c)
			i++;
		else
		{
			length = len(&s[i], c);
			ptr[row] = ft_substr(s, i, length);
			if (ptr[row] == 0)
			{
				ft_free(ptr, row);
				return (0);
			}
			i = i + length + 1;
			row++;
		}
	}
	ptr[row] = NULL;
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		word;

	word = count(s, c);
	ptr = malloc((word + 1) * sizeof (char *));
	if (ptr == 0)
		return (0);
	ptr = split_str(s, c, ptr);
	if (ptr == 0)
		free(ptr);
	return (ptr);
}
