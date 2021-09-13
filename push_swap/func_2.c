#include "push_swap.h"

int	ft_argv_len(char **argv)
{
	int	i;

	i = 0;
	while (*argv)
	{
		i++;
		(argv)++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}
