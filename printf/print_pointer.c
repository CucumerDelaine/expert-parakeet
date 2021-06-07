/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 13:17:20 by cdelaine          #+#    #+#             */
/*   Updated: 2021/05/28 13:17:21 by cdelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pointer(va_list args, t_list flag)
{
	unsigned long long int	ul;
	int						j;

	ul = va_arg(args, long long);
	j = 0;
	if (flag.dot == 0 && ul == 0)
	{
		j += print_null(flag.wight - 2, 0, 0);
		j += ft_put("0x", 2);
		return (j);
	}
	j += put_pointer(ul, flag);
	return (j);
}

int	put_pointer(long long ul, t_list flag)
{
	int	j;

	j = 0;
	if (flag.dot >= 0 && flag.dot < ft_length_hex(ul))
		flag.dot = ft_length_hex(ul);
	if (flag.minus == 1)
		j += put_pointer2(ul, flag);
	if (flag.dot > 0)
	{
		flag.wight -= flag.dot + 2;
		j += print_null(flag.wight, 0, 0);
	}
	else
		j += print_null(flag.wight, ft_length_hex(ul) + 2, 0);
	if (flag.minus == 0)
		j += put_pointer2(ul, flag);
	return (j);
}

int	put_pointer2(long long ul, t_list flag)
{
	int	j;

	j = 0;
	j += ft_put("0x", 2);
	if (flag.dot >= 0)
	{
		print_null(flag.dot, ft_length_hex(ul), 1);
		ft_putnbr_hex(ul);
		j += flag.dot;
	}
	else
	{
		ft_putnbr_hex(ul);
		j += ft_length_hex(ul);
	}
	return (j);
}

int	ft_length_hex(unsigned long long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

void	ft_putnbr_hex(unsigned long long nb)
{
	if (nb >= 16)
		ft_putnbr_hex(nb / 16);
	if ((nb % 16) >= 10)
		ft_putchar((nb % 16) + 87);
	else if ((nb % 16) < 10)
		ft_putchar((nb % 16) + 48);
}
