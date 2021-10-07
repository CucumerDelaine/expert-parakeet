/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erichell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 20:52:16 by erichell          #+#    #+#             */
/*   Updated: 2021/04/19 20:52:18 by erichell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(char const *s, unsigned int start, size_t len)
{
	size_t	l;

	l = ft_strlen(s + start);
	if (l >= len)
		l = len;
	return (l);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t				i;
	char				*low;
	size_t				l;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		low = (char *)malloc(sizeof(char) * 1);
		low[0] = '\0';
		return (low);
		
	}
	l = ft_len(s, start, len);
	low = (char *)malloc(sizeof(char) * l + 1);
	if (!low)
		return (NULL);
	while (i < l)
	{
		low[i] = s[start];
		i++;
		start++;
	}
	low[i] = '\0';
	return (low);
}
