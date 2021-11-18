/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaine <cdelaine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:43:45 by cdelaine          #+#    #+#             */
/*   Updated: 2021/11/18 12:47:33 by cdelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit (1);
}

int	only_service(char s)
{
	if (s == '>' || s == '<' || s == '|')
		return (1);
	return (0);
}

int	service_char(char s)
{
	if (s == '>' || s == '<' || s == '|' || s == '\0' || ft_is_space(s))
		return (1);
	return (0);
}

int	ft_strncmp_nr(const char *s1, const char *s2, int n)
{
	char	*tmp1;
	char	*tmp2;
	int		i;

	i = 0;
	tmp1 = (char *)s1;
	tmp2 = (char *)s2;
	if (n == 0)
		return (1);
	while (i < n)
	{
		if (tmp1[i] != tmp2[i] && tmp1[i] - tmp2[i] != 32
			&& tmp1[i] - tmp2[i] != -32)
			return (tmp1[i] - tmp2[i]);
		if (tmp1[i] == 0 && tmp2[i] == 0)
			return (0);
		i++;
	}
	return (0);
}

int	ft_check_only_pipe(char *str)
{
	int	i;

	i = 0;
	while (ft_is_space(str[i]))
		i++;
	if (str[i] == '|')
		return (1);
	return (0);
}
