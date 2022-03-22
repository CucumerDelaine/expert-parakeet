/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaine <cdelaine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:56:22 by cdelaine          #+#    #+#             */
/*   Updated: 2022/03/22 14:58:23 by cdelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

void	error_handler(int i)
{
	write(1, "Error: ", 7);
	if (i == 0)
		printf("invalid argument\n");
	else if (i == 1)
		printf("invalid map format\n");
	else if (i == 2)
		printf("invalid file\n");
	else if (i == 3)
		printf("invalid configuration\n");
	else if (i == 4)
		printf("invalid map\n");
	exit(1);
}

int	file_check(char *fname)
{
	if (ft_strlen2(fname) <= 4)
		return (1);
	if (ft_strncmp2(&(fname[ft_strlen2(fname) - 4]), ".xpm", 5))
		return (1);
	return (0);
}
