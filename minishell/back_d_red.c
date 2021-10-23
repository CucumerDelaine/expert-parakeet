/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_d_red.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 12:19:00 by cdelaine          #+#    #+#             */
/*   Updated: 2021/10/23 12:19:02 by cdelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	strcount(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (cmd->red_words[i])
		i++;
	return (i);
}

char	**init_str(char **str2)
{
	int	i;

	i = 0;
	str2 = malloc(sizeof(char *) * 100);
	while (i < 100)
	{
		str2[i] = NULL;
		i++;
	}
	return (str2);
}

void	term_str(char **str2)
{
	int	i;

	i = 0;
	while (str2[i])
	{
		if (str2[i])
			free(str2[i]);
		i++;
	}
	free(str2);
}

void	print_and_term(char **str2)
{
	int	i;

	i = 0;
	while (str2[i])
		printf("%s\n", str2[i++]);
	term_str(str2);
}

void	back_d_red(t_cmd *cmd)
{
	char	*str;
	int		i;
	int		count;
	int		j;
	char	**str2;

	str2 = NULL;
	init_count(&i, &j);
	str2 = init_str(str2);
	count = strcount(cmd);
	while (i < count)
	{
		if (i < count)
			str = readline("> ");
		if (i < count)
		{
			if (!ft_strncmp_nr(str, cmd->red_words[i], ft_strlen(str)))
				i++;
			else if (i == count - 1 && !ft_strncmp_nr("cat", cmd->cmd, 3) \
			&& cmd->argum[0] == NULL)
				str2[j++] = ft_strdup(str);
		}
		free(str);
	}
	print_and_term(str2);
}
