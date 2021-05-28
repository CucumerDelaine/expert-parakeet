/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 10:52:42 by cdelaine          #+#    #+#             */
/*   Updated: 2021/05/28 10:52:44 by cdelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_string(char *str, t_list flag)
{
	int j;

	j = 0;
	if (flag.dot == 0)
		j += ft_put("", flag.wight);
	j += put_string(str, flag);
	return (j);
}

int put_string(char *str, t_list flag)
{
	int j;

	j = 0;
    if (flag.dot > ft_strlen(str))
        flag.dot = ft_strlen(str);
	if (flag.minus == 1)
	{
		j += ft_put(str, flag.dot);
	}
	j += print_null(flag.wight, flag.dot, 0);
	if (flag.minus == 0)
		j += ft_put(str, flag.dot);
	return (j);
}
