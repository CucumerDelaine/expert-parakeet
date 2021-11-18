/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaine <cdelaine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:43:06 by cdelaine          #+#    #+#             */
/*   Updated: 2021/11/18 12:43:53 by cdelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ebuch_norma(int i, int argc, int *ft, int *fd)
{
	if (i == argc)
		cmd_proc_last(i, ft, fd);
	else
		cmd_proc(i, ft, fd);
}

int	switch_flag(t_cmd *cmd, int flag)
{
	if (!flag && cmd->next)
		return (1);
	else if (flag && cmd->next)
		return (0);
	return (flag);
}

void	cmd_pipex(t_cmd *cmd, int *ft, int *fd, int flag)
{
	if (cmd->next)
	{
		if (!flag)
			pipe(ft);
		else
			pipe(fd);
	}
}

void	proc_close(t_cmd *cmd, int flag, int *ft, int *fd)
{
	if (!flag && !cmd->next)
	{
		close(ft[0]);
		close(fd[1]);
	}
	else if (flag && !cmd->next)
	{
		close(ft[1]);
		close(fd[0]);
	}
	if (!flag)
	{
		if (fd[0])
			close(fd[0]);
		close(ft[1]);
	}
	else
	{
		if (ft[0])
			close(ft[0]);
		close(fd[1]);
	}
}

void	errr1(pid_t pid, int argc)
{
	int	i;
	int	err;

	i = 0;
	while (i <= argc)
	{
		waitpid(pid, &err, WUNTRACED | WCONTINUED);
		g_status_error = WEXITSTATUS(err);
		i++;
	}
}
