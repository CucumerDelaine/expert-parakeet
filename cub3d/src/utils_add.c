/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaine <cdelaine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:57:09 by cdelaine          #+#    #+#             */
/*   Updated: 2022/03/22 15:11:32 by cdelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

int	check_rows(t_listt *lst, int i)
{
	int	flag;
	int	j;

	flag = 2;
	while (lst)
	{
		if (i > ft_strlen2(lst->str))
			j = 2;
		else
			j = get_value(lst->str[i], NULL);
		if (j < 0 || flag - j < -1
			|| flag - j > 1)
			return (1);
		flag = j;
		lst = lst->next;
	}
	if (flag <= 0)
		return (1);
	return (0);
}

char	*ft_spaces(char *str, int i)
{
	int		len;
	char	*ret;

	len = ft_strlen2(str);
	ret = malloc((sizeof(char)) * i + 1);
	ft_memcpy2(ret, str, len);
	ft_memset2(&(ret[len]), 32, i - len);
	ret[i] = 0;
	return (ret);
}

char	**lst_to_map(t_listt *lst, t_config *config)
{
	char	**map;
	int		i;

	i = 0;
	config->width = get_max_strlen(lst);
	config->height = lst_len(lst);
	map = (char **)malloc(sizeof(char *) * (config->height + 1));
	while (lst)
	{
		if (ft_strlen2(lst->str) < config->width)
			map[i] = ft_spaces(lst->str, config->width);
		else
			map[i] = ft_strdup2(lst->str);
		if (!map[i])
			return (free_all2(map));
		i++;
		lst = lst->next;
	}
	map[i] = NULL;
	return (map);
}

int	row_is_empty(t_listt *lst, int i)
{
	while (lst)
	{
		if (i < ft_strlen2(lst->str)
			&& lst->str[i] != ' ')
			return (0);
		lst = lst->next;
	}
	return (1);
}
