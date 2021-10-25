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

int	find_comand(t_cmd *cmd, t_env *env, char **oenv)
{
	// if (!ft_strncmp_nr("echo", cmd->cmd, 4))
	// 	g_status_error = comand_echo(cmd);
	// else if (!ft_strncmp_nr("cd", cmd->cmd, 2))
	// 	g_status_error = comand_cd(cmd, env);
	// else if (!ft_strncmp_nr("pwd", cmd->cmd, 3))
	// 	g_status_error = comand_pwd(cmd, envp, o_en);
	// else if (!ft_strncmp_nr("export", cmd->cmd, 6))
	// 	g_status_error = comand_export(cmd, env);
	if (!ft_strncmp_nr("unset", cmd->cmd, 5))
		g_status_error = comand_unset(cmd, env);
	else if (!ft_strncmp_nr("env", cmd->cmd, 3))
		g_status_error = comand_env(cmd, env);
	else if (!ft_strncmp_nr("exit", cmd->cmd, 4))
		g_status_error = comand_exit(cmd);
	else
		g_status_error = comand_exve(cmd, env, oenv);
	return (g_status_error);
}

int	ft_lstsize1(t_cmd *lst)
{
	int		i;
	t_cmd	*str;

	str = lst;
	i = 0;
	while (str)
	{
		str = str->next;
		i++;
	}
	return (i);
}

int	logic(t_cmd **cmd_origin, t_env **env_origin, char **oenv)
{
	t_cmd	*cmd;
	t_env	*env;

	cmd = *cmd_origin;
	env = *env_origin;
	if ((ft_lstsize1(cmd) - 1) > 0)
		pipe_logic(cmd, env, oenv, ft_lstsize1(cmd) - 1);
	else
		find_comand(cmd, env, oenv);
	return (0);
}
