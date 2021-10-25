#include "minishell.h"

void ft_init_iter(t_iter **iter)
{
	*iter = malloc(sizeof(t_iter));
	(*iter)->i = 0;
	(*iter)->j = 0;
	(*iter)->tmp = NULL;
	(*iter)->full = 0;
}

int ft_shr_print(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if (ft_isprint(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int ft_search_sumb(char *tmp2)
{
	if (ft_strchr(tmp2, '<') || ft_strchr(tmp2, '>') || ft_strchr(tmp2, '|'))
		return (1);
	else
		return (0);
}

char *ft_quotes_two_two(char *str, int *i, char **env)
{
	int j = *i;
	char *tmp;
	char *tmp2;
	char *tmp3;

	char *freez;
	(*i)++;
	while (str[*i])
	{
		if (str[(*i)] == '\"')
			break;
		if (str[*i] == '$')
		{
			tmp = str;
			str = ft_dollar(str, i, env);
			free(tmp);
			tmp = NULL;
		}
		(*i)++;
	}
	tmp = ft_substr(str, 0, j);
	tmp2 = ft_substr(str,j + 1 , *i - j - 1);
	tmp3 = ft_strdup(str + *i + 1);
	// freez = str;
	str = ft_strjoin(tmp, tmp2);
	// free(freez);
	// freez = NULL;
	*i -= 1;
	str = ft_strjoin(str, tmp3);
	if (ft_strlen(tmp) == 0 && ft_strlen(tmp2) == 0)
		return (NULL);
	free(tmp);
	tmp = NULL;
	free(tmp2);
	tmp2 = NULL;
	return (str);
}

char *ft_quotes_one_two(char *str, int *i)
{
	int j = *i;
	char *tmp = NULL;
	char *tmp2 = NULL;
	char *tmp3 = NULL;
	char *freez;

	while (str[++(*i)])
	{
		if (str[(*i)] == '\'')
			break;
	}
	tmp = ft_substr(str, 0, j);
	tmp2 = ft_substr(str,j + 1 , *i - j - 1);
	tmp3 = strdup(str + *i + 1);
	str = ft_strjoin(tmp, tmp2);
	freez = str;
	free(freez);
	str = ft_strjoin(str, tmp3);
	free(tmp);
	tmp = NULL;
	free(tmp2);
	tmp2 = NULL;
	free(tmp3);
	tmp3 = NULL;
	*i -=  1;
	return (str);
}

char *ft_quotes_one(char *str, int *i, t_cmd *cmd, t_env *our_env, char **env)
{
	int j = *i;
	char *tmp = NULL;
	char *tmp2 = NULL;
	char *tmp3 = NULL;
	char *freez;

	while (str[++(*i)])
	{
		if (str[(*i)] == '\'')
			break;
	}
	tmp = ft_substr(str, 0, j);
	tmp2 = ft_substr(str,j + 1 , *i - j - 1);
	tmp3 = strdup(str + *i + 1);
	// if (!ft_shr_print(tmp) && ft_strchr(tmp2, ' '))
	// {
	// 	// if (ft_src_sp_one(tmp3))
	// 	cmd = ft_lstnew_cmd(tmp2);
	// 	logic(&cmd, &our_env, env);
	// 	return(0);
	// }
	if (ft_search_sumb(tmp2))
	{
		free(tmp);
		tmp = NULL;
		free(tmp2);
		tmp2 = NULL;
		free(tmp3);
		tmp3 = NULL;
		return(str);
	}
	str = ft_strjoin(tmp, tmp2);
	*i = ft_strlen(str) - 1;
	freez = str;
	free(freez);
	// freez = str;
	str = ft_strjoin(str, tmp3);
	// free(freez);
	// freez = NULL;
	free(tmp);
	tmp = NULL;
	free(tmp2);
	tmp2 = NULL;
	free(tmp3);
	tmp3 = NULL;
	return (str);
}

char *ft_quotes_two(char *str, int *i, t_cmd *cmd, t_env *our_env, char **env)
{
	int j = *i;
	char *tmp;
	char *tmp2;
	char *tmp3;

	char *freez;
	(*i)++;
	while (str[*i])
	{
		if (str[(*i)] == '\"')
			break;
		if (str[*i] == '$')
		{
			// tmp = str;
			str = ft_dollar(str, i, env);
			// free(tmp);
			// tmp = NULL;
		}
		(*i)++;
	}
	tmp = ft_substr(str, 0, j);
	tmp2 = ft_substr(str,j + 1 , *i - j - 1);
	tmp3 = ft_strdup(str + *i + 1);
	// if (!ft_shr_print(tmp) && ft_strchr(tmp2, ' '))
	// {
	// 	cmd = ft_lstnew_cmd(tmp2);
	// 	logic(&cmd, &our_env, env);
	// 	return(0);
	// }
	if (ft_search_sumb(tmp2))
	{
		free(tmp);
		tmp = NULL;
		free(tmp2);
		tmp2 = NULL;
		free(tmp3);
		tmp3 = NULL;
		return(str);
	}
	freez = str;
	str = ft_strjoin(tmp, tmp2);
	free(freez);
	freez = NULL;
	*i = ft_strlen(str) - 1;
	// freez = str;
	str = ft_strjoin(str, tmp3);
	// free(freez);
	// freez = NULL;
	if (ft_strlen(tmp) == 0 && ft_strlen(tmp2) == 0)
		return (NULL);
	// free(freez);
	// freez = NULL;
	// free(tmp);
	// tmp = NULL;
	// free(tmp2);
	// tmp2 = NULL;
	return (str);
}
// dwaadwawdwada w d dwadwawad"wdawad$USER" da
char *ft_dollar(char *str, int *i, char **env)
{
	int j = *i;
	char *tmp = NULL;
	char *tmp2 = NULL;
	char *tmp3 = NULL;
	char *freez = NULL;
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
	tmp[ft_strlen(tmp)] = '=';
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
		tmp2 = ft_substr(tmp2, ft_strlen(tmp), ft_strlen(tmp2) - ft_strlen
		(tmp));
		freez = tmp;
		tmp = ft_substr(str, 0, j);
		free(freez);
		freez = NULL;
		tmp3 = ft_substr(str, *i, ft_strlen(str) - *i);
		freez = str;
		str = ft_strjoin(tmp, tmp2);
		free(freez);
		freez = NULL;
		freez = str;
		str = ft_strjoin(str, tmp3);
		free(freez);
		freez = NULL;
	}
	else
	{
		freez = tmp;
		tmp = ft_substr(str, 0, j);
		free(freez);
		freez = NULL;
		tmp3 = ft_substr(str, *i, ft_strlen(str) - *i - 1);
		if (ft_strlen(tmp) == 0 && ft_strlen(tmp3) == 0)
			return(NULL);
		// freez = str;
		str = ft_strjoin(tmp, tmp3);
		// free(freez);
		// freez = NULL;
	}
	return (str);
}

char *ft_other_dollar(char *str, int *i)
{
	char *tmp;
	char *tmp2;
	char *tmp3;

	(*i)++;
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

void	ft_redir(t_cmd **cmd, char *str, int *i, int *red)
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
			free(file);
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
			free(file);
			// printf ("file = |%s|\n", file);
			// printf ("str = %s\n", str + (*i));
			// printf("fd == %d\n", fd_next);
		}

	}
	else if (str[(*i)] == '<')
	{
		if (str[(*i) + 1] == '<')
		{
			(*cmd)->back_d_red = 1;
			*i = (*i) + 2;
			while (ft_is_space(str[*i]))
				(*i)++;
			j = (*i);
			while (!service_char(str[(*i)]))
				(*i)++;
			(*cmd)->red_words[(*red)] = ft_substr(str, j, (*i) - j);
			(*red)++;
			while (ft_is_space(str[*i]))
				(*i)++;
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
			free(file);
		}
	}
	//	printf("STROKA = %s", str);
}

