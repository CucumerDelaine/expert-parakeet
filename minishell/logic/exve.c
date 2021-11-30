/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exve.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaine <cdelaine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:02:57 by cdelaine          #+#    #+#             */
/*   Updated: 2021/11/18 12:38:50 by cdelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	path(char *name_programm)
{
	int	i;

	i = 0;
	while (name_programm[i])
	{
		if (name_programm[i] == '/')
			return (1);
		i++;
	}
	return (0);
}

void	call_execve_proc(t_cmd *cmd, char **oenv)
{
	char	*name_program;
	char	**flags;

	if (path(cmd->cmd))
		name_program = ft_strdup(cmd->cmd);
	else
		name_program = get_addres(oenv, cmd->cmd);
	flags = get_flag(cmd);
	check_minishel(name_program, oenv, cmd);
	execve(name_program, flags, oenv);
	perror(name_program);
	exit (127);
}

int	comand_exve(t_cmd *cmd, t_env *env, char **oenv)
{
	int	pid;
	int	err;

	err = 0;
	if (cmd->cmd == NULL )
		return (g_status_error);
	if (!path(cmd->cmd) && check_path(cmd, env))
		return (g_status_error);
	ft_siginit_cat();
	pid = fork();
	if (pid < 0)
		exit (1);
	if (pid == 0)
	{
		if (cmd->fd_in != 0)
			dup2(cmd->fd_in, STDIN_FILENO);
		else if (cmd->fd_red != 0)
			dup2(cmd->fd_red, STDIN_FILENO);
		if (cmd->fd_out != 1)
			dup2(cmd->fd_out, STDOUT_FILENO);
		call_execve_proc(cmd, oenv);
	}
	errr1(pid, 1);
	norma2(cmd);
	return (g_status_error);
}

void	norma2(t_cmd *cmd)
{
	if (cmd->fd_in != 0)
		close(cmd->fd_in);
	else if (cmd->fd_red != 0)
		close (cmd->fd_red);
	if (cmd->fd_out != 1)
		close(cmd->fd_out);
}
