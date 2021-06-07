/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 13:22:32 by cdelaine          #+#    #+#             */
/*   Updated: 2021/04/28 13:22:34 by cdelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*str;
	t_list	*a;

	a = *lst;
	while (a)
	{
		str = a->next;
		ft_lstdelone(a, del);
		a = str;
	}
	*lst = NULL;
}
