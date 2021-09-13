#ifndef PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>

typedef struct s_pipex
{
	char	*addres;
	char	*addres_full;
	char	**strings_way;
	char	**comand;
	int		i;
}			t_pipex;

void	free_memory(char **str1, char **str2);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_free_all_split_alloc(char **str, int nbr);
char	**ft_split(char const *s, char c);
int     ft_strlen(const char *str);
int     ft_strncmp(const char *s1, const char *s2, unsigned int n);

#endif