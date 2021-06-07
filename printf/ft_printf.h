#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct s_list
{
	int	wight;
	int	minus;
	int	null;
	int	star;
	int	dot;
	int	type;
}				t_list;

t_list	flag_weight(t_list flag, va_list args);
int		ft_printf(const char *str, ...);
int		ft_pusk(char *str, va_list args);
int		flag_parser(char *str, va_list args, t_list *flag, int i);
t_list	ft_flag_digit(char c, t_list flag);
int		ft_isdigit(int c);
void	flag_init(t_list *flag);
t_list	ft_flag_minus(t_list flag);
int		ft_flag_dot(char *str, t_list *flag, va_list args, int start);
int		ft_type_list(char c);
int		ft_flag_list(char c);
int		ft_vetka(char c, t_list flag, va_list args);
int		ft_put(char *str, int j);
int		ft_print_int(int i, t_list flag);
int		put_int(char *str, int save, t_list flag);
int		put_int2(char *str, int save, t_list flag);
int		print_null(int str1, int str2, int null);
int		ft_putchar(char c);
int		ft_strlen(const char *str);
int		stlen(int n);
char	*ft_itoa(int n);
int		print_char(char c, t_list flag);
int		ft_print_string(char *str, t_list flag);
int		put_string(char *str, t_list flag);
int		ft_print_pointer(va_list args, t_list flag);
int		put_pointer(long long ul, t_list flag);
int		put_pointer2(long long ul, t_list flag);
int		ft_length_hex(unsigned long long n);
void	ft_putnbr_hex(unsigned long long nb);
int		ft_print_ull(va_list args, t_list flag);
int		put_ull(long long ul, t_list flag);
int		put_ull2(long long ul, t_list flag);
int		ft_length(long long int n);
void	ft_putnbr_ull(long long nb);
int		ft_print_hex(va_list args, t_list flag, int a);
int		put_hex(long long ul, t_list flag, int a);
int		put_hex2(long long ul, t_list flag, int a);
void	ft_putnbr_hex_XX(unsigned long long nb);
int		put_procent(t_list flag);

#endif
