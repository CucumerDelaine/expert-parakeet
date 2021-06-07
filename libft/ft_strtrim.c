/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 08:48:53 by cdelaine          #+#    #+#             */
/*   Updated: 2021/04/23 08:48:55 by cdelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check(char c, const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (c == s[i])
			return (0);
		i++;
	}
	return (1);
}

char	*check_str(char *str)
{
	str = ft_strdup("");
	if (!(str))
		return (NULL);
	else
		return (str);
}

char	*strim1(char const *s1, int start, int end, char *str)
{
	int	i;

	i = 0;
	while (start < end)
	{
		str[i] = s1[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	char	*str;

	start = 0;
	i = 0;
	str = NULL;
	if (!s1)
		return (NULL);
	if (!set)
		return ((char *)s1);
	end = ft_strlen((char *)s1);
	while (check(s1[start], set) == 0)
		start++;
	if (start == end)
		return (check_str(str));
	while (check(s1[end - 1], set) == 0)
		end--;
	str = malloc(end - start + 1);
	if (!(str))
		return (NULL);
	strim1(s1, start, end, str);
	return (str);
}
