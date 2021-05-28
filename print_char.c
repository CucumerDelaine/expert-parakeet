/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 10:31:53 by cdelaine          #+#    #+#             */
/*   Updated: 2021/05/28 10:31:54 by cdelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_char(char c, t_list flag)
{
    int i;

    i = 0;
    if (flag.minus == 1)
        ft_putchar(c);
    i = print_null(flag.wight, 1, 0);
    if (flag.minus == 0)
        ft_putchar(c);
    return (i + 1);
}
