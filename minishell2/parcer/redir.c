#include "../minishell.h"

void	ft_forward_one(t_cmd **cmd, int *i, char *str)
{
	char	*file;
	int		fd_next;
	int		j;

	*i = (*i) + 2;
	while (ft_is_space(str[*i]))
		(*i)++;
	j = (*i);
	while (!service_char(str[(*i)]))
		(*i)++;
	file = ft_substr(str, j, (*i) - j);
	fd_next = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd_next < 0)
	{
		printf("%s\n", strerror(errno));
		exit(0);
	}
	(*cmd)->fd_out = fd_next;
	if (ft_strchr(str + (*i), '>'))
		close(fd_next);
	while (ft_is_space(str[*i]))
		(*i)++;
	free(file);
}

void	ft_forward_two(t_cmd **cmd, int *i, char *str)
{
	char	*file;
	int		fd_next;
	int		j;

	*i = (*i) + 1;
	while (ft_is_space(str[*i]))
		(*i)++;
	j = (*i);
	while (!service_char(str[(*i)]))
		(*i)++;
	file = ft_substr(str, j, (*i) - j);
	fd_next = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_next < 0)
	{
		printf("%s\n", strerror(errno));
		exit(0);
	}
	(*cmd)->fd_out = fd_next;
	if (ft_strchr(str + (*i), '>'))
		close(fd_next);
	while (ft_is_space(str[*i]))
		(*i)++;
	free(file);
}

void	ft_back_one(t_cmd **cmd, int *i, char *str)
{
	int	j;

	(*cmd)->back_d_red = 1;
	*i = (*i) + 2;
	while (ft_is_space(str[*i]))
		(*i)++;
	j = (*i);
	while (!service_char(str[(*i)]))
		(*i)++;
	(*cmd)->red_words[(*cmd)->word_num] = ft_substr(str, j, (*i) - j);
	(*cmd)->word_num++;
	while (ft_is_space(str[*i]))
		(*i)++;
}

void	ft_back_two(t_cmd **cmd, int *i, char *str)
{
	char	*file;
	int		fd_back;
	int		j;

	*i = (*i) + 1;
	while (ft_is_space(str[*i]))
		(*i)++;
	j = (*i);
	while (!service_char(str[(*i)]))
		(*i)++;
	file = ft_substr(str, j, (*i) - j);
	fd_back = open(file, O_RDONLY, 0644);
	if (fd_back < 0)
	{
		printf("%s\n", strerror(errno));
		exit(0);
	}
	(*cmd)->fd_in = fd_back;
	if (ft_strchr(str + (*i), '<'))
		close(fd_back);
	while (ft_is_space(str[*i]))
		(*i)++;
	free(file);
}

void	ft_redir(t_cmd **cmd, char *str, int *i)
{
	if (str[*i] == '>')
	{
		if (str[*i + 1] == '>')
			ft_forward_one(cmd, i, str);
		else if (str[*i + 1] != '>')
			ft_forward_two(cmd, i, str);
	}
	else if (str[(*i)] == '<')
	{
		if (str[(*i) + 1] == '<')
			ft_back_one(cmd, i, str);
		else if (str[*i + 1] != '<')
			ft_back_two(cmd, i, str);
	}
}
