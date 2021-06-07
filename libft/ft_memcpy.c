/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 16:11:18 by cdelaine          #+#    #+#             */
/*   Updated: 2021/04/16 16:11:20 by cdelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *str, const void *rev, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)str;
	str2 = (unsigned char *)rev;
	if (n == 0)
		return (str);
	if (!str && !rev)
		return (str);
	while (i < n)
	{
		str1[i] = str2[i];
		i++;
	}
	return (str);
}
