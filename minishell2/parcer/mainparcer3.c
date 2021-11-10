#include "../minishell.h"

void	ft_min_exit(void)
{
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	write(1, "exit\n", 5);
	exit(g_status_error);
}

int	print_prepars_invalid(char *str)
{
	ft_putstr_fd(str, 2);
	ft_putstr_fd(" : invalid command\n", 2);
	return (0);
}

int	preparser2(char *str, int *i)
{
	while (str[*i])
	{
		if (str[*i] == '\'')
			return (0);
		if (str[*i + 1] == '\0' && str[*i] != '\'')
			return (1);
		(*i)++;
	}
	return (0);
}

int	preparser3(char *str, int *i)
{
	while (str[*i])
	{
		if (str[*i] == '\"')
			return (0);
		if (str[*i + 1] == '\0' && str[*i] != '\"')
			return (1);
		(*i)++;
	}
	return (0);
}
