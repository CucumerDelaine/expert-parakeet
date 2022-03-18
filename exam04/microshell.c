#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

typedef struct s_cmd
{
	int fd[2];
	int type[2];
	char **args;
	int	fd_in;
}			t_cmd;

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

void fatal()
{
	write(2, "error: fatal\n", ft_strlen("error: fatal\n"));
	exit(1);
}

void exec(t_cmd *list, char **env)
{
	pid_t pid;
	int ex;

	if ((list->type[0] == 1 || list->type[1] == 1) && pipe(list->fd))
		fatal();
	if ((pid = fork()) < 0)
		fatal();
	if (pid == 0)
	{
		if (list->type[1] == 1 && dup2(list->fd[1], 1) < 0)
			fatal();
		if (list->type[0] == 1 && dup2(list->fd_in, 0) < 0)
			fatal();
		if ((ex = execve(list->args[0], list->args, env)) < 0)
		{
			write(2, "error: cannot execute ", ft_strlen("error: cannot execute "));
			write(2, list->args[0], ft_strlen(list->args[0]));
			write(2, "\n", 1);
		}
		exit(ex);
	}
	else
	{
		waitpid(pid, 0, 0);
		if (list->type[0] == 1 || list->type[1] == 1)
		{
			close(list->fd[1]);
			if (list->type[1] != 1)
				close(list->fd[0]);
		}
		if (list->type[0] == 1)
			close(list->fd_in);
	}
}

int list_len(t_cmd *list, int start, char **argv)
{
	int end;
	int len;

	end = start;
	while (argv[end] && strcmp(argv[end], ";") && strcmp(argv[end], "|"))
		end++;
	len = end - start;
	if (len > 0)
	{
		list->args = &argv[start];
		list->type[0] = list->type[1];
		if (!argv[end])
			list->type[1] = 0;
		else if (!strcmp(argv[end], "|"))
			list->type[1] = 1;
		else
			list->type[1] = 2;
		argv[end] = NULL;
		list->fd_in= list->fd[0];
	}
	return (end);
}

int main(int ac, char **av, char **env)
{
	t_cmd list;
	int i, start;

	i = 0;
	if (ac  > 1)
	{
		while (i < ac && av[++i])
		{
			start = i;
			i = list_len(&list, i, av);
			if (!strcmp(av[start], "cd"))
			{
				if (i - start != 2)
					write(2, "error: cd: bad arguments\n", ft_strlen("error: cd: bad arguments\n"));
				else if (chdir(list.args[1]) == -1)
				{
					write(2, "error: cd: cannot change directory to ", ft_strlen("error: cd: cannot change directory to "));
					write(2, list.args[1], ft_strlen(list.args[1]));
					write(2, "\n", 1);
				}
			}
			else if (i > start)
				exec(&list, env);
		}
	}
	return (0);
}