/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erichell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 11:16:10 by erichell          #+#    #+#             */
/*   Updated: 2021/04/18 13:00:12 by erichell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned long int	i;

	i = 0;
	if (!src && !dest)
		return (NULL);
	while (n > 0 && i < n)
	{
		if (dest > src)
		{
			((char *)dest)[n - 1] = ((char *)src)[n - 1];
			n--;
		}
		else if (dest <= src)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i++;
		}
	}
	return ((char *)dest);
}
