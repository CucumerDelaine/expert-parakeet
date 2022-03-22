#ifndef PARSER_H
# define PARSER_H

# include <stddef.h>
# include <stdlib.h>
# include <strings.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

typedef	struct s_listt {
	char			*str;
	struct s_listt	*next;
}	t_listt;

typedef struct s_config {
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	int		height;
	int		width;
	int		ceiling;
	int		floor;
	char	**map2;
}	t_config;

void	error_handler(int i);
int		file_check(char *fname);
int		get_map_line(t_listt **lst, int fd);
//config handler
void	init_config(t_config *config);
int		config_check(t_config *config);
int		get_config(int fd, t_config *config);
//list functions
void	add_list(t_listt **lst, char *str);
int		get_max_strlen(t_listt *lst);
int		lst_len(t_listt *lst);
int		list_checker(t_listt *lst);
void	list_clear(t_listt **lst);
//utils
char	**free_arr(char **arr);
int		check_if_empty(char *line);
int		line_check(const char *line);
int		check_rows(t_listt *lst, int i);
int		row_is_empty(t_listt *lst, int i);
int		get_value(char c, int *character);
char	**lst_to_map(t_listt *lst, t_config *config);
char	**free_all2(char **ret);
int		get_next_line2(int fd, char **line);
void	free_config(t_config *config);
int		parcer(char **argv, t_config *config);
int		ft_strlen2(const char *s);
char	**ft_split2(char const *s, char c);
void	*ft_memcpy2(void *dst, const void *src, size_t n);
void	*ft_memset2(void *b, int c, size_t len);
char	*ft_strdup2(const char *s1);
int		ft_strncmp2(const char *s1, const char *s2, size_t n);
int		ft_atoi2(const char *str);
size_t	ft_strlcpy2(char *dst, const char *src, size_t size);

#endif