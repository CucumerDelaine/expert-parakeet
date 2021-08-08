/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 12:44:04 by cdelaine          #+#    #+#             */
/*   Updated: 2021/04/23 12:44:06 by cdelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb(char const *s, char c)
{
	int	nbr;
	int	i;

	nbr = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (i > 0 && s[i] && s[i - 1] == c)
			nbr++;
		if (s[i])
			i++;
	}
	if (s[0] != c)
		nbr++;
	if (nbr == 0 && s[i - 1] == c)
		return (0);
	return (nbr);
}

static char	**ft_nbrr2(char **str, char const *s, char c, int h)
{
	size_t	j;
	int		i;

	j = 0;
	i = 0;
	while (s[++h])
	{
		if (s[h] != c)
			j++;
		else if (h > 0 && s[h - 1] != c)
		{
			str[i] = malloc(sizeof(char) * (j + 1));
			if (!(str[i]))
				return (ft_free_all_split_alloc(str, i));
			j = 0;
			i++;
		}
		if (s[h + 1] == '\0' && s[h] != c)
		{
			str[i] = malloc(sizeof(char) * (j + 1));
			if (!(str[i]))
				return (ft_free_all_split_alloc(str, i));
		}
	}
	return (str);
}

static char	**ft_nbrr(char **str, char const *s, char c)
{
	int		i;
	int		h;
	char	**str2;

	i = 0;
	h = -1;
	str2 = ft_nbrr2(str, s, c, h);
	if (str2 == 0)
		return (0);
	return (str);
}

static char	**ft_copy(char **str, char const *s, char c)
{
	int	j;
	int	i;
	int	h;

	j = 0;
	i = 0;
	h = 0;
	while (s[h])
	{
		if (s[h] != c)
			str[i][j++] = s[h];
		else if (h > 0 && s[h - 1] != c)
		{
			str[i][j] = '\0';
			j = 0;
			i++;
		}
		if (s[h + 1] == '\0' && s[h] != c)
			str[i][j] = '\0';
		h++;
	}
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		strnb;

	if (!s || !*s)
	{
		str = malloc(sizeof(char *) * 1);
		if (!(str))
			return (0);
		*str = (void *)0;
		return (str);
	}
	strnb = nb(s, c);
	str = malloc(sizeof(char *) * (strnb + 1));
	if (!str)
		return (0);
	if (ft_nbrr(str, s, c) != 0)
		ft_copy(str, s, c);
	else
		return (0);
	str[strnb] = (void *)0;
	return (str);
}
