/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erichell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:54:12 by erichell          #+#    #+#             */
/*   Updated: 2021/04/18 20:54:14 by erichell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*finish;
	int		i;

	i = 0;
	while (s[i])
		i++;
	finish = (char *)malloc(sizeof(char) * (i + 1));
	if (!finish)
		return (NULL);
	i = 0;
	while (s[i])
	{
		finish[i] = s[i];
		i++;
	}
	finish[i] = '\0';
	return (finish);
}
