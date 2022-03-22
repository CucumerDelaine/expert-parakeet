/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaine <cdelaine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:57:00 by cdelaine          #+#    #+#             */
/*   Updated: 2022/03/22 14:57:03 by cdelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"
#define BUFFER_SIZE 42

char	**free_all2(char **ret)
{
	int	i;

	if (!ret)
		return (NULL);
	i = 0;
	while (ret[i])
	{
		free(ret[i]);
		ret[i] = NULL;
		i++;
	}
	free(ret[i]);
	ret[i] = NULL;
	free(ret);
	return (NULL);
}

int	get_next_line2(int fd, char **line)
{
	char	c;
	int		res;
	char	*buff;

	*line = NULL;
	res = read(fd, &c, 1);
	while (res > 0 && c != '\n')
	{
		res = ft_strlen2(*line);
		buff = malloc(sizeof(char) * (res + 2));
		ft_strlcpy2(buff, *line, res);
		buff[res] = c;
		buff[res + 1] = 0;
		free(*line);
		*line = buff;
		res = read(fd, &c, 1);
	}
	return (res);
}
