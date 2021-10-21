/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erichell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 16:14:29 by erichell          #+#    #+#             */
/*   Updated: 2021/04/18 16:14:33 by erichell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_town(char *temp, char *finish, int i, int num)
{
	if (!finish)
		return (0);
	if (temp[0] == '-')
	{
		finish[num] = temp[0];
		num++;
	}
	while (i >= 0 && (temp[i] != '-'))
	{
		finish[num] = temp[i] + '0';
		num++;
		i--;
	}
	finish[num] = '\0';
	return (finish);
}

char	*ft_itoa(int n)
{
	int		num;
	int		i;
	char	temp[20];
	char	*finish;

	num = 0;
	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		n = -n;
		temp[i++] = '-';
	}
	while (n >= 10)
	{
		temp[i++] = n % 10;
		n /= 10;
	}
	temp[i] = n;
	finish = ((char *)malloc(sizeof(char) * (i + 2)));
	if (!finish)
		return (NULL);
	finish = ft_town(temp, finish, i, num);
	return (finish);
}
