/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 12:23:25 by cdelaine          #+#    #+#             */
/*   Updated: 2021/04/20 12:23:28 by cdelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	char	*str;

	str = (char *)malloc (number * size);
	if (!str)
		return (NULL);
	ft_bzero(str, number * size);
	return (str);
}
