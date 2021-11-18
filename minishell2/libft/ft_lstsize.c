/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaine <cdelaine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:48:57 by cdelaine          #+#    #+#             */
/*   Updated: 2021/11/18 12:49:27 by cdelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		len;
	t_list	*lok;

	len = 0;
	lok = lst;
	if (lst)
	{
		while (lok->next != NULL)
		{
			lok = lok->next;
			len++;
		}
		if (lok->next == NULL)
			len++;
	}
	return (len);
}
