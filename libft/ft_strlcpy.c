/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 12:21:01 by cdelaine          #+#    #+#             */
/*   Updated: 2021/04/19 12:24:18 by cdelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int size)
{
	unsigned int	z;

	z = 0;
	if (!dest || !src)
		return (0);
	if (size == 0)
		return (ft_strlen(src));
	while (z < size - 1 && src[z] != '\0')
	{
		dest[z] = src[z];
		z++;
	}
	dest[z] = '\0';
	return (ft_strlen(src));
}
