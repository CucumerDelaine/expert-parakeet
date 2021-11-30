/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_export_command.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaine <cdelaine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:43:30 by cdelaine          #+#    #+#             */
/*   Updated: 2021/11/18 12:45:13 by cdelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	change_value(t_env *new, char *key, t_env *env, char *value)
{
	free(new);
	new = ft_find_list_env(key, &env);
	free(new->value);
	free(key);
	new->value = value;
}

void	ft_add_env(t_env *new, char *key, char *value, t_env *env)
{
	new->key = key;
	new->value = value;
	new->next = NULL;
	ft_lstadd_back_env(&env, new);
}

int	add_var(char *var, t_env *env)
{
	t_env	*new;
	char	*key;
	char	*value;

	new = (t_env *)malloc(sizeof(t_env));
	if (check_var(var))
	{
		ft_putstr_fd(var, 2);
		ft_putendl_fd(": not a valid identifier", 2);
		free(new);
		return (1);
	}
	get_key_value(&key, &value, var);
	if (value && ft_find_list_env(key, &env))
		change_value(new, key, env, value);
	else
	{
		if (!ft_find_list_env(key, &env))
			ft_add_env(new, key, value, env);
		else
			free_func(key, value, new);
	}
	return (0);
}

int	comand_export(t_cmd *cmd, t_env *env)
{
	int		i;
	int		fd;
	t_env	*copy;

	copy = NULL;
	ft_copy_env(env, &copy);
	if (cmd->fd_out < 0)
		return (1);
	fd = cmd->fd_out;
	if (!cmd->argum[0])
	{
		sorting_env(copy);
		print__sort_env(copy, fd);
	}
	else
	{
		i = -1;
		while (cmd->argum[++i])
		{
			if (add_var(cmd->argum[i], env))
				return (1);
		}
	}
	ft_copy_freed(&copy);
	return (0);
}

void	ft_copy_freed(t_env **lst)
{
	t_env	*low;
	t_env	*temp;

	low = *lst;
	while (low)
	{
		temp = low;
		low = low->next;
		free(temp);
	}
}
