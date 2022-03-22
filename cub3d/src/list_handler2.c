/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_handler2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaine <cdelaine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:02:24 by cdelaine          #+#    #+#             */
/*   Updated: 2022/03/22 15:07:22 by cdelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

t_listt	*init_list(char *str)
{
	t_listt	*lst;

	lst = (t_listt *)malloc(sizeof(t_listt));
	lst->str = ft_strdup2(str);
	lst->next = NULL;
	return (lst);
}

void	list_clear(t_listt **lst)
{
	t_listt	*tmp;

	tmp = NULL;
	if (!*lst)
		return ;
	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp->str);
		free(tmp);
		tmp = NULL;
	}
}

void	add_list(t_listt **lst, char *str)
{
	t_listt	*start;

	if (!*lst)
	{
		*lst = init_list(str);
		return ;
	}
	start = *lst;
	while ((*lst)->next)
		*lst = (*lst)->next;
	(*lst)->next = init_list(str);
	(*lst) = start;
}
