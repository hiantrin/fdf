/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiantrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 22:41:44 by hiantrin          #+#    #+#             */
/*   Updated: 2019/06/23 13:09:30 by hiantrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	get_line(char **s, char **line)
{
	int		len;
	char	*tmp;

	len = 0;
	if (ft_strchr(*s, '\n'))
	{
		while ((*s)[len] != '\n')
			len++;
		*line = ft_strsub(*s, 0, len);
		tmp = ft_strdup((*s) + (len + 1));
		free(*s);
		*s = tmp;
		if ((*s)[0] == '\0')
			ft_strdel(s);
	}
	else
	{
		*line = ft_strdup(*s);
		ft_strdel(s);
	}
	return (1);
}

static int	error(char **s, char **line, int ret)
{
	if (ret < 0)
		return (-1);
	else if (ret == 0 && *s == NULL)
		return (0);
	else
		return (get_line(s, line));
}

int			get_next_line(const int fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	int			ret;
	static char	*s[FD_LIMIT];
	char		*tmp;

	if (fd < 0 || !line || fd > FD_LIMIT)
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (!s[fd])
			s[fd] = ft_strdup(buff);
		else
		{
			tmp = ft_strdup(s[fd]);
			free(s[fd]);
			s[fd] = ft_strjoin(tmp, buff);
			free(tmp);
		}
		if (ft_strchr(s[fd], '\n'))
			break ;
	}
	return (error(&s[fd], line, ret));
}
