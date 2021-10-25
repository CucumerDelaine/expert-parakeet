#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned long int	i;
	unsigned char		*destv;
	const unsigned char	*srcv;

	destv = (unsigned char *)dest;
	srcv = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		while (srcv[i] != (unsigned char)c)
		{
			(destv[i] = srcv[i]);
			i++;
			if (i == n)
				return (NULL);
		}
		destv[i] = srcv[i];
		if (srcv[i] == (unsigned char)c)
			return (destv + (i + 1));
	}
	return (NULL);
}
