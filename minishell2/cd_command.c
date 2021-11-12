#include "minishell.h"

int	comand_echo(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (cmd->argum[i])
	{		
		ft_putstr_fd(cmd->argum[i], cmd->fd_out);
		ft_putstr_fd(" ", cmd->fd_out);
		i++;
	}
	if (ft_strncmp_nr("-n", cmd->flags[0], ft_strlen(cmd->flags[0])))
		ft_putstr_fd("\n", cmd->fd_out);
	return (g_status_error);
}

int	ft_go_home_cd(char *oldpath, t_env *env, t_env *tmp)
{
	t_env	*tmp_home;

	tmp_home = ft_find_list_env("HOME", &env);
	if (tmp == NULL)
	{
		ft_putstr_fd("cd: HOME not set\n", 2);
		return (1);
	}
	chdir(tmp_home->value);
	getcwd(oldpath, 10000);
	tmp = ft_find_list_env("PWD", &env);
	free(tmp->value);
	tmp->value = ft_strdup(tmp_home->value);
	return (0);
}

int	ft_first_cd(char *oldpath, t_env **env, t_cmd *cmd)
{
	t_env	*tmp;
	int		stat;

	stat = 0;
	getcwd(oldpath, 10000);
	tmp = ft_find_list_env("OLDPWD", env);
	if ((ft_find_list_env("OLDPWD", env)) != NULL)
		tmp->value = ft_strdup(oldpath);
	if (!chdir(cmd->argum[0]))
	{
		if (ft_find_list_env("PWD", env) == NULL)
			return (0);
		tmp = ft_find_list_env("PWD", env);
		free(tmp->value);
		getcwd(oldpath, 10000);
		tmp->value = ft_strdup(oldpath);
	}
	else if (!(ft_strcmp(cmd->argum[0], "~")) || cmd->argum[0] == NULL)
		stat = ft_go_home_cd(oldpath, *env, tmp);
	else
		stat = print_no_such(cmd);
	return (stat);
}

int	ft_second_cd(char *oldpath, t_env **env, t_cmd *cmd)
{
	t_env	*tmp;
	int		stat;

	stat = 0;
	getcwd(oldpath, 10000);
	tmp = ft_find_list_env("OLDPWD", env);
	free(tmp->value);
	tmp->value = ft_strdup(oldpath);
	if (!chdir(cmd->argum[0]))
	{
		if (ft_find_list_env("PWD", env) == NULL)
			return (0);
		tmp = ft_find_list_env("PWD", env);
		free(tmp->value);
		getcwd(oldpath, 10000);
		tmp->value = ft_strdup(oldpath);
	}
	else if (!(ft_strcmp(cmd->argum[0], "~")))
		stat = ft_go_home_cd(oldpath, *env, tmp);
	else
		stat = print_no_such(cmd);
	return (stat);
}

int	comand_cd(t_cmd *cmd, t_env *env)
{
	char	oldpath[10000];

	if (ft_find_list_env("OLDPWD", &env) == NULL)
		return (ft_first_cd(oldpath, &env, cmd));
	else if (!((ft_find_list_env("OLDPWD", &env))->value))
		return (ft_first_cd(oldpath, &env, cmd));
	else
		return (ft_second_cd(oldpath, &env, cmd));
}
