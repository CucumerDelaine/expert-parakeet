/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 19:46:45 by cdelaine          #+#    #+#             */
/*   Updated: 2021/04/27 19:46:50 by cdelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_free_all_split_alloc(char **str, int nbr)
{
	int	i;

	i = 0;
	while (i < nbr)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}