void	ft_free_cmd(t_cmd **new, char *str)
{
	int i;
	t_cmd *tmp;

	if (!new)
		return;
	if (*new != NULL)
	{
		while (*new)
		{
			i = 0;
			if ((*new)->flags[i])
			{
				while ((*new)->flags[i] != NULL)
				{
					// write(1,"fla\n",4);
					// printf("%s\n",(*new)->flags[i]);
					free((*new)->flags[i]);
					i++;
				}
			}
			i = 0;
			if ((*new)->argum[i])
			{
				while ((*new)->argum[i] != NULL)
				{
					// write(1,"arg\n",4);
					free((*new)->argum[i]);
					i++;
				}
			}
			i = 0;
			if ((*new)->red_words[i])
			{
				while((*new)->red_words[i] != NULL)
				{
					free((*new)->red_words[i]);
					i++;
				}
			}
			free((*new)->cmd);
			(*new)->cmd = NULL;
			free((*new)->red_words);
			(*new)->red_words = NULL;
			free((*new)->flags);
			(*new)->flags = NULL;
			free((*new)->argum);
			(*new)->argum = NULL;
			tmp = *new;
			(*new) = ((*new)->next);
			free(tmp);
			tmp = NULL;
		}
		free(str);
		str = NULL;
		// free(*new);
		// *new = NULL;
	}


}

