/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaine <cdelaine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:58:38 by cdelaine          #+#    #+#             */
/*   Updated: 2022/03/22 15:01:01 by cdelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
}

void	print_config(t_config *config)
{
	printf("floor: %d\n", config->floor);
	printf("ceiling: %d\n", config->ceiling);
	printf("NO: %s\n", config->north);
	printf("SO: %s\n", config->south);
	printf("WE: %s\n", config->west);
	printf("EA: %s\n", config->east);
}

char	**start_parsing(char *fname, t_config *config)
{
	t_listt	*lst;
	char	**map;
	int		fd;

	lst = NULL;
	map = NULL;
	if (ft_strlen2(fname) <= 4)
		error_handler(1);
	if (ft_strncmp2(&(fname[ft_strlen2(fname) - 4]), ".cub", 5))
		error_handler(1);
	init_config(config);
	fd = open(fname, O_RDONLY);
	if (fd < 0)
		error_handler(2);
	if (get_config(fd, config))
		error_handler(3);
	if (get_map_line(&lst, fd) || list_checker(lst))
		error_handler(4);
	map = lst_to_map(lst, config);
	list_clear(&lst);
	return (map);
}

void	free_config(t_config *config)
{
	free(config->north);
	free(config->south);
	free(config->west);
	free(config->east);
}

int	parcer(char **argv, t_config *config)
{
	config->map2 = start_parsing(argv[1], config);
	return (0);
}
