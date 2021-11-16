/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainlogic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erichell <erichell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 14:39:10 by cdelaine          #+#    #+#             */
/*   Updated: 2021/11/12 15:55:54 by erichell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	find_comand(t_cmd *cmd, t_env *env, char **oenv)
{
	if (!ft_strncmp_nr("echo", cmd->cmd, ft_strlen(cmd->cmd)))
		g_status_error = comand_echo(cmd);
	else if (!ft_strncmp_nr("cd", cmd->cmd, ft_strlen(cmd->cmd)))
		g_status_error = comand_cd(cmd, env);
	else if (!ft_strncmp_nr("pwd", cmd->cmd, ft_strlen(cmd->cmd)))
		g_status_error = command_pwd(cmd, env, oenv);
	else if (!ft_strncmp_nr("export", cmd->cmd, ft_strlen(cmd->cmd)))
		g_status_error = comand_export(cmd, env);
	else if (!ft_strncmp_nr("unset", cmd->cmd, ft_strlen(cmd->cmd)))
		g_status_error = comand_unset(cmd, env);
	else if (!ft_strncmp_nr("env", cmd->cmd, ft_strlen(cmd->cmd)))
		g_status_error = comand_env(cmd, env);
	else if (!ft_strncmp_nr("exit", cmd->cmd, ft_strlen(cmd->cmd)))
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
	if (back_d_red21(cmd) == 130)
		return (0);
	if ((ft_lstsize1(cmd) - 1) > 0)
		pipe_logic(cmd, env, oenv, ft_lstsize1(cmd) - 1);
	else
		find_comand(cmd, env, oenv);
	return (0);
}
