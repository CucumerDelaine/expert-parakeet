/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erichell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 08:03:28 by erichell          #+#    #+#             */
/*   Updated: 2021/04/17 08:03:31 by erichell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*t;
	unsigned long int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (!f)
		return ((char *) s);
	t = (char *)(malloc(sizeof(char) * (ft_strlen(s) + 1)));
	if (!t)
		return (NULL);
	while (i < ft_strlen(s))
	{
		t[i] = f(i, s[i]);
		i++;
	}
	t[i] = '\0';
	return (t);
}
