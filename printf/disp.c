/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 13:17:10 by cdelaine          #+#    #+#             */
/*   Updated: 2021/06/01 13:17:14 by cdelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put(char *str, int j)
{
	int	i;

	i = 0;
	while (str[i] && i < j)
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	print_null(int str1, int str2, int null)
{
	int	i;

	i = 0;
	while (i < (str1 - str2))
	{
		if (null)
			ft_putchar('0');
		else
			ft_putchar(' ');
		i++;
	}
	return (i);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
