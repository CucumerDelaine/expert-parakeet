/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erichell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 16:35:48 by erichell          #+#    #+#             */
/*   Updated: 2021/04/17 16:35:50 by erichell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

void	*ft_memchr(const void *arr, int c, size_t n)
{
	const unsigned char	*arrv;

	arrv = arr;
	while (n)
	{
		if (*arrv == (unsigned char)c)
			return ((unsigned char *)arrv);
		arrv++;
		n--;
	}
	return (NULL);
}
