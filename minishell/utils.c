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

int	ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit (1);
}

int service_char_with(char s)
{
	if (s == '>' || s == '<' || s == '|' || s == '\0' || ft_is_space(s) || s == '\'' || s == '\"')
		return (1);
	return (0);
}

int	service_char(char s)
{
	if (s == '>' || s == '<' || s == '|' || s == '\0' || ft_is_space(s))
		return (1);
	return (0);
}

int	ft_strncmp_nr(const char *s1, const char *s2, int n)
{
	char	*tmp1;
	char	*tmp2;
	int		i;

	i = 0;
	tmp1 = (char *)s1;
	tmp2 = (char *)s2;
	while (i < n)
	{
		if (tmp1[i] != tmp2[i] && tmp1[i] - tmp2[i] != 32
			&& tmp1[i] - tmp2[i] != -32)
			return (tmp1[i] - tmp2[i]);
		if (tmp1[i] == 0 && tmp2[i] == 0)
			return (0);
		i++;
	}
	return (0);
}
