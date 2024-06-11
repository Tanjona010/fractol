/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: traveloa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:38:49 by traveloa          #+#    #+#             */
/*   Updated: 2024/03/05 10:43:37 by traveloa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

/*int	main(void)
{
	t_list	l1;
	t_list	l2;
	t_list	l3;
	t_list	*ptr;

	l1.next = &l2;
	l2.next = &l3;
	l3.next = 0;
	ptr = &l1;
	printf("%d\n", ft_lstsize(ptr));
}*/
