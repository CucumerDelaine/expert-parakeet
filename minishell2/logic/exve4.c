/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exve4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaine <cdelaine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 11:54:19 by cdelaine          #+#    #+#             */
/*   Updated: 2021/11/18 12:45:52 by cdelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	plus_shlvl(char **oenv)
{
	int	i;
	int	j;
	int	number;

	i = 0;
	j = 0;
	while (oenv[i])
	{
		if (!ft_strncmp(oenv[i], "SHLVL", 5))
		{
			while (oenv[i][j])
			{
				if (oenv[i][j] == '=')
					break ;
				j++;
			}
			break ;
		}
		i++;
	}
	number = ft_atoi(&(oenv[i][j + 1])) + 1;
	oenv[i] = ft_strjoin("SHLVL=", ft_itoa(number));
}

void	check_minishel(char *name, char **oenv, t_cmd *cmd)
{
	int	last;
	int	i;

	(void)cmd;
	i = 0;
	while (name[i])
	{
		if (name[i] == '/')
			last = i;
		i++;
	}
	if (!ft_strncmp(name + last + 1, "minishell", 9))
		plus_shlvl(oenv);
}
