/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaine <cdelaine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:41:06 by cdelaine          #+#    #+#             */
/*   Updated: 2021/11/18 12:41:33 by cdelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_many_arg_ex(t_cmd *cmd)
{
	int	i;

	i = -1;
	while (cmd->argum[0][++i])
	{
		if ((cmd->argum[0][i] == '-' && i == 0) || ft_isdigit(cmd->argum[0][i]))
			continue ;
		g_status_error = 255;
		ft_putstr_fd("exit: ", 2);
		ft_putstr_fd(cmd->argum[0], 2);
		ft_putendl_fd(": numeric argument required", 2);
		exit (g_status_error);
	}
	ft_putendl_fd("exit: too many arguments", 2);
	g_status_error = 1;
	return (g_status_error);
}

void	check_number_exit(char *number)
{
	int	i;

	if (ft_strlen(number) > 20)
	{
		g_status_error = 255;
		ft_putstr_fd("exit: ", 2);
		ft_putstr_fd(number, 2);
		ft_putendl_fd(": numeric argument required", 2);
		exit (g_status_error);
	}
	i = ft_atoi(number);
	if (i > 255)
		exit(WEXITSTATUS(i) - 1);
	else
		exit(i);
}

void	check_one_arg_ex(t_cmd *cmd)
{
	int	i;

	i = -1;
	while (cmd->argum[0][++i])
	{
		if ((cmd->argum[0][i] == '-' && i == 0) || ft_isdigit(cmd->argum[0][i]))
			continue ;
		g_status_error = 255;
		ft_putstr_fd("exit: ", 2);
		ft_putstr_fd(cmd->argum[0], 2);
		ft_putendl_fd(": numeric argument required", 2);
		exit (g_status_error);
	}
	check_number_exit(cmd->argum[0]);
}

int	comand_exit(t_cmd *cmd)
{
	ft_putendl_fd("exit", 1);
	if (cmd->argum && cmd->argum[0] && cmd->argum[1])
		return (check_many_arg_ex(cmd));
	else if (cmd->argum && cmd->argum[0])
		check_one_arg_ex(cmd);
	else
		exit(g_status_error);
	return (0);
}
