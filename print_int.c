/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 10:24:09 by cdelaine          #+#    #+#             */
/*   Updated: 2021/05/28 10:24:13 by cdelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_int(int i, t_list flag)
{
	int j;
	int save;
	char *str;

	j = 0;
	save = i;
	if (flag.dot == 0 && i == 0)
	{
		while (j < flag.wight)
		{
			ft_putchar(' ');
			j++;
		}
		return (j);
	}
	else if (i < 0 && (flag.dot >= 0 || flag.null == 1))
	{
	    if (flag.null == 1 && flag.dot == -1)
	        ft_putchar('-');
		i = -i;
		j++;
		flag.wight--;
	}
	str = ft_itoa(i);
	j += put_int(str, save, flag);
	free (str);
	return (j);
}

int put_int(char *str, int save, t_list flag)
{
	int j;

	j = 0;
	if (flag.minus == 1)
	{
		j += put_int2(str, save, flag);
	}
	if (flag.dot >= 0 && flag.dot < ft_strlen(str))
		flag.dot = ft_strlen(str);
	if (flag.dot > 0)
	{
		flag.wight -= flag.dot;
		j += print_null(flag.wight, 0, 0);
	}
	else
		j += print_null(flag.wight, ft_strlen(str), flag.null);
	if (flag.minus == 0)
		j += put_int2(str, save, flag);
	return (j);
}

int put_int2(char *str, int save, t_list flag)
{
	int j;

	j = 0;
	if (save < 0 && flag.dot >= 0)
		ft_putchar('-');
	if (flag.dot >= 0)
		j += print_null(flag.dot - 1, ft_strlen(str) - 1, 1);
	j += ft_put(str, ft_strlen(str));
	return (j);
}