int	postparser(char *str, t_cmd  *new, t_cmd **cmd, char **env, t_env **our_env)
{
	char *word;
	char *argum;
	char *flags;
	int red;
	char *res;
	t_iter *iter;
	ft_init_iter(&iter);
	int i;
	int j;

	i = 0;
	red = 0;
	word = NULL;
	argum = NULL;
	flags = NULL;
	res = NULL;
	str = ft_strtrim(str, "\t\n\v\f\r ");
	if (str[i] == '\0')
		return (1);
	// printf("str = |%s|\n", str);
	while (str[i])
	{
		if (str[i] == '\'')
			str = ft_quotes_one(str, &i, *cmd, *our_env, env);
		else if (str[i] == '$')
			str = ft_dollar(str, &i, env);
		else if (str[i] == '\"')
			str = ft_quotes_two(str, &i, *cmd, *our_env, env);
		if ((ft_is_space(str[i + 1]) || str[i + 1] == '\0') && iter->full == 0)
		{
			res = ft_substr(str, 0, i + 1);
			iter->full = 1;
			iter->i = i;
		}
		i++;
		if (str == NULL)
			return (1);
	}
	i = 0;
	while (str[i] != '\0')
	{
		while (ft_is_space(str[i]))
			i++;
		if (!service_char(str[i])) //команда
		{
			j = i;
			if (str[i] == '\'' && (str[i + 1] == '|' || str[i + 1] == '<' || str[i + 1] == '>'))
				str = ft_quotes_one_two(str, &i);
			else if (str[i] == '\"' && (str[i + 1] == '|' || str[i + 1] == '<' || str[i + 1] == '>'))
				str = ft_quotes_two_two(str, &i, env);
			while (!service_char(str[i]))
				i++;
			if (res == NULL)
			{
				word = ft_substr(str, j, i - j);
				new = ft_lstnew_cmd(word);
			}
			else
			{
				new = ft_lstnew_cmd(res);
				res = NULL;
			}
			while (ft_is_space(str[i]) && str[i] != '\0')
				i++;
			while (str[i] == '-' && !service_char(str[i + 1])) // флаги
				{
				j = i;
				while (!service_char(str[i]))
					i++;
				flags = ft_substr(str, j, i - j); // добавление нескольких флагов
				ft_lstadd_flags(&new, flags);
				free(flags);
				flags = NULL;
				while (ft_is_space(str[i]) && str[i] != '\0')
					i++;
				}
			while (!service_char(str[i])) // аргументы
				{
				j = i;
				if (str[i] == '\'' && (str[i + 1] == '|' || str[i + 1] == '<' || str[i + 1] == '>'))
					str = ft_quotes_one_two(str, &i);
				else if (str[i] == '\"' && (str[i + 1] == '|' || str[i + 1] == '<' || str[i + 1] == '>'))
					str = ft_quotes_two_two(str, &i, env);
				while (!service_char_with(str[i]))
					i++;
				argum = ft_substr(str, j, i - j);
				ft_lstadd_argum(&new, argum);
				free(argum);
				argum = NULL;
				while (ft_is_space(str[i]) && str[i] != '\0')
					i++;
				}
			}
		// TODO тут утечка у str
		else if (str[i] == '|')
		{
			i++;
			while (ft_is_space(str[i]) && str[i] != '\0')
				i++;
			ft_lstadd_back_cmd(cmd, new);
			new = NULL;
		}
		else if ((str[i] == '>' || str[i] == '<'))
		{
			if (new == NULL)
				new = ft_lstnew_cmd(NULL);
			ft_redir(&new, str, &i, &red);
		}
		if (str[i] == '\0')
		{
			ft_lstadd_back_cmd(cmd, new);
			new = NULL;
			free(word);
			word = NULL;
		}
		// printf("cmd == %s, flags == %s, argum %s\n", (*cmd)->cmd, (*cmd)->flags[0], (*cmd)->argum[0]);
		// echo qwe '|' qwe
	}
	// i = 0;
	// while ((*cmd)->red_words[i])
	// {
	// printf("flags %s\n", (new)->red_words[0]);
	// printf("flags %s\n", (new)->red_words[1]);
	// printf("flags %s\n", (*cmd)->red_words[0]);
	// printf("flags %s\n", (*cmd)->red_words[3]);

	// 	i++;
	// }
	// i = 0;
	// while((*cmd)->argum[i])
	// {
	// 	printf("argum %s\n", (*cmd)->argum[i]);
	// 	i++;
	// }
	return (0);
}

