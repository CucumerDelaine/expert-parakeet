/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 17:23:33 by cdelaine          #+#    #+#             */
/*   Updated: 2021/10/23 17:23:35 by cdelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_ctrl_c_cat(int id)
{
	(void) id;
	write (1, "\n", 1);
	g_status_error = 130;
}

void	ft_ctrl_bs_cat(int id)
{
	(void) id;
	write(1, "Quit: 3\n", 8);
	g_status_error = 131;
}

void	ft_siginit_cat(void)
{
	signal(SIGINT, ft_ctrl_c_cat);
	signal(SIGQUIT, ft_ctrl_bs_cat);
}
