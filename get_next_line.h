/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmotaung <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 07:30:03 by mmotaung          #+#    #+#             */
/*   Updated: 2019/06/29 08:56:30 by mmotaung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 100

# include "fcntl.h"
# include "unistd.h"
# include "stdlib.h"
# include "libft/libft.h"

int		ft_newline(char **s, char **line, int fd, int bytes);
int		get_next_line(const int fd, char **line);

#endif
