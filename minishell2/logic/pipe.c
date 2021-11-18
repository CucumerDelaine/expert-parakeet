/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaine <cdelaine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:42:59 by cdelaine          #+#    #+#             */
/*   Updated: 2021/11/18 12:43:53 by cdelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	pipe_logic(t_cmd *cmd, t_env *env, char **oenv, int argc)
{
	if (argc == 1)
		cmd_proc_two(cmd, env, oenv, argc);
	else
		cmd_proc_many(cmd, env, oenv, argc);
}

void	cmd_proc(int i, int *ft, int *fd)
{
	if (i == 0)
	{
		close(ft[0]);
		dup2(ft[1], 1);
		close(ft[1]);
	}
	else if (i % 2 != 0)
	{
		dup2(ft[0], 0);
		close(fd[0]);
		close(ft[0]);
		dup2(fd[1], 1);
	}
	else if (i % 2 == 0)
	{
		dup2(fd[0], 0);
		close(fd[0]);
		close(ft[0]);
		dup2(ft[1], 1);
	}
}

void	cmd_proc_last(int i, int *ft, int *fd)
{
	if (i % 2 != 0)
		dup2(ft[0], 0);
	else if (i % 2 == 0)
		dup2(fd[0], 0);
}

void	cmd_proc_two(t_cmd *cmd, t_env *env, char **oenv, int argc)
{
	pid_t	pid;
	int		fd[2];

	if (1)
	{
		pipe(fd);
		pid = fork();
		if (!pid)
			one_pipe_1(cmd, env, oenv, fd);
		else
			close(fd[1]);
	}
	if (1)
	{
		pid = fork();
		if (!pid)
			one_pipe_2(cmd->next, env, oenv, fd);
		else
			close(fd[0]);
	}
	errr1(pid, argc);
}

void	cmd_proc_many(t_cmd *cmd, t_env *env, char **oenv, int argc)
{
	pid_t	pid;
	int		flag;
	int		i;
	int		ft[2];
	int		fd[2];

	init_flag_i(&flag, &i);
	while (i <= argc)
	{		
		cmd_pipex(cmd, ft, fd, flag);
		pid = fork();
		if (!pid)
		{
			ebuch_norma(i, argc, ft, fd);
			find_comand2(cmd, env, oenv);
		}
		else
		{
			proc_close(cmd, flag, ft, fd);
			flag = switch_flag(cmd, flag);
			cmd = cmd->next;
		}
		i++;
	}
	errr1(pid, argc);
}
