/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 11:00:38 by cdelaine          #+#    #+#             */
/*   Updated: 2021/05/12 11:00:40 by cdelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get2(char *str)
{
	int		i;
	int		j;
	char	*str2;

	i = 0;
	j = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (0);
	}
	str2 = malloc(sizeof(char) * ((ft_strlen(str) - i) + 1));
	if (!str2)
		return (0);
	i++;
	while (str[i])
		str2[j++] = str[i++];
	str2[j] = '\0';
	free(str);
	return (str2);
}

char	*get(char *str)
{
	int		i;
	char	*str2;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	str2 = malloc(sizeof(char) * (i + 1));
	if (!str2)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		str2[i] = str[i];
		i++;
	}
	str2[i] = '\0';
	return (str2);
}

int	readerer(int reader)
{
	if (reader == 0)
		return (0);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	char		*buffer;
	static char	*non;
	int			reader;

	reader = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!(buffer))
		return (-1);
	while (!on_return(non) && reader != 0)
	{
		reader = read(fd, buffer, BUFFER_SIZE);
		if (reader == -1)
		{
			free(buffer);
			return (-1);
		}
		buffer[reader] = '\0';
		non = strjoin(non, buffer);
	}
	free(buffer);
	*line = get(non);
	non = get2(non);
	return (readerer(reader));
}
