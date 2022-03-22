/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaine <cdelaine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:56:57 by cdelaine          #+#    #+#             */
/*   Updated: 2022/03/22 15:08:48 by cdelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

char	**free_arr(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return (NULL);
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	arr = NULL;
	return (arr);
}

int	get_value(char c, int *character)
{
	if (c == ' ' || c == 0)
		return (2);
	if (c == '1')
		return (1);
	if (c == '0')
		return (0);
	if (c == 'N' || c == 'S'
		|| c == 'W' || c == 'E')
	{
		if (!character || *character == 0)
		{
			if (character)
				*character = 1;
			return (0);
		}
	}
	return (-1);
}

int	line_check(const char *line)
{
	static int	character;
	int			flag;
	int			buff;

	flag = 2;
	while (*line)
	{
		buff = get_value(*line, &character);
		if (buff < 0 || flag - buff < -1
			|| flag - buff > 1)
			return (1);
		flag = buff;
		line++;
	}
	if (flag <= 0)
		return (1);
	return (0);
}

int	check_if_empty(char *line)
{
	if (!line)
		return (1);
	while (*line)
	{
		if (*line != ' ')
			return (0);
		line++;
	}
	return (1);
}
