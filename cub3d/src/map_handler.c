/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaine <cdelaine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:56:48 by cdelaine          #+#    #+#             */
/*   Updated: 2022/03/22 15:08:22 by cdelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

int	get_map_line(t_listt **lst, int fd)
{
	char	*str;
	int		ret;
	int		is_empty;

	is_empty = 0;
	ret = get_next_line2(fd, &str);
	while (ret || str)
	{
		if (!check_if_empty(str))
		{
			if (line_check(str), is_empty == 2)
				break ;
			is_empty = 1;
			add_list(lst, str);
		}
		else if (is_empty)
			is_empty++;
		free(str);
		ret = get_next_line2(fd, &str);
	}
	if (!ret && !str)
		return (0);
	free(str);
	return (1);
}
