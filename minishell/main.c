#include "minishell.h"

char *ft_quotes_one(char *str, int *i)
{
	int j = *i;
	char *tmp;
	char *tmp2;
	char *tmp3;
	while (str[++(*i)])
	{
		if (str[(*i)] == '\'')
			break;
	}
	tmp = ft_substr(str, 0, j);
	tmp2 = ft_substr(str,j + 1 , *i - j - 1);
	tmp3 = strdup(str + *i + 1);
	str = ft_strjoin(tmp, tmp2);
	str = ft_strjoin(str, tmp3);

//	*i = ft_strlen(tmp2) - 1;
//	printf("tmp = |%s|\n", tmp);
//	printf("tmp2 = |%s|\n", tmp2);
//	printf("str = |%s|\n", str);
//	printf("i = |%d|\n", *i);
	return (str);
}

char *ft_quotes_two(char *str, int *i, char **env)
{
	int j = *i;
	char *tmp;
	char *tmp2;
	//	char *tmp3;
	while (str[*i])
	{
		if (str[(*i)] == '\"')
			break;
		if (str[*i] == '$')
			str = ft_dollar(str, i, env);
		i++;
	}
	tmp = ft_substr(str, 0, j);
	tmp2 = ft_substr(str,j + 1 , ft_strlen(str));
	str = ft_strjoin(tmp, tmp2);
	return (str);
}
char *ft_dollar(char *str, int *i, char **env)
{
	int j = *i;
	char *tmp;
	char *tmp2;
	char *tmp3;
	int q;

	q = 0;
	if (str[*i + 1] == '$' || str[*i + 1] == '?' || str[*i + 1]
	== ' ' || ft_is_space(str[*i + 1]))
		return (ft_other_dollar(str, i));
	while (str[++(*i)])
	{
		if (!ifkey(str[*i]))
			break;
	}
	if (*i == j + 1)
		return (str);
	tmp = ft_substr(str, j + 1, *i - j - 1);
	tmp[*i] = '=';
	tmp[*i + 1] = '\0';
	while (env[q])
	{
		 tmp2 = ft_strnstr(env[q], tmp, ft_strlen(tmp));
		 if (tmp2)
		 	break;
		q++;
	}
	if (tmp2)
	{
		tmp2 = ft_substr(tmp2, ft_strlen(tmp) + 1, ft_strlen(tmp2) - ft_strlen
		(tmp));
		tmp = ft_substr(str, 0, j);
		tmp3 = ft_substr(str, *i, ft_strlen(str) - *i);
		str = ft_strjoin(tmp, tmp2);
		str = ft_strjoin(str, tmp3);
	}
	else
	{
		tmp = ft_substr(str, 0, j);
		tmp3 = ft_substr(str, *i, ft_strlen(str) - *i);
		str = ft_strjoin(tmp, tmp3);
	}
//	printf("tmp = |%s|\n", tmp);
//	printf("tmp2 = |%s|\n", tmp2);
//	printf("tmp3 = |%s|\n", tmp3);
//	printf("str = |%s|\n", str);
	return (str);
}

char *ft_other_dollar(char *str, int *i)
{
	char *tmp;
	char *tmp2;
	char *tmp3;

	if (str[*i] == '$')
	{
		tmp = ft_substr(str,0 ,*i - 1);
		tmp2 = ft_itoa(getpid());
		tmp3 = ft_strdup(str + *i + 1);
		str = ft_strjoin(tmp, tmp2);
		str = ft_strjoin(str, tmp3);
//		printf("%s\n", str);
	}
	else if (str[*i] == '?')
	{
		tmp = ft_substr(str,0 ,*i - 1);
		tmp2 = ft_itoa(g_status_error); // узнать чему равно это значение
		tmp3 = ft_strdup(str + *i + 1);
		str = ft_strjoin(tmp, tmp2);
		str = ft_strjoin(str, tmp3);
	}
//	else if (str[*i] == '\0' || ft_is_space(str[*i]))
//	{
//		tmp = ft_substr(str,0 ,*i - 1);
//		tmp2 = ft_strdup("$");
//		tmp3 = ft_strdup(str + *i);
//		str = ft_strjoin(tmp, tmp2);
//		str = ft_strjoin(str, tmp3);
//	}
	return(str);
}
char *parser(char *str, char **env)
{
	int i;

	i = 0;
	while(str[i])
	{
		if (str[i] == '\'')
			str = ft_quotes_one(str, &i);
		if (str[i] == '$')
			str = ft_dollar(str, &i, env);
		if (str[i] == '\"')
			str = ft_quotes_two(str, &i, env);
		i++;
	}
	return (str);
}

