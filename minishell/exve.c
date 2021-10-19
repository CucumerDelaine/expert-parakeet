/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exve.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:02:57 by cdelaine          #+#    #+#             */
/*   Updated: 2021/10/07 16:02:59 by cdelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

void	call_execve_proc(t_cmd *cmd, t_env *env, char **oenv)
{
	char	*name_program;
	char	**flags;

	if (path(cmd->cmd))
		name_program = ft_strdup(cmd->cmd);
	else
		name_program = get_addres(oenv, env, cmd->cmd);
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
	if (!path(cmd->cmd) && check_path(cmd, env))
		return (g_status_error);
	pid = fork();
	if (pid < 0)
		exit (1);
	if (pid == 0)
	{
		call_execve_proc(cmd, env, oenv);
	}
	waitpid(pid, &err, WUNTRACED | WCONTINUED);
	g_status_error = WEXITSTATUS(err);
	return (g_status_error);
}
