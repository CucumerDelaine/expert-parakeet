#include "push_swap.h"

int	checker_argv(char *argv)
{
	while (*argv)
	{
		if ((ft_atoi(argv) == -2147483648))
		{
			argv = argv + 2;
		}
		if ((!(ft_isdigit(*argv)) && *argv != '-') || \
		(ft_atoi(argv) > 2147483647) || (ft_atoi(argv) < -2147483648))
		{
			ft_putstr("Error");
			return (0);
		}
		argv++;
	}
	return (1);
}

int	checker_duplic(int *arr, int size)
{
	int	i;
	int	*arr_copy;

	i = 0;
	arr_copy = arr;
	arr_copy++;
	while (i < size)
	{
		while (*arr != *arr_copy && *(arr_copy + 1) != 0)
			arr_copy++;
		if (*arr == *arr_copy)
		{
			ft_putstr("Error");
			return (0);
		}
		arr++;
		arr_copy = arr;
		arr_copy++;
		i++;
	}
	return (1);
}

int	checker_sort(int *arr, int *arr_sort, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == arr_sort[i])
			i++;
		if (arr[i] != arr_sort[i] && i < size)
			return (0);
	}
	return (1);
}

int	found_at_buf(int arr, int *arr_sort, int size)
{
	int	i_in_sort;

	i_in_sort = 0;
	while (i_in_sort < size)
	{
		if (arr == arr_sort[i_in_sort])
		{
			return (i_in_sort);
		}
		else if (arr != arr_sort[i_in_sort])
		{
			i_in_sort++;
		}
	}
	return (0);
}
