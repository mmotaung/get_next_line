/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmotaung <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 07:12:28 by mmotaung          #+#    #+#             */
/*   Updated: 2019/06/29 09:06:30 by mmotaung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_newline(char **s, char **line, int fd, int bytes)
{
	char		*tmp;
	int			i;

	i = 0;
	while (s[fd][i] != '\n' && s[fd][i] != '\0')
		i++;
	if (s[fd][i] == '\n')
	{
		*line = ft_strsub(s[fd], 0, i);
		tmp = ft_strdup(s[fd] + i + 1);
		free(s[fd]);
		s[fd] = tmp;
		if (s[fd][0] == '\0')
			ft_strdel(&s[fd]);
	}
	else if (s[fd][i] == '\0')
	{
	if (bytes == BUFF_SIZE)
		return (get_next_line(fd, line));
	*line = ft_strdup(s[fd]);
	ft_strdel(&s[fd]);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char		*s[200];
	char			buff[BUFF_SIZE + 1];
	char			*tmp;
	int				bytes;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((bytes = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[bytes] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strnew(1);
		tmp = ft_strjoin(s[fd], buff);
		free(s[fd]);
		s[fd] = tmp;
		if (ft_strchr(buff, '\n'))
			break;
	}
	if (bytes < 0)
		return (-1);
	else if (bytes == 0 && (s[fd] == NULL || s[fd][0] == '\0'))
		return (0);
	return (ft_newline(s, line, fd, bytes));
}
