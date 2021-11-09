/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erichell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 12:07:55 by erichell          #+#    #+#             */
/*   Updated: 2021/04/19 12:07:56 by erichell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!ft_isascii(c))
		return ((char *)s);
	while (*s)
	{
		s++;
		i++;
	}
	while (i >= 0)
	{
		if (*s == c)
			return ((char *)s);
		else
		{
			i--;
			s--;
		}
	}
	return (NULL);
}
