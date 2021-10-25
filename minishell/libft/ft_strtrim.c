#include "libft.h"

static int	ft_found_char(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static char	*ft_new_str(char const *s1, size_t start, size_t end)
{
	size_t	i;
	char	*s2;

	s2 = (char *)malloc(sizeof(char) * (end - start + 2));
	if (!s2)
		return (0);
	i = 0;
	while (start <= end)
	{
		s2[i] = s1[start];
		i++;
		start++;
	}
	s2[i] = 0;
	return (s2);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	char	*s2;

	i = 0;
	while (s1 && s1[i] && ft_found_char(s1[i], set))
		i++;
	if (s1 && s1[i])
	{
		start = i;
		i = ft_strlen(s1) - 1;
		while (s1[i] && ft_found_char(s1[i], set))
			i--;
		s2 = ft_new_str(s1, start, i);
		if (!s2)
			return (0);
	}
	else
	{
		s2 = (char *)malloc(sizeof(char));
		if (!s2)
			return (0);
		s2[0] = 0;
	}
	return (s2);
}
