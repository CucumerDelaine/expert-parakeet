/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaine <cdelaine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:57:02 by cdelaine          #+#    #+#             */
/*   Updated: 2022/03/22 15:11:32 by cdelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

int	ft_strlen2(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

static	size_t	cnt_arr_len(const char *str, char c)
{
	size_t	i;
	size_t	cnt;

	i = 0;
	cnt = 0;
	if (str[i] != 0 && str[i] != c)
		cnt++;
	while (str[i])
	{
		if (str[i] == c)
		{
			if (str[i + 1] != 0 && str[i + 1] != c)
				cnt++;
			i++;
		}
		else
			i++;
	}
	return (cnt);
}	

static	char	*ft_strtok(char const *str, char sep, size_t i)
{
	char	*dest;
	size_t	j;
	size_t	z;

	j = i;
	z = 0;
	while (str[i] != sep && str[i])
		i++;
	dest = (char *)malloc(sizeof(char) * (i - j + 1));
	if (!dest)
		return (NULL);
	while (j != i)
	{
		dest[z] = str[j];
		j++;
		z++;
	}
	dest[z] = 0;
	return (dest);
}

char	**ft_split2(char const *s, char c)
{
	char	**arr;
	char	*tmp;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (!s)
		return (NULL);
	arr = (char **)malloc(sizeof(char *) * (cnt_arr_len(s, c) + 1));
	if (!arr)
		return (NULL);
	arr[cnt_arr_len(s, c)] = NULL;
	while (i < (size_t)ft_strlen2(s))
	{
		tmp = ft_strtok(s, c, i++);
		if (ft_strlen2(tmp) == 0)
			free(tmp);
		else
		{
			arr[j] = tmp;
			i += (size_t)ft_strlen2(arr[j++]);
		}
	}
	return (arr);
}

void	*ft_memcpy2(void *dst, const void *src, size_t n)
{
	char		*dest;
	const char	*source;

	dest = dst;
	source = src;
	if (!dst && !src)
		return (dst);
	while (n-- > 0)
	{
		*dest++ = *source++;
	}
	return (dst);
}
