/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 14:50:19 by cdelaine          #+#    #+#             */
/*   Updated: 2021/09/08 14:50:20 by cdelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_addres(char **envp, char *cmd_string)
{
	t_pipex	str;

	str.i = 0;
	while (ft_strncmp(envp[str.i], "PATH=", 5))
		str.i++;
	str.strings_way = ft_split(envp[str.i] + 5, ':');
	str.comand = ft_split(cmd_string, ' ');
	str.i = 0;
	while (str.strings_way[str.i])
	{
		str.addres = ft_strjoin(str.strings_way[str.i], "/");
		str.addres_full = ft_strjoin(str.addres, str.comand[0]);
		free(str.addres);
		if (access(str.addres_full, F_OK) == 0)
		{
			free_memory(str.strings_way, str.comand);
			return (str.addres_full);
		}
		free(str.addres_full);
		str.i++;
	}
	ft_putstr_fd(str.comand[0], 2);
	ft_putstr_fd(": command not found\n", 2);
	free_memory(str.strings_way, str.comand);
	exit(5);
}

void	cmd1_process(int *ft, char **argv, char **envp)
{
	char	*program;
	int		infile;
	char	**cmd1;

	infile = open(argv[1], O_RDONLY);
	if (infile < 0)
	{
		perror(argv[1]);
		exit(7);
	}
	dup2(infile, STDIN_FILENO);
	dup2(ft[1], STDOUT_FILENO);
	close(ft[1]);
	close(ft[0]);
	cmd1 = ft_split(argv[2], ' ');
	program = get_addres(envp, argv[2]);
	execve(program, cmd1, envp);
}

void	cmd2_process(int *ft, char **argv, char **envp)
{
	char	*program;
	int		outfile;
	char	*file_name;
	char	**cmd2;

	outfile = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0664);
	if (outfile < 0)
	{
		perror(argv[4]);
		exit (6);
	}
	dup2(outfile, STDOUT_FILENO);
	dup2(ft[0], STDIN_FILENO);
	close(ft[0]);
	close(ft[1]);
	cmd2 = ft_split(argv[3], ' ');
	program = get_addres(envp, argv[3]);
	execve(program, cmd2, NULL);
}

void	new_proces(int *ft, char **argv, char **envp, int num_child)
{
	int	pid;

	pid = fork();
	if (pid < 0)
		exit (2);
	if (pid == 0 && num_child == 1)
		cmd1_process(ft, argv, envp);
	if (pid == 0 && num_child == 2)
		cmd2_process(ft, argv, envp);
}

int	main(int argc, char **argv, char **envp)
{
	int	ft[2];

	if (argc == 5)
	{
		if (pipe(ft) < 0)
			return (1);
		new_proces(ft, argv, envp, 1);
		wait(NULL);
		new_proces(ft, argv, envp, 2);
		close(ft[1]);
		close(ft[0]);
		wait(NULL);
		return (0);
	}
	else
		ft_putstr_fd("use: ./pipex infile cmd1 cmd2 outfile\n", 2);
	return (4);
}
