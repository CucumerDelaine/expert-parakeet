/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 10:59:03 by cdelaine          #+#    #+#             */
/*   Updated: 2021/04/20 10:59:04 by cdelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((s2[i] != '\0' || s1[i] != '\0') && (i < n))
	{
		if (s1[i] > s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		else if (s1[i] < s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		else
			i++;
	}
	return (0);
}
