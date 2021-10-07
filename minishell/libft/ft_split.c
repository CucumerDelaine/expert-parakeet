#include "libft.h"

static int	ft_whostrok(char const *s, char c)
{
	int	i;
	int	strok;

	i = 0;
	strok = 0;
	while (s[0] && s[0] == c)
		s++;
	while (s[0])
	{
		while (s[0] && s[0] != c)
			s++;
		while (s[0] && s[0] == c)
			s++;
		strok++;
	}
	return (strok);
}

static int	ft_symbols(char const *s, char c)
{
	int	len;

	len = 0;
	while (*s == c)
		s++;
	while ((*s != c) && *s)
	{
		s++;
		len++;
	}
	return (len);
}

static char	**ft_free_strok(char **res, int i)
{
	while (i >= 0)
	{
		free(res[i]);
		i--;
	}
	free(res);
	return (NULL);
}

static char	**ft_job(char **res, int strok, char const *s, char c)
{
	int	i;
	int	l;

	i = 0;
	while (i < strok)
	{
		res[i] = ((char *)malloc(sizeof(char)*(ft_symbols(s, c) + 1)));
		if (!res[i])
			return (ft_free_strok(res, i));
		while (*s == c)
			s++;
		l = 0;
		while (*s && (*s != c))
			res[i][l++] = *s++;
		res[i][l] = '\0';
		i++;
	}
	res[i] = 0;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		strok;
	char	**res;

	i = 0;
	if (!s)
		return (NULL);
	strok = ft_whostrok(s, c);
	res = (char **)malloc((strok + 1)* sizeof(char *));
	if (!res)
		return (NULL);
	res = ft_job(res, strok, s, c);
	return (res);
}
