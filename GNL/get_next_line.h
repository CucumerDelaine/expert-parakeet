/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 15:26:13 by cdelaine          #+#    #+#             */
/*   Updated: 2021/05/12 15:26:15 by cdelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(const char *str);
void	*ft_memmove(void *destination, const void *source, size_t n);
char	*strjoin(char const *str1, char const *str2);
int		get_next_line(int fd, char **line);
char	*get(char *str);
char	*get2(char *str);
int		on_return(char *str);

#endif