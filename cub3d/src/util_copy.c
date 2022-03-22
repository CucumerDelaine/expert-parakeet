/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_copy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaine <cdelaine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:10:41 by cdelaine          #+#    #+#             */
/*   Updated: 2022/03/22 15:11:44 by cdelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

void	*ft_memset2(void *b, int c, size_t len)
{
	unsigned char	*dest;

	dest = b;
	while (len-- > 0)
	{
		*dest++ = c;
	}
	return (b);
}

char	*ft_strdup2(const char *s1)
{
	char	*str;
	int		i;

	i = 0;
	if (!s1)
		return (NULL);
	str = (char *)malloc(ft_strlen2(s1) + 1);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

int	ft_strncmp2(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] != '\0' && s2[i] != '\0'
		&& (s1[i] == s2[i]) && (i < n - 1))
		i++;
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}

int	ft_atoi2(const char *str)
{
	int	i;
	int	m;
	int	n;

	n = 0;
	i = 0;
	m = 1;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
	{
		i++;
	}
	if (str[i] == '-')
	{
		m *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while ((str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
	{
		n = n * 10 + (str[i] - 48);
		i++;
	}
	return (m * n);
}

size_t	ft_strlcpy2(char *dst, const char *src, size_t size)
{
	size_t	s_len;
	int		lim;

	lim = size;
	s_len = ft_strlen2(src);
	if (size <= 0)
		return (s_len);
	if (s_len < size)
		lim = s_len;
	while (lim--)
		*dst++ = *src++;
	return (s_len);
}
