/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_procent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 14:41:41 by cdelaine          #+#    #+#             */
/*   Updated: 2021/05/28 14:41:45 by cdelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_procent(t_list flag)
{
	int	j;

	j = 0;
	if (flag.minus == 1)
		j += ft_putchar('%');
	j += print_null(flag.wight, 1, flag.null);
	if (flag.minus == 0)
		j += ft_putchar('%');
	return (j);
}
