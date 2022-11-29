/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiantrin <hiantrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 22:32:33 by helalam           #+#    #+#             */
/*   Updated: 2019/12/08 14:58:08 by helalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		print_error(int fd, int argc)
{
	int i;

	if (argc != 2)
	{
		ft_putendl("Usage : ./fdf <filename> [ case_size z_size ]");
		close(fd);
		exit(0);
	}
	if (fd == -1)
	{
		ft_putendl("Error opening the file");
		exit(0);
	}
	i = check_nbr_of_char(fd);
	if (i == 0)
	{
		ft_putendl("file invalid");
		close(fd);
		exit(0);
	}
	else
		return (i);
}

int		check_nbr_of_char(int fd)
{
	char	**m;
	int		len;
	int		len_old;
	char	*line;

	len = 0;
	len_old = 0;
	while (get_next_line(fd, &line) == 1)
	{
		m = ft_strsplit(line, ' ');
		if (m[0] == NULL)
			return (0);
		len = len_tab(m);
		if (len_old == 0)
			len_old = len;
		if (len_old != len)
		{
			free(line);
			free_2d(m);
			return (0);
		}
		free(line);
		free_2d(m);
	}
	return (len_old);
}