int	preparser(char *str, int *i)
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

int	ft_minishell(t_env **our_env, char *str, char **env, t_cmd	**cmd)
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
	else if (str[0] != '\0')
	{
		add_history(str);
		str[ft_strlen(str) + 1] = '\0';
		while (str[++i])
		{
			if (preparser(str, &i))
			{
				ft_putstr_fd(str, 2);
				ft_putstr_fd(" : invalid command\n", 2);
				return (0);
			}

		}
		// i = -1;
		// if (parser(str, env, *cmd, &new, our_env)) // TODO убрать утечки у доллара
		// 	return (0);
		if (postparser(str, new, cmd, env, our_env))
			return (0);
		// "daw dwa dwa " <<; 1 не работает
		
		logic(cmd, our_env, env);
		// printf ("str = |%s|\n", str);
		ft_free_cmd(cmd, str);
	}
	else
		free(str);

	return (0);

}

void	ft_ctrl_c(int id)
{
	if (id == SIGINT)
	{
		rl_on_new_line();
		rl_redisplay();
		write(1, "  \n", 3);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	ft_signal_init()
{
	signal(SIGINT, ft_ctrl_c);
	signal(SIGQUIT, SIG_IGN);
}

int	main(int argc, char **argv, char **env) // сделать выполнение команд c ctrl-C ctrl-D ctrl-
{
	t_cmd	*cmd;
	t_env	*our_env;

	(void ) argc;
	(void ) argv;
	if (ft_fill_env(env, &our_env))
		(ft_error("error_malloc"));
	while (1)
	{
		cmd = NULL;
		ft_signal_init();
		if (ft_minishell(&our_env, readline("minishell:> "), env, &cmd))
			return(1);
	}
	return (0);
}