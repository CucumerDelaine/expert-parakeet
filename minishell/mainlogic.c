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
	// if (!ft_strncmp_nr("env", cmd->cmd, 3))
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

int logic(t_cmd **cmd_origin, t_env **env_origin, char **oenv)
{
	t_cmd	*cmd;
	t_env	*env;
	int		d;

	cmd = *cmd_origin;
	env = *env_origin;
	d = dup(0);
	if (cmd->fd_in != 0)
		dup2(cmd->fd_in, STDIN_FILENO);
	// if(cmd->fd_out != 1)
	// 	dup2(cmd->fd_out, STDOUT_FILENO);
	if ((ft_lstsize1(cmd) - 1) > 0)
		pipe_logic(cmd, env, oenv, ft_lstsize1(cmd) - 1);
	else
		find_comand(cmd, env, oenv);
	if (cmd->fd_in != 0)
	{
		close(cmd->fd_in);
		dup2(d, STDIN_FILENO);
	}
	return (0);
}
