/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erichell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 10:38:11 by erichell          #+#    #+#             */
/*   Updated: 2021/04/19 10:38:13 by erichell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned long int	i;
	unsigned long int	k;

	k = 0;
	while (dst[k] != 0 && k < size)
		k++;
	i = k;
	while (src[k - i] != 0 && (k + 1 < size))
	{
		dst[k] = src[k - i];
		k++;
	}
	if (i < size)
		dst[k] = 0;
	return (i + ft_strlen(src));
}
