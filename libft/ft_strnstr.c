/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 10:39:30 by cdelaine          #+#    #+#             */
/*   Updated: 2021/04/20 10:39:32 by cdelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *str2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!str || !str2)
		return (NULL);
	if (!str2 || !str2[0])
		return ((char *)str);
	while (str[i])
	{
		j = 0;
		while (str[i + j] && str2[j] && str[i + j] == str2[j] && (i + j) < n)
			j++;
		if (!str2[j])
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}
