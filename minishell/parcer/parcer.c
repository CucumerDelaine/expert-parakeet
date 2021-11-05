#include "../minishell.h"

char	*ft_parcer(char **str, t_env **our_env, t_iter *iter)
{
	int		i;
	char	*res;

	i = 0;
	res = NULL;
	while ((*str) != NULL && (*str)[i])
	{
		if ((*str)[i] == '\'')
			(*str) = ft_quotes_one((*str), &i);
		else if ((*str)[i] == '$')
			(*str) = ft_dollar((*str), &i, our_env);
		else if ((*str)[i] == '\"')
			(*str) = ft_quotes_two((*str), &i, our_env);
		if (((*str) != NULL && (ft_is_space((*str)[i + 1]) || \
		(*str)[i + 1] == '\0') && iter->full == 0) ||
		((*str) != NULL && (only_service((*str)[i + 1])) && iter->full == 0))
		{
			res = ft_substr((*str), 0, i + 1);
			iter->full = 1;
		}
		if ((*str) == NULL)
			return (NULL);
		i++;
	}
	return (res);
}

int	postparser(char *str, t_cmd  *new, t_cmd **cmd, t_env **our_env)
{
	int		i;
    int		j;
    int		red;
    char	*res;
    t_iter	*iter;
	
    ft_init_iter(&iter);
    i = 0;
    red = 0;
    str = ft_strtrim(str, "\t\n\v\f\r ");
   	if (str[i] == '\0')
        return (1);
	res = ft_parcer(&str, our_env, iter);
	if (str == NULL)
		return (ft_freez(iter));
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
                iter->word = ft_substr(str, j, i - j);
                new = ft_lstnew_cmd(iter->word);
				free(iter->word);
            	iter->word = NULL;
            }
            else
            {
                new = ft_lstnew_cmd(res);
                i = ft_strlen(res);
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
                iter->flags = ft_substr(str, j, i - j); // добавление нескольких флагов
                ft_lstadd_flags(&new, iter->flags);
                free(iter->flags);
                iter->flags = NULL;
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
                iter->argum = ft_substr(str, j, i - j);
                ft_lstadd_argum(&new, iter->argum);
                free(iter->argum);
                iter->argum = NULL;
                while (ft_is_space(str[i]) && str[i] != '\0')
                    i++;
            }
		}
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
    return (0);
}