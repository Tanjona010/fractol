/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: traveloa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 09:55:02 by traveloa          #+#    #+#             */
/*   Updated: 2024/03/05 10:37:58 by traveloa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

/*int	main(void)
{
	t_list	*l1;
	t_list	*l2;
	t_list	**ptr;

	l2 = ft_lstnew("l2");
	l1 = ft_lstnew("l1");
	ptr = &l1;	
	ft_lstadd_front(ptr, l2);
	printf("%s", (char *)l2->next->content);
}*/
