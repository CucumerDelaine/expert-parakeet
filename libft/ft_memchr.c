/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 10:59:24 by cdelaine          #+#    #+#             */
/*   Updated: 2021/04/19 10:59:26 by cdelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *arrey, int c, size_t n)
{
	int				i;
	unsigned char	*a;

	a = (unsigned char *)arrey;
	i = 0;
	while (n--)
	{
		if (*a++ == (unsigned char)c)
			return (a - 1);
		i++;
	}
	return (0);
}
