/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ull.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 13:17:43 by cdelaine          #+#    #+#             */
/*   Updated: 2021/05/28 13:17:45 by cdelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_ull(va_list args, t_list flag)
{
	unsigned int ul;
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
	j += put_ull(ul, flag);
	return (j);
}

int put_ull(long long ul, t_list flag)
{
	int j;

	j = 0;
    if (flag.dot >= 0 && flag.dot < ft_length(ul))
		flag.dot = ft_length(ul);
	if (flag.minus == 1)
		j += put_ull2(ul, flag);
    if (flag.dot > 0)
    {
        flag.wight -= flag.dot;
        j += print_null(flag.wight, 0, 0);
    }
    else
	    j += print_null(flag.wight, ft_length(ul), 0);
	if (flag.minus == 0)
		j += put_ull2(ul, flag);
	return (j);
}

int put_ull2(long long ul, t_list flag)
{
	int j;

	j = 0;
    if (flag.dot >= 0)
    {
        print_null(flag.dot, ft_length(ul), 1);
        ft_putnbr_ull(ul);
        j += flag.dot;
    }
    return (j);
}

int	ft_length(long long int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n = n * -1;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

void	ft_putnbr_ull(long long nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr_ull((nb * (-1)));
	}
	else
	{
		if (nb >= 10)
			ft_putnbr_ull(nb / 10);
		ft_putchar((nb % 10) + '0');
	}
}