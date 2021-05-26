#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct t_list
{
    int wight;
    int minus;
    int null;
    int star;
    int dot;
    int type;
}       t_list;

t_list flag_weight(t_list flag, va_list args);   //поставил вместо t_list int
int ft_printf(const char *str, ...);
int ft_pusk(char *str, va_list args);
int flag_parser(char *str, va_list args, t_list *flag, int i);
t_list	ft_flag_digit(char c, t_list flag); //поставил вместо t_list int
int		ft_isdigit(int c);
void	flag_init(t_list *flag);
t_list	ft_flag_minus(t_list flag);
int ft_flag_dot(char *str, t_list *flag, va_list args, int start);
int ft_type_list(char c);
int ft_flag_list(char c);
int ft_vetka(char c, t_list flag, va_list args);
int ft_put(char *str, int j);
int ft_print_int(int i, t_list flag);
int put_int(char *str, int save, t_list flag);
int put_int2(char *str, int save, t_list flag);
int print_null(int str1, int str2, int null);
int	ft_putchar(char c);
int	ft_strlen(const char *str);
int	stlen(int n);
static char	*itoa3(char *str, int n, int len, unsigned int j);
static char	*itoa2(char *str, int n);
char	*ft_itoa(int n);

#endif
