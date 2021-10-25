#include "minishell.h"

void	print_envp(t_env *envp, int fd)
{
	t_env	*tmp;

	tmp = envp;
	while (tmp)
	{
		if (tmp->value)
		{
			ft_putstr_fd(tmp->key, fd);
			write(fd, "=", 1);
			ft_putendl_fd(tmp->value, fd);
		}
		tmp = tmp->next;
	}
}

int	comand_env(t_cmd *cmd, t_env *env)
{
	int	fd;

	if (cmd->fd_out)
		fd = cmd->fd_out;
	print_envp(env, fd);
	return (0);
}
