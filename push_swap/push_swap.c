/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 14:29:41 by cdelaine          #+#    #+#             */
/*   Updated: 2021/08/08 14:29:43 by cdelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int vetka_func()
{
	int i;
	
}
int checker(char *argv)
{
	while(*argv)
	{
		if (ft_atoi(argv) == -2147483648)
		argv = argv + 2;
		if (!ft_isdigit(c) && *argv != '-' 
		|| (ft_atoi(argv) > 2147483647) || (ft_atoi(argv) < -2147483648))
		{
		ft_putstr("Error'\n");
		return (0);
		}
		argv++;
	}
	return (1);
}	

int digit(int *argc, char *argv, int *array, int *array_sort)
{
	char **ar;
	int i;

	ar = ft_split(argv, ' ');
	*argc = nb(argv) + 1;
	*array = malloc(sizeof(int)) * *argc + 1);
	*array_sort = malloc(sizeof(int)) * *argc + 1);
	if (!*arr || !*arr_sort)
		return (0);
	while (i < (argc - 1))
	{
		if (!checker(*ar))
			return (0);
		(*array)[i] = ft_atoi(*ar);
		(*array_sort)[i] = (*array)[i];
		i++;
		ar++;
	}
	ft_free_all_split_alloc(ar - i, i);
	return (1);
}

int main(int argc, char **argv)
{
	int *array;
	int *array_sort;

	if (argc == 1)
	{
		write(1, "\n", 1);
		return (0);
	}
	if (digit(&argc, *argv, *array, *array_sort) == 0)
		return (0);
	vetka_func();
}

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			write (1, &(s[i]), 1);
			i++;
		}
	}
	write (1, "\n", 1);
	return ;
}

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
