
#include "minishell.h"

void pipe_logic(t_cmd *cmd, t_env *env, char **oenv, int argc)
{
	int		ft[2];
	int		fd[2];

	if (argc == 1)
		cmd_proc_two(cmd, env, oenv, ft, fd, argc);
	else
		cmd_proc_many(cmd, env, oenv, ft, fd, argc);
}

void cmd_proc(t_cmd *cmd, t_env *env, char **oenv, int i, int *ft, int *fd, int flag)
{
	if (i == 0)
	{
		close(ft[0]);
		dup2(ft[1], 1);
		close(ft[1]);
		find_comand(cmd, env, oenv);
		exit(0);
	}
	else if (i%2 != 0)
	{
		dup2(ft[0], 0);
		close(fd[0]);
		close(ft[0]);
		dup2(fd[1], 1);
		find_comand(cmd, env, oenv);
		exit(0);
	}
	else if(i%2 == 0)
	{
		dup2(fd[0], 0);
		close(fd[0]);
		close(ft[0]);
		dup2(ft[1], 1);
		find_comand(cmd, env, oenv);
		exit(0);
	}
}

void cmd_proc_last(t_cmd *cmd, t_env *env, char **oenv, int i, int *ft, int *fd)
{
	if (i%2 != 0)
	{
		dup2(ft[0], 0);
		find_comand(cmd, env, oenv);
		exit(0);
	}
	else if(i%2 == 0)
	{
		dup2(fd[0], 0);
		find_comand(cmd, env, oenv);
		exit(0);
	}
}

void cmd_proc_two(t_cmd *cmd, t_env *env, char **oenv, int *ft, int *fd, int argc)
{
	pid_t	pid;
	int		err;
	int		i;

	i = 0;
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
				close(fd[1]);
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
				close(fd[0]);
		}
		i = 0;
		while(i <= argc)
		{
			waitpid(pid, &err, WUNTRACED | WCONTINUED);
			g_status_error = WEXITSTATUS(err);
			i++;
		}
}

void cmd_proc_many(t_cmd *cmd, t_env *env, char **oenv, int *ft, int *fd, int argc)
{
	pid_t	pid;
	int		err;
	int		flag;
	int		i;

	flag = 0;
	i = 0;
	while(i <= argc)
	{		
		if (cmd->next)
		{
			if (!flag)
				pipe(ft);
			else
				pipe(fd);
		}
		pid = fork();
		if (!pid)
		{
			if (i == argc)
				cmd_proc_last(cmd, env, oenv, i, ft, fd);
			cmd_proc(cmd, env, oenv, i, ft, fd, flag);
		}
		else
		{
			if (!flag && !cmd->next)
			{
				close(ft[0]);
				close(fd[1]);
			}
			else if (flag && !cmd->next)
			{				
				close(ft[1]);	
				close(fd[0]);
			}
			if (!flag)
			{
				if (fd[0])
					close(fd[0]);
				close(ft[1]);
			}
			else
			{
				if (ft[0])
					close(ft[0]);
				close(fd[1]);
			}
			if (!flag && cmd->next)
				flag = 1;
			else if (flag && cmd->next)
				flag = 0;
			cmd = cmd->next;
		}
		i++;
	}
	i = 0;
	while(i <= argc)
	{
		waitpid(pid, &err, WUNTRACED | WCONTINUED);
		g_status_error = WEXITSTATUS(err);
		i++;
	}
}