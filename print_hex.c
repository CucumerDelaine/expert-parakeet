/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 13:17:31 by cdelaine          #+#    #+#             */
/*   Updated: 2021/05/28 13:17:33 by cdelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_hex(va_list args, t_list flag, int a)
{
	unsigned long long int ul;
    int j;

    ul = va_arg(args, unsigned int);

	j = 0;
	if (flag.dot == 0 && ul == 0)
	{
		while (j < flag.wight)
		{
			ft_putchar(' ');
			j++;
		}
		return (j);
	}
	j += put_hex(ul, flag, a);
	return (j);
}

int put_hex(long long ul, t_list flag, int a)
{
	int j;

	j = 0;
    if (flag.dot >= 0 && flag.dot < ft_length_hex(ul))
		flag.dot = ft_length_hex(ul);
	if (flag.minus == 1)
		j += put_hex2(ul, flag, a);
    if (flag.dot > 0)
    {
        flag.wight -= flag.dot;
        j += print_null(flag.wight, 0, 0);
    }
    else
	    j += print_null(flag.wight, ft_length_hex(ul), 0);
	if (flag.minus == 0)
		j += put_hex2(ul, flag, a);
	return (j);
}

int put_hex2(long long ul, t_list flag, int a)
{
	int j;

	j = 0;
    if (flag.dot >= 0)
    {
        print_null(flag.dot, ft_length_hex(ul), 1);
        if (a == 1)
            ft_putnbr_hex(ul);
        else if (a == 0)
            ft_putnbr_hex_XX(ul);
        j += flag.dot;
    }
    return (j);
}

void	ft_putnbr_hex_XX(unsigned long long nb)
{
	if (nb >= 16)
		ft_putnbr_hex_XX(nb / 16);
	if ((nb % 16) >= 10)
		ft_putchar((nb % 16) + 55);
	else if ((nb % 16) < 10)
		ft_putchar((nb % 16) + 48);
}