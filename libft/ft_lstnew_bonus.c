/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: traveloa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 09:49:55 by traveloa          #+#    #+#             */
/*   Updated: 2024/03/05 09:54:47 by traveloa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof (t_list));
	new->content = content;
	new->next = NULL;
	return (new);
}

/*int	main(void)
{
	t_list	*new;
	new = ft_lstnew("abc");
	printf("%s\n", (char *)new->content);
	free(new);
}*/
