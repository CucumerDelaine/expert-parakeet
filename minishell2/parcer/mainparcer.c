#include "../minishell.h"

int	preparser(char *str, int *i)
{
	int	j;

	j = 0;
	while (str[*i])
	{
		if (str[*i] == '\\' || str[*i] == ';')
			return (1);
		if (str[*i] == '\'')
		{
			(*i)++;
			if (str[*i] == '\0')
				return (1);
			j = preparser2(str, i);
		}
		if (str[*i] == '\"')
		{
			(*i)++;
			if (str[*i] == '\0')
				return (1);
			j = preparser2(str, i);
		}
		(*i)++;
	}
	return (j);
}

int	ft_minishell(t_env **our_env, char *str, char **env, t_cmd	**cmd)
{
	int		i;
	t_cmd	*new;

	i = -1;
	new = NULL;
	if (str == NULL)
		ft_min_exit();
	else if (str[0] != '\0')
	{
		add_history(str);
		str[ft_strlen(str) + 1] = '\0';
		while (str[++i])
		{
			if (preparser(str, &i))
				return (print_prepars_invalid(str));
		}
		if (postparser(str, new, cmd, our_env))
			return (ft_free_cmd(cmd, str));
		logic(cmd, our_env, env);
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

void	ft_signal_init(void)
{
	signal(SIGINT, ft_ctrl_c);
	signal(SIGQUIT, SIG_IGN);
}

int	main(int argc, char **argv, char **env)
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
			return (1);
	}
	return (0);
}

/// кейсы 
// "|"
//  
// dawdw "|" daw
