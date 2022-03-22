/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaine <cdelaine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:55:52 by cdelaine          #+#    #+#             */
/*   Updated: 2022/03/22 14:57:41 by cdelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

void	init_config(t_config *config)
{
	config->north = NULL;
	config->south = NULL;
	config->east = NULL;
	config->west = NULL;
	config->width = 0;
	config->height = 0;
	config->ceiling = -1;
	config->floor = -1;
}

int	get_color(char *color)
{
	int	i;
	int	buff;
	int	value;

	i = 0;
	value = 0;
	while (i < 3)
	{
		buff = ft_atoi2(color);
		if (buff < 0 || buff > 255)
			return (-1);
		value = (value << 8) + buff;
		while (*color <= 57 && *color >= 48)
			color++;
		i++;
		if (*color != ',')
			break ;
		color++;
	}
	if (i < 3)
		return (-1);
	else if (*color || color[-1] == ',')
		return (-1);
	return (value);
}

int	config_check(t_config *config)
{
	if (!config->north || !config->south || !config->west
		|| !config->east || config->ceiling < 0 || config->floor < 0)
		return (1);
	if (file_check(config->north) || file_check(config->south)
		|| file_check(config->west) || file_check(config->east))
		return (1);
	return (0);
}

int	add_config(char **tmp, t_config *config)
{
	if (!ft_strncmp2(tmp[0], "NO", 3) && !config->north)
		config->north = ft_strdup2(tmp[1]);
	else if (!ft_strncmp2(tmp[0], "SO", 3) && !config->south)
		config->south = ft_strdup2(tmp[1]);
	else if (!ft_strncmp2(tmp[0], "WE", 3) && !config->west)
		config->west = ft_strdup2(tmp[1]);
	else if (!ft_strncmp2(tmp[0], "EA", 3) && !config->east)
		config->east = ft_strdup2(tmp[1]);
	else if (!ft_strncmp2(tmp[0], "F", 2) && config->floor == -1)
		config->floor = get_color(tmp[1]);
	else if (!ft_strncmp2(tmp[0], "C", 2) && config->ceiling == -1)
		config->ceiling = get_color(tmp[1]);
	else
		return (1);
	return (0);
}

int	get_config(int fd, t_config *config)
{
	int		ret;
	char	*str;
	char	**tmp;

	while (config_check(config))
	{
		ret = get_next_line2(fd, &str);
		if (!ret)
			break ;
		if (!str)
			continue ;
		tmp = ft_split2(str, ' ');
		free(str);
		if (!tmp || add_config(tmp, config))
			break ;
		tmp = free_all2(tmp);
	}
	free_all2(tmp);
	return (config_check(config));
}
