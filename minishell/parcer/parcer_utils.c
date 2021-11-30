/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erichell <erichell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 13:11:51 by erichell          #+#    #+#             */
/*   Updated: 2021/11/18 13:12:50 by erichell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_next_stage(t_cmd **new, int *i, t_iter *iter)
{
	(*new) = ft_lstnew_cmd((iter)->res);
	(*i) = (iter)->len;
	free_iter_res_or_word(iter);
}
