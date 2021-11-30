/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaine <cdelaine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:40:55 by cdelaine          #+#    #+#             */
/*   Updated: 2021/11/18 12:41:33 by cdelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_key_value(t_env **env)
{
	if (!ft_strncmp((*env)->key, "PATH", 4))
	{
		if ((*env)->value != NULL)
			return (0);
		else
			return (1);
	}
	else
		(*env) = (*env)->next;
	if (*env == NULL)
		return (1);
	return (0);
}

int	free_normi(t_pipex *a)
{
	free_memory(a->strings_way, a->comand);
	free(a->addres_full);
	return (1);
}

int	check_addres(t_env *env, char *cmd)
{
	t_pipex	str;

	while (ft_strncmp(env->key, "PATH", 4))
		if (check_key_value(&env))
			return (0);
	if (env->value == NULL)
		return (0);
	str.strings_way = ft_split(env->value, ':');
	str.comand = ft_split(cmd, ' ');
	str.i = 0;
	while (str.strings_way[str.i])
	{
		str.addres = ft_strjoin(str.strings_way[str.i++], "/");
		str.addres_full = ft_strjoin(str.addres, cmd);
		free(str.addres);
		if (access(str.addres_full, F_OK) == 0)
			return (free_normi(&str));
		free(str.addres_full);
	}
	free_memory(str.strings_way, str.comand);
	return (0);
}

int	check_path(t_cmd *cmd, t_env *env)
{
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		if (!ft_strncmp(tmp->key, "PATH", 4)
			&& check_addres(env, cmd->cmd))
			return (0);
		tmp = tmp->next;
	}
	ft_putstr_fd(cmd->cmd, 2);
	ft_putendl_fd(": command not found", 2);
	g_status_error = 127;
	return (1);
}
