#include "../includes/minishell.h"

int	check_flags_echo(char *flag)
{
	int	i;

	i = 1;
	while (flag[i])
	{
		if (flag[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

int	comand_echo(t_cmd *cmd)
{
	int		fd;

	fd = cmd->fd_in;
	if (cmd->flags[1] && check_flags_echo(cmd->flags[1]))
		ft_putstr_fd(cmd->argum[0], fd);
	else
		ft_putendl_fd(cmd->argum[0], fd);
	return (0);
}
