/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 16:26:53 by cdelaine          #+#    #+#             */
/*   Updated: 2021/04/16 16:26:55 by cdelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *str, const void *rev, int c, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;
	unsigned char	sim;

	i = 0;
	sim = (unsigned char)c;
	str1 = (unsigned char *)str;
	str2 = (unsigned char *)rev;
	if (!str && !rev)
		return (str);
	while (i < n)
	{
		str1[i] = str2[i];
		if (str1[i] == sim)
			return (&str1[i + 1]);
		i++;
	}
	return (0);
}
