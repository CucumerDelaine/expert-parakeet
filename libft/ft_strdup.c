/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 12:37:24 by cdelaine          #+#    #+#             */
/*   Updated: 2021/04/20 12:37:26 by cdelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*tab;
	char	*bat;
	int		i;

	i = 0;
	tab = NULL;
	while (src[i])
	{
		i++;
	}
	tab = malloc(i + 1);
	if (!tab)
		return (NULL);
	bat = tab;
	while (*src != '\0')
	{
		*bat = *src;
		src++;
		bat++;
	}
	*bat = '\0';
	return (tab);
}
