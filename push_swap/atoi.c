#include "push_swap.h"

int	ft_atoi(const char *str)
{
	long long int	p;
	long long int	n;
	long long int	i;

	i = 0;
	n = 1;
	p = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' \
	|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			n = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		p = ((p * 10) + (str[i] - 48));
		i++;
	}
	p = p * n;
	return (p);
}