void ft_redir(t_cmd **cmd, char *str, int *i)
{
	int j;
	char *file;
	int fd_next;
	int fd_back;

	if (str[*i] == '>')
	{
		if (str[*i + 1] == '>')
		{
			*i = (*i) + 2;
			while (ft_is_space(str[*i]))
				(*i)++;
			j = (*i);
			while (!service_char(str[(*i)]))
				(*i)++;
			file = ft_substr(str, j, (*i) - j); // сделать для нескольких файлов
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
			// printf ("file = |%s|\n", file);
		}
		else if (str[*i + 1] != '>')
		{
			*i = (*i) + 1;
			while (ft_is_space(str[*i]))
				(*i)++;
			j = (*i);
			while (!service_char(str[(*i)]))
				(*i)++;
			file = ft_substr(str, j, (*i) - j); // сделать для нескольких файлов
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
			// printf ("file = |%s|\n", file);
//			printf ("str = %s\n", str + (*i));
//			printf("fd == %d\n", fd_next);
		}

	}
	else if (str[(*i)] == '<')
	{
		if (str[(*i) + 1] == '<')
		{
			;
		}
		else if (str[*i + 1] != '<')
		{
			*i = (*i) + 1;
			while (ft_is_space(str[*i]))
				(*i)++;
			j = (*i);
			while (!service_char(str[(*i)]))
				(*i)++;
			file = ft_substr(str, j, (*i) - j); // сделать для нескольких файлов
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
		}
	}
//	printf("STROKA = %s", str);
}
int postparser(char *str, t_env **our_env, t_cmd *new, t_cmd **cmd)
{
	char *word;
	char *argum;
	char *flags;

	int i;
	int j;

	i = 0;
	while (ft_is_space(str[i]))
		i++;
	while (str[i] != '\0')
	{
		if (!service_char(str[i])) //команда
		{
			j = i;
			while (!service_char(str[i]))
				i++;
			word = ft_substr(str, j, i - j);
			new = ft_lstnew_cmd(word);
			// printf("command = %s\n", new->cmd);
			while (ft_is_space(str[i]) && str[i] != '\0')
				i++;
			while (str[i] == '-' && !service_char(str[i + 1])) // флаги
			{
				j = i;
				while (!service_char(str[i]))
					i++;
				flags = ft_substr(str, j, i - j); // добавление нескольких флагов
				ft_lstadd_flags(&new, flags);
				printf("flags = %s\n", flags);
				while (ft_is_space(str[i]) && str[i] != '\0')
					i++;
			}
			while (!service_char(str[i])) // аргументы
			{
				j = i;
				while (!service_char(str[i]))
					i++;
				argum = ft_substr(str, j, i - j);
				ft_lstadd_argum(&new, argum);
				// printf("argum = %s\n", argum);
				while (ft_is_space(str[i]) && str[i] != '\0')
					i++;
			}
		}
		else if (str[i] == '|')
		{
			i++;
			while (ft_is_space(str[i]) && str[i] != '\0')
				i++;
		}
		ft_lstadd_back_cmd(cmd, new);
		free(new);
		new = NULL;
		if (str[i] == '>' || str[i] == '<')
		{
			ft_redir(cmd, str, &i);
		}
	}
//	i = 0;
//	while ((*cmd)->flags[i])
//	{
//		printf("flags - %s\n", (*cmd)->flags[i]);
//		i++;
//	}
//	i = 0;
//	while((*cmd)->argum[i])
//	{
//		printf("argum - %s\n", (*cmd)->argum[i]);
//		i++;
//	}
	return (0);
}

int preparser(char *str, int *i)
{
	while (str[*i])
	{
		if (str[*i] == '\\' || str[*i] == ';')
			return 1;
		if (str[*i] == '\'')
		{
			(*i)++;
			if (str[*i] == '\0')
				return (1);
			while (str[*i])
			{
				if (str[*i] == '\'')
					return 0;
				if (str[*i + 1] == '\0' && str[*i] != '\'')
					return 1;
				(*i)++;
			}
		}
		if (str[*i] == '\"')
		{
			(*i)++;
			if (str[*i] == '\0')
				return (1);
			while (str[*i])
			{
				if (str[*i] == '\"')
					return 0;
				if (str[*i + 1] == '\0' && str[*i] != '\"')
					return 1;
				(*i)++;
			}
		}
		(*i)++;
	}
//	printf("str = %s\n", str);
	return 0;
}

int ft_minishell(t_env **our_env, char *str, char **env, t_cmd	**cmd)
{
	int i;
	t_cmd *new;

	i = -1;
	new = NULL;
	if (str == NULL)
	{
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		write(1, "exit\n", 5);
		exit(g_status_error);
	}
	else
	{
		add_history(str);
		str[ft_strlen(str) + 1] = '\0';
		while (str[++i])
		{
			if (preparser(str, &i))
				return(ft_error("Unknown command\n"));
		}
		i = -1;
		str = parser(str, env);
		postparser(str,our_env, new, cmd);
			// return (ft_error("invalid command"));
		logic(cmd, our_env, env);
		// printf ("str = |%s|\n", str);
	}
	return (0);

}

void my_handler (int signum)
{
	if (signum == SIGINT)
	{
		ft_putchar_fd('\n', 1);

	}
}

int main(int argc, char **argv, char **env) // сделать выполнение команд c ctrl-C ctrl-D ctrl-
{
	t_cmd	*cmd;
	t_env	*our_env;

	(void ) argc;
	(void ) argv;
	if (ft_fill_env(env, &our_env))
		(ft_error("error_malloc"));
//	while (our_env->next)
//	{
//		printf("key = %s, value = %s\n", our_env->key, our_env->value);
//		our_env = our_env->next;
//	}
	while (1)
	{
		cmd = NULL;
		signal(SIGINT,my_handler);
		if (ft_minishell(&our_env, readline("<minishell>"), env, &cmd))
			return(1);
	}
	return (0);
}
