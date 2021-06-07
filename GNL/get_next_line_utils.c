/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 11:08:02 by cdelaine          #+#    #+#             */
/*   Updated: 2021/05/12 11:08:04 by cdelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

void	*ft_memmove(void *destination, const void *source, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	i = 0;
	d = (unsigned char *)destination;
	s = (unsigned char *)source;
	if (!destination && !source)
		return (destination);
	if (source > destination)
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (i--)
			d[i] = s[i];
	}
	return (destination);
}

char	*strjoin(char const *str1, char const *str2)
{
	size_t		s1;
	size_t		s2;
	size_t		slen;
	char		*str;

	if (!str1 && !str2)
		return (0);
	s1 = ft_strlen((char *)str1);
	s2 = ft_strlen((char *)str2);
	slen = s1 + s2 + 1;
	str = malloc(sizeof(char) * slen);
	if (!str)
		return (0);
	ft_memmove(str, str1, s1);
	ft_memmove(str + s1, str2, s2);
	str[slen - 1] = '\0';
	free((char *)str1);
	return (str);
}

int	on_return(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
