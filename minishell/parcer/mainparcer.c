#include "../minishell.h"

int    ft_strchr_n(const char *s, int c)
{
    int i;

    i = 0;
    while (s[i])
    {
        if (s[i] == (unsigned char)c)
            return (i);
        i++;

    }
    if (s[i] == (unsigned char)c)
        return (i);
    return (0);
}

void ft_init_iter(t_iter **iter)
{
    *iter = malloc(sizeof(t_iter));
    (*iter)->tmp = NULL;
    (*iter)->full = 0;
	(*iter)->res = NULL;
	(*iter)->word = NULL;
	(*iter)->argum = NULL;
	(*iter)->flags = NULL;
}

int ft_shr_print(char *str)
{
    int i;

    i = 0;
    while(str[i])
    {
        if (ft_isprint(str[i]))
            return (1);
        i++;
    }
    return (0);
}

void	ft_free_cmd_cont(t_cmd **new)
{
	t_cmd	*tmp;

	free((*new)->cmd);
    (*new)->cmd = NULL;
    free((*new)->red_words);
    (*new)->red_words = NULL;
    free((*new)->flags);
    (*new)->flags = NULL;
    free((*new)->argum);
    (*new)->argum = NULL;
    tmp = *new;
    (*new) = ((*new)->next);
    free(tmp);
    tmp = NULL;
}

int    ft_free_cmd(t_cmd **new, char *str)
{
    int i;
   
    if (!new)
        return (1);
    if (*new != NULL)
    {
        while (*new)
        {
			i = -1;
            while ((*new)->flags[++i] != NULL)
                free((*new)->flags[i]);
			i = -1;
            while ((*new)->argum[++i] != NULL)
                free((*new)->argum[i]);
			i = -1;
            while((*new)->red_words[++i] != NULL)
                free((*new)->red_words[i]);
            ft_free_cmd_cont(new);
        }
    }
	return (0);
}

int    preparser(char *str, int *i)
{
    while (str[*i])
    {
        if (str[*i] == '\\' || str[*i] == ';')
            return 1;
        if (str[*i] == '\'')
        {
            (*i)++;
            if (str[*i] == '\0')
                return (1);
            while (str[*i])
            {
                if (str[*i] == '\'')
                    return 0;
                if (str[*i + 1] == '\0' && str[*i] != '\'')
                    return 1;
                (*i)++;
            }
        }
        if (str[*i] == '\"')
        {
            (*i)++;
            if (str[*i] == '\0')
                return (1);
            while (str[*i])
            {
                if (str[*i] == '\"')
                    return 0;
                if (str[*i + 1] == '\0' && str[*i] != '\"')
                    return 1;
                (*i)++;
            }
        }
        (*i)++;
    }
    return 0;
}

int    ft_minishell(t_env **our_env, char *str, char **env, t_cmd	**cmd)
{
    int i;
    t_cmd *new;

    i = -1;
    new = NULL;
    if (str == NULL)
    {
        rl_on_new_line();
        rl_replace_line("", 0);
        rl_redisplay();
        write(1, "exit\n", 5);
        exit(g_status_error);
    }
    else if (str[0] != '\0')
    {
        add_history(str);
        str[ft_strlen(str) + 1] = '\0';
        while (str[++i])
        {
            if (preparser(str, &i))
            {
                ft_putstr_fd(str, 2);
                ft_putstr_fd(" : invalid command\n", 2);
                return (0);
            }

        }
        if (postparser(str, new, cmd, our_env))
            return (ft_free_cmd(cmd, str));
        logic(cmd, our_env, env);
        ft_free_cmd(cmd, str);
    }
    else
        free(str);

    return (0);

}

void    ft_ctrl_c(int id)
{
    if (id == SIGINT)
    {
        rl_on_new_line();
        rl_redisplay();
        write(1, "  \n", 3);
        rl_on_new_line();
        rl_replace_line("", 0);
        rl_redisplay();
    }
}

void    ft_signal_init()
{
    signal(SIGINT, ft_ctrl_c);
    signal(SIGQUIT, SIG_IGN);
}

int    main(int argc, char **argv, char **env)
{
    t_cmd    *cmd;
    t_env    *our_env;

    (void ) argc;
    (void ) argv;
    if (ft_fill_env(env, &our_env))
        (ft_error("error_malloc"));
    while (1)
    {
        cmd = NULL;
        ft_signal_init();
        if (ft_minishell(&our_env, readline("minishell:> "), env, &cmd))
            return(1);
    }
    return (0);
}

/// кейсы 
// "|"
//  
// dawdw "|" daw
