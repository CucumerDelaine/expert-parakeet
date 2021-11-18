/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaine <cdelaine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:43:50 by cdelaine          #+#    #+#             */
/*   Updated: 2021/11/18 12:43:53 by cdelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../libft/libft.h"

int	ft_is_space(char c)
{
	return ((c >= 9 && c <= 13) || c == ' ');
}

int	ifkey(char c)
{
	if (c == '_' || ft_isalnum(c))
		return (1);
	return (0);
}

int	print_no_such(t_cmd *cmd)
{
	ft_putstr_fd(cmd->argum[0], 2);
	ft_putstr_fd(": No such file or directory", 2);
	ft_putstr_fd("\n", 2);
	return (1);
}

void	ft_ctrl_c_cat(int id)
{
	(void) id;
	write (1, "\n", 1);
	g_status_error = 130;
}

void	ft_siginit_cat(void)
{
	signal(SIGINT, ft_ctrl_c_cat);
	signal(SIGQUIT, ft_ctrl_bs_cat);
}
