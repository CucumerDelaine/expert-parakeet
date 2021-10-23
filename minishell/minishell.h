#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <term.h>
# include <stdlib.h>
# include <string.h>
# include "libft/libft.h"
# include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>

typedef struct s_env {
	char			*key;
	char			*value;
	struct s_env	*next;
}				t_env;

typedef struct s_cmd {
	char			*cmd;
	char			**argum;
	char			**flags;
	int				flag_num;
	int				arg_num;
	int				active;
	int				fd_in;
	int				fd_out;
	int				back_d_red;
	int				fd_red;
	char			**red_words;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_pipex
{
	char	*addres;
	char	*addres_full;
	char	**strings_way;
	char	**comand;
	int		i;
}	t_pipex;

int	g_status_error;

char	*ft_quotes_one(char *str, int *i, t_cmd *cmd, t_env *our_env, char **env);
char	*ft_dollar(char *str, int *i, char **env);
int		ft_is_space(char c);
char	*ft_other_dollar(char *str, int *i);
int		ifkey(char c);
t_env	*ft_lstnew_env(char *key, char *value);
void	ft_lstadd_back_env(t_env **lst, t_env *new);
void	ft_lstclear_env(t_env **lst);
int		ft_error(char *str);
int		ft_fill_env(char **env, t_env **our_env);
int		service_char(char s);
t_cmd	*ft_lstnew_cmd(char *command);
void	ft_lstadd_flags(t_cmd **cmd, char *flag);
void	ft_lstadd_argum(t_cmd **cmd, char *argm);
void	ft_lstadd_back_cmd(t_cmd **lst, t_cmd *new);
int		ft_strncmp_nr(const char *s1, const char *s2, int n);
char	**get_flag(t_cmd *cmd);
void	free_memory(char **str1, char **str2);
char	*print_exit(t_pipex *str, int i);
char	*get_addres(char **oenvp, char *cmd_string);
void	call_execve_proc(t_cmd *cmd, char **oenv);
int		comand_exve(t_cmd *cmd, t_env *env, char **oenv);
int		find_comand(t_cmd *cmd, t_env *env, char **oenv);
int		logic(t_cmd **cmd_origin, t_env **env_origin, char **oenv);
int		path(char *name_programm);
int		check_key_value(t_env **env);
int		free_normi(t_pipex *a);
int		check_addres(t_env *env, char *cmd);
int		check_path(t_cmd *cmd, t_env *env);
void	plus_SHLVL(char **oenv);
void	check_minishel(char *name, char **oenv, t_cmd *cmd);
void	ft_free_cmd(t_cmd **new, char *str);
void	init_count(int *i, int *j);
void	norma2(t_cmd *cmd, int d);
int		service_char_with(char s);
void	ft_ctrl_c(int id);

// pipe.c
void	pipe_logic(t_cmd *cmd, t_env *env, char **oenv, int argc);
void	cmd_proc(int i, int *ft, int *fd);
void	cmd_proc_last(int i, int *ft, int *fd);
void	cmd_proc_two(t_cmd *cmd, t_env *env, char **oenv, int argc);
void	cmd_proc_many(t_cmd *cmd, t_env *env, char **oenv, int argc);
void	proc_close(t_cmd *cmd, int flag, int *ft, int *fd);
void	errr1(pid_t pid, int argc);
void	one_pipe_1(t_cmd *cmd, t_env *env, char **oenv, int *fd);
void	one_pipe_2(t_cmd *cmd, t_env *env, char **oenv, int *fd);
void	cmd_pipex(t_cmd *cmd, int *ft, int *fd, int flag);
int		switch_flag(t_cmd *cmd, int flag);
void	ebuch_norma(int i, int argc, int *ft, int *fd);
void	find_comand2(t_cmd *cmd, t_env *env, char **oenv);
void	init_flag_i(int *flag, int *i);

void	ft_delete_list_env(char *key, t_env **env);
t_env	*ft_find_list_env(char *find, t_env **env);
int		comand_unset(t_cmd *cmd, t_env *envp);
void	print_envp(t_env *envp, int fd);
int		comand_env(t_cmd *cmd, t_env *env);
int		comand_exit(t_cmd *cmd);

//readline
char	*readline(const char *line);
int		add_history(const char *line);
int		rl_on_new_line(void);
void	dl_redisplay(void);
void	rl_replace_line(const char *buffer, int val);

void	back_d_red(t_cmd *cmd);
void	ft_siginit_cat(void);

#endif
