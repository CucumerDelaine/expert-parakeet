#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		char_count;

	char_count = 0;
	va_start(args, str);
	char_count += ft_pusk((char *)str, args);
	va_end(args);
	return (char_count);
}

int	ft_pusk(char *str, va_list args)
{
	t_list	flag;
	int		i;
	int		char_count;

	i = -1;
	char_count = 0;
	while (str[++i])
	{
		flag_init(&flag);
		if (!str[i])
			break ;
		else if (str[i] == '%' && str[i + 1] != '\0')
		{
			i = flag_parser(str, args, &flag, ++i);
			if (ft_type_list(str[i]))
				char_count += ft_vetka((char)flag.type, flag, args);
			else if (str[i])
				char_count += ft_putchar(str[i]);
			else if (str[i] == '\0')
				break ;
		}
		else if (str[i] != '%')
			char_count += ft_putchar(str[i]);
	}
	return (char_count);
}

int	flag_parser(char *str, va_list args, t_list *flag, int i)
{
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && !ft_type_list(str[i])
			&& !ft_flag_list(str[i]))
			break ;
		if (str[i] == '0' && flag->minus == 0 && flag->wight == 0)
			flag->null = 1;
		if (str[i] == '.')
			i = ft_flag_dot(str, flag, args, i);
		if (str[i] == '-')
			*flag = ft_flag_minus(*flag);
		if (str[i] == '*')
			*flag = flag_weight(*flag, args);
		if (ft_isdigit(str[i]))
			*flag = ft_flag_digit(str[i], *flag);
		if (ft_type_list(str[i]))
		{
			flag->type = str[i];
			break ;
		}
		i++;
	}
	return (i);
}	

int	ft_vetka(char c, t_list flag, va_list args)
{
	int	i;

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
