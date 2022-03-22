/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaine <cdelaine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:56:29 by cdelaine          #+#    #+#             */
/*   Updated: 2022/03/22 15:03:06 by cdelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

int	get_max_strlen(t_listt *lst)
{
	int	max;
	int	buff;

	max = 0;
	while (lst)
	{
		buff = ft_strlen2(lst->str);
		if (buff > max)
			max = buff;
		lst = lst->next;
	}
	return (max);
}

int	lst_len(t_listt *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

int	list_checker(t_listt *lst)
{
	int	max;
	int	is_empty;
	int	i;

	i = 0;
	is_empty = 0;
	max = get_max_strlen(lst);
	if (!max)
		return (1);
	while (i < max)
	{
		if (!row_is_empty(lst, i))
		{
			if (check_rows(lst, i) || is_empty == 2)
				return (1);
			is_empty = 1;
		}
		else if (is_empty)
			is_empty++;
		i++;
	}
	return (0);
}
