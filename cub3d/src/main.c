/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaine <cdelaine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 17:30:04 by                   #+#    #+#             */
/*   Updated: 2022/03/22 15:07:55 by cdelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"
#include "../parser.h"

void	free_error(t_config *config, t_data *data)
{
	free_config(config);
	free_all2(config->map2);
	ft_error(data);
}

void	ft_copy(t_data *data, t_config *config)
{
	data->p_draw->path_n = config->north;
	data->p_draw->path_s = config->south;
	data->p_draw->path_w = config->west;
	data->p_draw->path_e = config->east;
	data->p_draw->f_color = config->floor;
	data->p_draw->c_color = config->ceiling;
	data->p_info->arr = config->map2;
	data->p_info->width = config->width;
	data->p_info->height = config->height;
}

static int	init_struct(t_data *data)
{
	data->p_draw = malloc(sizeof(t_draw));
	data->p_coord = malloc(sizeof(t_coord));
	data->p_addres = malloc(sizeof(t_addres));
	data->p_info = malloc(sizeof(t_info));
	if (!data->p_draw || !data->p_addres || !data->p_coord)
	{
		ft_putendl_fd("Error malloc", 1);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data		data;
	t_config	config;

	if (argc != 2)
	{
		ft_putendl_fd("Error", 1);
		return (1);
	}
	else
	{
		if (init_struct(&data))
			return (1);
		if (ft_parser(argv, &data))
			free_error(&config, &data);
		if (parcer(argv, &config))
			free_error(&config, &data);
		ft_copy(&data, &config);
		ft_draw_general(&data);
	}
	free_config(&config);
	free_all2(config.map2);
	free_all(&data);
	return (0);
}
