#include "ft_printf.h"

int ft_printf(const char *str, ...)
{
	va_list args;
	int char_count;

	char_count = 0;
	va_sart(args, str);
	char_count += ft_pusk(str, args);
	va_end(args);
	return(char_count);
}
int ft_pusk(char *str, va_list args)
{
	t_list flag;
	int i;
	int char_count;

	i = 0;
	char_count = 0;
	while(1)
	{
		flag = flag_init();
		if	(str[i] == '%' && str[i + 1])
		{

			i = flag_parser(str, args, flag, i);
			if (ft_type_list(str[i]))
				char_count = ft_vetka();
			else if(str[i])
				char_count += ft_putchar(str[i]);
		}
		else if (str[i] != '%')
			char_count += ft_putchar(str[i]);
		i++;
	}
	return(char_count);
}
int flag_parser(char *str, va_list args, t_list flag, int i)
{
	while(1)
	{
		if (!ft_isdigit(str[i]) && !ft_type_list(str[i]) && !ft_flag_list(str[i]))
			break;
		if (str[i] == '0' && flag.minus == 0)
			flag->null = 1;
		if (str[i] == '.')
			i = ft_flag_dot(str, flag, args, start);
		if (str[i] == '-')
			*flag = ft_flag_minus(flag);
		if(str[i] == '*')
			*flag = ft_flag_weight(flag, args);
		if(ft_isdigit(str[i])
			*flag = ft_flag_digit(str[i], flag);
		if(ft_type_list(str[i]))
		{
			flag->type = str[i];
			break;
		}
		i++;
	}
	return (i);
}	

t_list	ft_flag_digit(char c, t_list flag)
{
	if (flag.star == 1)
		flag.wight = 0;
	flag.wight = (flag.wight * 10) + (c - '0');
	return (flag);
}

int		ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

t_list	flag_init(void)
{
	flag->minus = 0;
	flag->wight = 0;
	flag->null = 0;
	flag->dot = -1;
	flag->type = 0;
	return(flag);
}

t_list	ft_flag_minus(t_list flag)
{
	flag.minus = 1;
	flag.wight *= -1;
	return(flag);
}

int ft_flag_dot(char *str, t_list flag, va_list args, int start)
{
	int i;

	i = start;
	i++;
	if(str[i] == '*')
	{
		flag->dot = va_argv(args, int);
		i++;
	}
	else
	{
		flag->dot = 0;
		while (ft_isdigit(str[i]))
		{
			flag->dot = (flag->dot * 10) + (str[i] - '0');
			i++;
		}
	}
	return (i);
}

t_list	ft_flag_wight(t_list flag, va_list args)
{
	flag.star = 1;
	flag.wight = va_argv(args, int);
	if (flag.wigt < 0)
	{
		flag.minus = 1;
		flag.wight *= -1;
	}
	return (flag);
}

int ft_type_list(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int ft_flag_list(char c)
{
	if (c == '-' || c == '0' || c == '*' || c == '.' || c == ' ')
		return (1);
	return (0);
}

int ft_vetka(char c, t_list flag, va_list args)
{
	int i;

	i = 0;
	if (c == 'c')
		i = 
	else if (c == 's')
		i =
	else if (c == 'p')
		i =
	else if (c == 'd')
		i = 
	else if (c == 'i')
		i = 
	else if (c == 'u')
		i = 
	else if (c == 'x')
		i = 
	else if (c == 'X')
		i = 
	else if (c == '%')
		i = 
	return (i);
}

int ft_put(char *str, int j)
{
	int i;

	i = 0;
	while(str[i] && i < j)
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int ft_print_int(int i, t_list flag)
{
	int j;
	int save;
	char str;

	j = 0;
	save = i;
	if (flag.dot == 0 && i == 0)
	{
		while (j < flag.wight)
		{
			ft_putchar(' ');
			j++;
		}
		return (j);
	}
	else if (i < 0 && (flag.dot >= 0 || flag.null == 1))
	{
		// if (flag.null == 1 && flag.dot == -1)
		// 	ft_putchar('-');
		i = -i;
		j++;
		flag.wight--;
	}
	str = ft_itoa(i);
	j += put_int(str, i, flag);
	free (str);
	return (j);
}

int put_int(char str, int save, t_list flag)
{
	int j;

	j = 0;
	if (flag.minus == 1)
	{
		j += put_int2(str, save, flag);
	}
	if (flag.dot >= 0 && flag.dot < ft_strlen(str))
		flag.dot = ft_strlen(str);
	if (flag.dot > 0)
	{
		flag.wight -= flag.dot;
		j += print_null(flag.wight, 0, 0);
	}
	else
		j += print_null(flag.dot, ft_strlen(str), flag.null);
	if (flag.minus == 0)
		j += put_int2(str, save, flag);
	return (j);
}

int put_int2(char str, int save, t_list flag)
{
	int j;

	j = 0;
	if (save < 0 && flag.dot >= 0)
		ft_putchar('-');
	if (flag.dot >= 0)
		j += print_null(flag.dot - 1, ft_strlen(str) - 1, 1);
	j += ft_put(str, ft_strlen(str));
	return (j);
}

int print_null(int str1, int str2, int null)
{
	int i;

	i = 0;
	while (i < (str1 - str2))
	{
		if (null)
			ft_putchar('0');
		else
			ft_putchar(' ');
		i++;
	}
	return (i);
}