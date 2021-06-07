/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 13:15:36 by cdelaine          #+#    #+#             */
/*   Updated: 2021/06/01 13:15:39 by cdelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_init(t_list *flag)
{
	flag->minus = 0;
	flag->wight = 0;
	flag->null = 0;
	flag->dot = -1;
	flag->type = 0;
}

t_list	ft_flag_minus(t_list flag)
{
	flag.minus = 1;
	flag.null = 0;
	flag.wight *= -1;
	return (flag);
}

int	ft_flag_dot(char *str, t_list *flag, va_list args, int start)
{
	int	i;

	i = start;
	i++;
	if (str[start + 1] == '-')
		flag->wight = 0;
	if (str[i] == '*')
	{
		flag->dot = va_arg(args, int);
		i++;
	}
	else
	{
		flag->dot = 0;
		while (ft_isdigit(str[i]))
		{
			flag->dot = (flag->dot * 10) + (str[i] - '0');
			i++;
		}
	}
	return (i);
}

t_list	flag_weight(t_list flag, va_list args)
{
	flag.star = 1;
	flag.wight = va_arg(args, int);
	if (flag.wight < 0)
	{
		flag.minus = 1;
		flag.wight *= -1;
		flag.null = 0;
	}
	return (flag);
}

t_list	ft_flag_digit(char c, t_list flag)
{
	if (flag.star == 1)
		flag.wight = 0;
	flag.wight = (flag.wight * 10) + (c - '0');
	return (flag);
}
