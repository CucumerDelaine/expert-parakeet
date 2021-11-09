#include "minishell.h"
#include "libft/libft.h"

int	ft_is_space(char c)
{
	return ((c >= 9 && c <= 13) || c == ' ');
}

int	ifkey(char c)
{
	if (c == '_' || ft_isalnum(c))
		return (1);
	return (0);
}

int	print_no_such(t_cmd *cmd)
{
	ft_putstr_fd(cmd->argum[0], 2);
	ft_putstr_fd(": No such file or directory", 2);
	ft_putstr_fd("\n", 2);
	return (1);
}
