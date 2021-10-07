/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erichell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 18:54:22 by erichell          #+#    #+#             */
/*   Updated: 2021/04/16 18:54:24 by erichell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned long int	i;
	char				*guest;

	i = 0;
	guest = (char *)dest;
	if (!src && !dest)
		return (dest);
	while (i < n)
	{
		guest[i] = ((char *)src)[i];
		i++;
	}
	return (guest);
}
