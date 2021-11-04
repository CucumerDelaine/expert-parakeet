#include "../minishell.h"

int    postparser(char *str, t_cmd  *new, t_cmd **cmd, t_env **our_env)
{
    char *word;
    char *argum;
    char *flags;
    int red;
    char *res;
    t_iter *iter;
    ft_init_iter(&iter);
    int i;
    int j;

    i = 0;
    red = 0;
    word = NULL;
    argum = NULL;
    flags = NULL;
	res = NULL;
    str = ft_strtrim(str, "\t\n\v\f\r ");
    if (str[i] == '\0')
        return (1);
    // printf("str = |%s|\n", str);
    while (str[i])
    {
        if (str[i] == '\'')
            str = ft_quotes_one(str, &i);
        else if (str[i] == '$')
            str = ft_dollar(str, &i, our_env);
        else if (str[i] == '\"')
            str = ft_quotes_two(str, &i, our_env);
       	if (str != NULL && (ft_is_space(str[i + 1]) || str[i + 1] == '\0') && iter->full == 0)
        {
            res = ft_substr(str, 0, i + 1);
			if (ft_strchr(res, '\'') || ft_strchr(res, '\"'))
			{
				if (ft_strchr(res, '\''))
				{
					iter->j = ft_strchr_n(res, '\'');
					res = ft_quotes_one_two(res, &iter->j);
				}
				if (ft_strchr(res, '\"'))
				{
					iter->j = ft_strchr_n(res, '\"');
					res = ft_quotes_two_two(res, &iter->j, our_env);
				}
			}
            else if (ft_strchr(res, '<'))
                res = ft_substr(res, 0, ft_strchr_n(res, '<'));
            else if (ft_strchr(res, '>'))
                res = ft_substr(res, 0, ft_strchr_n(res, '>'));
            else if (ft_strchr(res, '|'))
                res = ft_substr(res, 0, ft_strchr_n(res, '|'));
            iter->full = 1;
            iter->i = i + 1;
		}	
        i++;
        if (str == NULL)
		{
			free(iter);
            return (1);
		}
	}
	if (res)
    	i = ft_strlen(res) - 1;
    while (str[i] != '\0')
    {
        while (ft_is_space(str[i]))
            i++;
        if (!service_char(str[i])) //команда
        {
            j = i;
            if (str[i] == '\'' && (str[i + 1] == '|' || str[i + 1] == '<' || str[i + 1] == '>'))
                str = ft_quotes_one_two(str, &i);
            else if (str[i] == '\"' && (str[i + 1] == '|' || str[i + 1] == '<' || str[i + 1] == '>'))
                str = ft_quotes_two_two(str, &i, our_env);
            while (!service_char(str[i]))
                i++;
            if (res == NULL || ft_strlen(res) == 0)
            {
                word = ft_substr(str, j, i - j);
                new = ft_lstnew_cmd(word);
				free(word);
            	word = NULL;
            }
            else
            {
                new = ft_lstnew_cmd(res);
                i = ft_strlen(res) + 1;
				free (res);
				res = NULL;
            }
            while (ft_is_space(str[i]) && str[i] != '\0')
                i++;
            while (str[i] == '-' && !service_char(str[i + 1])) // флаги
            {
                j = i;
                while (!service_char(str[i]))
                    i++;
                flags = ft_substr(str, j, i - j); // добавление нескольких флагов
                ft_lstadd_flags(&new, flags);
                free(flags);
                flags = NULL;
                while (ft_is_space(str[i]) && str[i] != '\0')
                    i++;
            }
            while (!service_char(str[i])) // аргументы
            {
                j = i;
                if (str[i] == '\'' && (str[i + 1] == '|' || str[i + 1] == '<' || str[i + 1] == '>'))
                    str = ft_quotes_one_two(str, &i);
                else if (str[i] == '\"' && (str[i + 1] == '|' || str[i + 1] == '<' || str[i + 1] == '>'))
                    str = ft_quotes_two_two(str, &i, our_env);
                while (!service_char(str[i]))
                    i++;
                argum = ft_substr(str, j, i - j);
                ft_lstadd_argum(&new, argum);
                free(argum);
                argum = NULL;
                while (ft_is_space(str[i]) && str[i] != '\0')
                    i++;
            }
        }
        // TODO тут утечка у str
        else if (str[i] == '|')
        {
            i++;
            while (ft_is_space(str[i]) && str[i] != '\0')
                i++;
            ft_lstadd_back_cmd(cmd, new);
            new = NULL;
            red = 0;
        }
        else if ((str[i] == '>' || str[i] == '<'))
        {
            if (new == NULL)
                new = ft_lstnew_cmd(NULL);
            ft_redir(&new, str, &i, &red);
        }
        if (str[i] == '\0')
        {
            ft_lstadd_back_cmd(cmd, new);
			free(str);
			str = NULL;
            new = NULL;
			free(iter);
			return(0);
        }
    }
    return (0);
}