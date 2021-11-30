/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erichell <erichell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:54:12 by erichell          #+#    #+#             */
/*   Updated: 2021/11/12 13:36:28 by erichell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*finish;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
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
