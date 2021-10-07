#include "libft.h"

char	*ft_strnstr(const char *big, const char *lit, size_t len)
{
	size_t	x;
	size_t	y;

	x = 0;
	if (*lit == '\0')
		return ((char *)big);
	while (big[x] != '\0' && x < len)
	{
		y = 1;
		if (big[x] == lit[0])
		{
			while ((big[x + y] == lit[y])
				&& (lit[y] != '\0') && x + y < len)
				y++;
			if (lit[y] == '\0')
				return ((char *)&big[x]);
		}
		x++;
	}
	return (NULL);
}

// int main()
// {
// 	char big[30] = "aaabcabcd";
// 	char lit[10] = "aabc";
// 	char *low;
// 	low = ft_strnstr(big, lit, -1);
// 	//low = strnstr(big, lit, -1);
// 	printf("%s", low);
// 	return(0);
// }
