#ifndef LIBFT_H
# define LIBFT_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

int				ft_isalnum(int ch);
int				ft_atoi(const char *str);
void			*ft_bzero(void *src, int a);
void			*ft_calloc(size_t number, size_t size);
int				ft_toupper(int ch);
int				ft_tolower(int ch);
char			*ft_strrchr (char *str, int ch);
char			*ft_strnstr (const char *str, const char *str2, size_t n);
int				ft_strncmp(const char *s1, const char *s2, unsigned int n);
int				ft_strlen(const char *str);
unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int size);
unsigned int	ft_strlcat(char *dest, const char *src, unsigned int size);
char			*ft_strdup(char *src);
char			*ft_strchr (char *str, int ch);
void			*ft_memset(void *src, int bat, int a);
void			*ft_memmove (void *destination, const void *source, size_t n);
void			*ft_memcpy(void *str, const void *rev, size_t n);
int				ft_memcmp (const void *arr1, const void *arr2, size_t n);
void			*ft_memchr (void *arrey, int c, size_t n);
void			*ft_memccpy(void *str, const void *rev, int c, size_t n);
int				ft_isprint(int ch);
int				ft_isdigit(int ch);
int				ft_isascii(int ch);
int				ft_isalpha(int ch);
int				ft_isalnum(int ch);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
char			**ft_split(char const *s, char c);
void			*ft_free_all_split_alloc(char **str, int nbr);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstadd_front(t_list **lst, t_list *new);
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstnew(void *content);
int				ft_lstsize(t_list *lst);

#endif
