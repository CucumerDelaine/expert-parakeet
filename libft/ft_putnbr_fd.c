/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 08:56:32 by cdelaine          #+#    #+#             */
/*   Updated: 2021/04/23 08:56:33 by cdelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	j;
	unsigned int	e;

	j = 0;
	if (n < 0)
	{
		e = -n;
		write(fd, "-", 1);
	}
	else
		e = n;
	if (e >= 10)
		ft_putnbr_fd(e / 10, fd);
	j = (e % 10) + '0';
	write(fd, &j, 1);
}
