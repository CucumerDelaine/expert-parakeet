/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erichell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 12:35:28 by erichell          #+#    #+#             */
/*   Updated: 2021/04/16 12:38:36 by erichell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buf, int ch, int count)
{
	char	*zuf;
	int		i;

	i = 0;
	zuf = buf;
	while (i < (count))
	{
		zuf[i] = ch;
		i++;
	}
	return (zuf);
}
