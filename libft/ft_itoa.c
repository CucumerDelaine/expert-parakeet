/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 08:55:30 by cdelaine          #+#    #+#             */
/*   Updated: 2021/04/23 08:55:32 by cdelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	stlen(int n)
{
	int				i;
	unsigned int	j;

	i = 0;
	if (n < 0)
	{
		i++;
		j = -n;
	}
	else
		j = n;
	while (j >= 1)
	{
		j = j / 10;
		i++;
	}
	return (i);
}

static char	*itoa3(char *str, int n, int len, unsigned int j)
{
	while (len > 0)
	{
		str[len] = (j % 10) + '0';
		j = j / 10;
		len--;
	}
	if (n > 0)
		str[0] = (j % 10) + '0';
	return (str);
}

static char	*itoa2(char *str, int n)
{
	int				len;
	int				i;
	unsigned int	j;

	i = 0;
	len = stlen(n);
	if (len == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	if (n < 0)
	{
		str[0] = '-';
		j = -n;
	}
	else
		j = n;
	str[len] = '\0';
	len--;
	itoa3(str, n, len, j);
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	i = stlen(n);
	if (i == 0)
		i = 1;
	str = malloc(i + 1);
	if (!(str))
		return (0);
	itoa2(str, n);
	return (str);
}
