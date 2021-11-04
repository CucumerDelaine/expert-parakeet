#include "minishell.h"

int command_pwd(t_cmd *cmd, t_env *env, char **oenv)
{
	t_env *tmp;

	tmp = ft_find_list_env("PWD", &env);
	if (tmp == NULL)
		return (comand_exve(cmd, env, oenv));
	ft_putstr_fd(tmp->value, cmd->fd_out);
	ft_putstr_fd("\n",cmd->fd_out);
	return(0);
}

int is_sort_env(t_env *env)
{
	while (env->next)
	{
		if (ft_strcmp(env->key, env->next->key) <= 0)
			env = env->next;
		else
			return (1);
	}
	return (0);
}

void swap_elem(t_env *s1, t_env *s2)
{
	char *key;
	char *value;

	key = s1->key;
	value = s1->value;
	s1->key = s2->key;
	s1->value = s2->value;
	s2->key = key;
	s2->value = value;
}

void sorting_env(t_env *env)
{
	int i;
	t_env *start;

	i = 0;
	while (is_sort_env(env))
	{
		start = env;
		while (start->next)
		{
			if ((ft_strcmp(start->key, start->next->key)) > 0)
				swap_elem(start, start->next);
			start = start->next;
		}
	}
}

void print__sort_env(t_env *env, int fd)
{
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		if (tmp->value)
		{
			ft_putstr_fd("declare -x ", fd);
			ft_putstr_fd(tmp->key, fd);
			ft_putstr_fd("=\"", fd);
			ft_putstr_fd(tmp->value, fd);
			ft_putstr_fd("\"\n", fd);
		}
		else
		{
			ft_putstr_fd("declare -x ", fd);
			ft_putstr_fd(tmp->key, fd);
			ft_putstr_fd("=\"\"\n", fd);
		}
		tmp = tmp->next;
	}
}

t_env	*ft_copy_env(t_env *env, t_env *copy)
{
	t_env *tmp;
	t_env *new;
	char *key;
	char *value;

	tmp = env;
	while (tmp != NULL)
	{
		new = (t_env *)malloc(sizeof(t_env));
		if (!new)
			return (NULL);
		key = tmp->key;
		value = tmp->value;
		new->key = key;
		new->value = value;
		new->next = NULL;
		ft_lstadd_back_env(&copy, new);
		tmp = tmp->next;
	}
	return (copy);
}

int check_var(char *var)
{
	int i;

	i = 0;
	while (var[i] && var[i] != '=')
	{
		if (i == 0 && !ft_isalpha(var[i]))
			return (1);
		if (i != 0 && !ft_isalpha(var[i])
			&& !ft_isdigit(var[i]) && var[i] != '_')
			return (1);
		i++;
	}
	return (0);
}
void get_key_value(char **key, char **value, char *var)
{
	char *sep;

	sep = ft_strchr(var, '=');
	if (sep)
	{
		*key = ft_substr(var, 0, ft_strlen(var) - ft_strlen(sep));
		*value = ft_strdup(sep + 1);
	}
	else
	{
		*key = ft_strdup(var);
		*value = NULL;
	}
}

void change_value(t_env *new, char *key, t_env *env, char *value)
{
	free(new);
	new = ft_find_list_env(key, &env);
	free(new->value);
	free(key);
	new->value = value;
}

void ft_add_env(t_env *new, char *key, char *value, t_env *env)
{
	new->key = key;
	new->value = value;
	new->next = NULL;
	ft_lstadd_back_env(&env, new);
}

int add_var(char *var, t_env *env)
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

int comand_export(t_cmd *cmd, t_env *env)
{
	int i;
	int fd;
	t_env	*copy;

	copy = NULL;
	copy = ft_copy_env(env, copy);
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
	return (0);
}