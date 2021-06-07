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

int	put_string(char *str, t_list flag)
{
	int	j;

	j = 0;
	if (flag.dot >= 0)
	{
		j += print_null(flag.dot, ft_strlen(str), 0);
		j += ft_put(str, flag.dot);
	}
	else
		j += ft_put(str, ft_strlen(str));
	return (j);
}

int	ft_print_string(char *str, t_list flag)
{
	int	j;

	j = 0;
	if (!str)
		str = "(null)";
	if (flag.dot > ft_strlen(str))
		flag.dot = ft_strlen(str);
	if (flag.minus == 1)
		j += put_string(str, flag);
	if (flag.dot >= 0)
		j += print_null(flag.wight, flag.dot, 0);
	else
		j += print_null(flag.wight, ft_strlen(str), flag.null);
	if (flag.minus == 0)
		j += put_string(str, flag);
	return (j);
}
