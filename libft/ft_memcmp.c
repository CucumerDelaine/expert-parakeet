/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 11:49:34 by cdelaine          #+#    #+#             */
/*   Updated: 2021/04/19 11:49:37 by cdelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp (const void *arr1, const void *arr2, size_t n)
{
	unsigned char	*a1;
	unsigned char	*a2;
	size_t			i;

	i = 0;
	a1 = (unsigned char *)arr1;
	a2 = (unsigned char *)arr2;
	while (i < n)
	{
		if (a1[i] != a2[i])
			return ((int)(a1[i] - a2[i]));
		i++;
	}
	return (0);
}
