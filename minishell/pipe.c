
#include "minishell.h"

void pipe_logic(t_cmd *cmd, t_env *env, char **oenv, int argc)
{
	int		i;
	int		ft[2];
	int		fd[2];
	pid_t pid;

	if (argc == 1)
	{
		if (1)
		{
			pipe(fd);
			pid = fork();
			if (!pid)
			{
				close(fd[0]);
				dup2(fd[1], 1);
				close(fd[1]);
				find_comand(cmd, env, oenv);
				exit(0);
			}
			else
			{
				close(fd[1]);
			}
		}
		if (1)
		{
			pid = fork();
			if (!pid)
			{
				dup2(fd[0], 0);
				close(fd[0]);
				find_comand(cmd->next, env, oenv);
				exit(0);
			}
			else
			{
				close(fd[0]);
			}
		}
		for (int i = 0; i <= argc + 1; ++i)
			wait(0);
	}
	else
	{
		i = 0;
		pipe(ft);
		pipe(fd);
		while(i <= argc)
		{		
			if (i == argc)
				cmd_proc_last(cmd, env, oenv, i, ft, fd);
			cmd_proc(cmd, env, oenv, i, ft, fd);
			if (i%4 == 1)
			{
				close(ft[0]);
				close(ft[1]);
				pipe(ft);
			}
			else if(i%4 == 3)
			{
				close(fd[0]);
				close(fd[1]);
				pipe(fd);
			}
			i++;
			cmd = cmd->next;
		}
		close(ft[0]);
		close(ft[1]);
		close(fd[0]);
		close(fd[1]);
		for (int i = 0; i <= argc + 1; i++)
			wait(0);
	}
}

void cmd_proc(t_cmd *cmd, t_env *env, char **oenv, int i, int *ft, int *fd)
{
	pid_t pid;
	
	pid = fork();
	if (pid == 0 && i == 0)
	{
		close(ft[0]);
		dup2(ft[1], 1);
		find_comand(cmd, env, oenv);
		exit(0);
	}
	else if (pid == 0 && i%2 != 0)
	{
		close(ft[1]);
		dup2(ft[0], 0);
		close(fd[0]);
		dup2(fd[1], 1);
		find_comand(cmd, env, oenv);
		exit(0);
	}
	else if(pid == 0 && i%2 == 0)
	{
		close(fd[1]);
		dup2(fd[0], 0);
		close(ft[0]);
		dup2(ft[1], 1);
		find_comand(cmd, env, oenv);
		exit(0);
	}
	
}

void cmd_proc_last(t_cmd *cmd, t_env *env, char **oenv, int i, int *ft, int *fd)
{
	pid_t pid;
	
	pid = fork();
	if (pid == 0 && i%2 != 0)
	{
		close(ft[1]);
		dup2(ft[0], 0);
		find_comand(cmd, env, oenv);
		exit(0);
	}
	else if(pid == 0 && i%2 == 0)
	{
		close(fd[1]);
		dup2(fd[0], 0);
		find_comand(cmd, env, oenv);
		exit(0);
	}
}
