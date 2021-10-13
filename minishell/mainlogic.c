/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainlogic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 14:39:10 by cdelaine          #+#    #+#             */
/*   Updated: 2021/10/02 14:39:12 by cdelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int search_name_comand(t_cmd *cmd, t_env *env, char **oenv)
{
	// if (!ft_strncmp_nr("echo", cmd->cmd, 4))
	// 	g_status_error = comand_echo(cmd);
	// else if (!ft_strncmp_nr("cd", cmd->cmd, 2))
	// 	g_status_error = comand_cd(cmd, envp);
	// else if (!ft_strncmp_nr("pwd", cmd->cmd, 3))
	// 	g_status_error = comand_pwd(cmd, envp, o_env);
	// else if (!ft_strncmp_nr("export", cmd->cmd, 6))
	// 	g_status_error = comand_export(cmd, envp);
	// else if (!ft_strncmp_nr("unset", cmd->cmd, 5))
	// 	g_status_error = comand_unset(cmd, envp);
	// else if (!ft_strncmp_nr("env", cmd->cmd, 3))
	// 	g_status_error = comand_env(cmd, envp);
	// else if (!ft_strncmp_nr("exit", cmd->cmd, 4))
	// 	g_status_error = comand_exit(cmd);
	// else
		g_status_error = comand_exve(cmd, env, oenv);
	return (g_status_error);
}

int	find_comand(t_cmd *cmd, t_env *env, char **oenv)
{
	search_name_comand(cmd, env, oenv);
	if (cmd->fd_in)
	{
		close(cmd->fd_in);
		dup2(cmd->fd_in, 0);
	}
	return (g_status_error);
}

int	ft_lstsize1(t_cmd *lst)
{
	int	i;
	t_cmd *str;
	str = lst;

	i = 0;
	while (str)
	{
		str = str->next;
		i++;
	}
	return (i);
}

// void pipe_logic2(t_cmd *cmd, t_env *env, char **oenv)
// {
// 	pid_t	pid;
// 	int		pipefd[2];

// 	pipe(pipefd);
// 	pid = fork();
// 	if (pid)
// 	{
// 		close(pipefd[1]);
// 		dup2(pipefd[0], 0);
// 		// waitpid(pid, NULL, 0);
// 	}
// 	else
// 	{
// 		close(pipefd[0]);
// 		dup2(pipefd[1], 1);
// 		find_comand(cmd, env, oenv);
// 	}
// }
void	cmd1_process(int *ft, t_cmd *cmd, t_env *env, char **oenv)
{
	dup2(ft[1], STDOUT_FILENO);
	close(ft[1]);
	close(ft[0]);
	find_comand(cmd, env, oenv);
}

void	cmd2_process(int *ft, t_cmd *cmd, t_env *env, char **oenv)
{
	dup2(ft[0], STDIN_FILENO);
	close(ft[0]);
	close(ft[1]);
	find_comand(cmd, env, oenv);
}

void	new_proces(int *ft, t_cmd *cmd, t_env *env, char **oenv, int argc)
{
	int	pid;

	pid = fork();
	if (pid < 0)
		exit (2);
	if (pid == 0 && argc == 1)
		cmd1_process(ft, cmd, env, oenv);
	if (pid == 0 && argc == 2)
		cmd2_process(ft, cmd->next, env, oenv);
}

int pipe_logic(t_cmd *cmd, t_env *env, char **oenv, int argc)
{
	int i;
	int	ft[2];
	int fd[2];

	if (argc == 1)
	{
		if (pipe(ft) < 0)
			return (1);
		new_proces(ft, cmd, env, oenv, 1);
		wait(NULL);
		new_proces(ft, cmd, env, oenv, 2);
		close(ft[1]);
		close(ft[0]);
		wait(NULL);
	}
	else if (argc%2 == 0)
	{
		
	}
	// else

	return (0);
}

int logic(t_cmd **cmd_origin, t_env **env_origin, char **oenv)
{
	t_cmd	*cmd;
	t_env	*env;

	cmd = *cmd_origin;
	env = *env_origin;
	if (cmd->fd_in != 0)
		dup2(cmd->fd_in, STDIN_FILENO);
	if(cmd->fd_out != 1)
		dup2(cmd->fd_out, STDOUT_FILENO);
	if ((ft_lstsize1(cmd) - 1) > 0)
		pipe_logic(cmd, env, oenv, ft_lstsize1(cmd) - 1);
	else
	printf("%d\n", 3%2); 
		find_comand(cmd, env, oenv);
	return (0);
}
