#include "../minishell.h"

int	command_pwd(t_cmd *cmd, t_env *env, char **oenv)
{
	t_env	*tmp;

	tmp = ft_find_list_env("PWD", &env);
	if (tmp == NULL)
		return (comand_exve(cmd, env, oenv));
	ft_putstr_fd(tmp->value, cmd->fd_out);
	ft_putstr_fd("\n", cmd->fd_out);
	return (0);
}

int	is_sort_env(t_env *env)
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

void	swap_elem(t_env *s1, t_env *s2)
{
	char	*key;
	char	*value;

	key = s1->key;
	value = s1->value;
	s1->key = s2->key;
	s1->value = s2->value;
	s2->key = key;
	s2->value = value;
}

void	sorting_env(t_env *env)
{
	int		i;
	t_env	*start;

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

void	print__sort_env(t_env *env, int fd)
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
