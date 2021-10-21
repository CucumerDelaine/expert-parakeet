#include "minishell.h"

void	one_pipe_1(t_cmd *cmd, t_env *env, char **oenv, int *fd)
{
	close(fd[0]);
	dup2(fd[1], 1);
	close(fd[1]);
	find_comand(cmd, env, oenv);
	exit(0);
}

void	one_pipe_2(t_cmd *cmd, t_env *env, char **oenv, int *fd)
{
	dup2(fd[0], 0);
	close(fd[0]);
	find_comand(cmd->next, env, oenv);
	exit(0);
}

void	init_flag_i(int *flag, int *i)
{
	*flag = 0;
	*i = 0;
}

void	find_comand2(t_cmd *cmd, t_env *env, char **oenv)
{
	find_comand(cmd, env, oenv);
	exit(0);
}
