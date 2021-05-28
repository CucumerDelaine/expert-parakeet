#include "ft_printf.h"

int ft_printf(const char *str, ...)
{
	va_list args;
	int char_count;

	char_count = 0;
	va_start(args, str);
	char_count += ft_pusk((char *)str, args);
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
	while(str[i])
	{
		flag_init(&flag);
		if	(str[i] == '%' && str[i + 1] != '\0')
		{
		    i++;
			i = flag_parser(str, args, &flag, i);
			if (ft_type_list(str[i]))
				char_count += ft_vetka((char)flag.type, flag, args);
			else if(str[i])
				char_count += ft_putchar(str[i]);
		}
		else if (str[i] != '%')
			char_count += ft_putchar(str[i]);
		i++;
	}
	return(char_count);
}
int flag_parser(char *str, va_list args, t_list *flag, int i)
{
	while(str[i])
	{
		if (!ft_isdigit(str[i]) && !ft_type_list(str[i]) && !ft_flag_list(str[i]))
			break;
		if (str[i] == '0' && flag->minus == 0 && flag->wight == 0)
			flag->null = 1;
		if (str[i] == '.')
			i = ft_flag_dot(str, flag, args, i);
		if (str[i] == '-')
			*flag = ft_flag_minus(*flag);
		if(str[i] == '*')
			*flag = flag_weight(*flag, args);
		if(ft_isdigit(str[i]))
			*flag = ft_flag_digit(str[i], *flag);
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

void	flag_init(t_list *flag)
{
	flag->minus = 0;
	flag->wight = 0;
	flag->null = 0;
	flag->dot = -1;
	flag->type = 0;
}

t_list	ft_flag_minus(t_list flag)
{
	flag.minus = 1;
	flag.wight *= -1;
	return(flag);
}

int ft_flag_dot(char *str, t_list *flag, va_list args, int start)
{
	int i;

	i = start;
	i++;
    if(str[start + 1] == '-')
        flag->wight = 0;
	if(str[i] == '*')
	{
		flag->dot = va_arg(args, int);
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

t_list	flag_weight(t_list flag, va_list args)
{
	flag.star = 1;
	flag.wight = va_arg(args, int);
	if (flag.wight < 0)
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
		i = print_char(va_arg(args, int), flag);
	else if (c == 's')
		i = ft_print_string(va_arg(args, char *), flag);
	else if (c == 'p')
		i = ft_print_pointer(args, flag);
	else if (c == 'd' || c == 'i')
		i = ft_print_int(va_arg(args, int), flag);
	else if (c == 'u')
		i = ft_print_ull(args, flag);
	else if (c == 'x')
		i = ft_print_hex(args, flag, 1);
	else if (c == 'X')
		i = ft_print_hex(args, flag, 0);
	else if (c == '%')
		i = put_procent(flag);
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

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}


int	stlen(int n)
{
	int				i;
	unsigned int	j;

	i = 0;
	if (n < 0)
	{
		i++;
		j = -n;
	}
	else
		j = n;
	while (j >= 1)
	{
		j = j / 10;
		i++;
	}
	return (i);
}

static char	*itoa3(char *str, int n, int len, unsigned int j)
{
	while (len > 0)
	{
		str[len] = (j % 10) + '0';
		j = j / 10;
		len--;
	}
	if (n > 0)
		str[0] = (j % 10) + '0';
	return (str);
}

static char	*itoa2(char *str, int n)
{
	int				len;
	int				i;
	unsigned int	j;

	i = 0;
	len = stlen(n);
	if (len == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	if (n < 0)
	{
		str[0] = '-';
		j = -n;
	}
	else
		j = n;
	str[len] = '\0';
	len--;
	itoa3(str, n, len, j);
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	i = stlen(n);
	if (i == 0)
		i = 1;
	str = malloc(i + 1);
	if (!(str))
		return (0);
	itoa2(str, n);
	return (str);
}

// int main()
// {
// 	int a;
// 	int b;

// 	a = ft_printf("Print: %30.20%30.20x\n", 1234567890);
// 	printf("%d\n", a);
// 	b = printf("Print: %30.20%30.20x\n", 1234567890);
// 	printf("%d\n", b);
// }