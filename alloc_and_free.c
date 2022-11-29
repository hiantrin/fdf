/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_and_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiantrin <hiantrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 11:48:16 by hiantrin          #+#    #+#             */
/*   Updated: 2019/12/08 14:11:30 by hiantrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pixel		**alloc_struct(int fd, int i)
{
	t_pixel	**pixel;
	char	**str;
	char	*line;
	int		j;
	int		k;

	j = 0;
	pixel = (t_pixel **)malloc(sizeof(t_pixel *) * i + 1);
	pixel[i] = NULL;
	i = 0;
	while ((k = get_next_line(fd, &line)) == 1)
	{
		str = ft_strsplit(line, ' ');
		pixel[j] = (t_pixel *)malloc(sizeof(t_pixel) * len_tab(str));
		while (str[i])
		{
			pixel[j][i] = stock_pixel(str[i], i, j);
			i++;
		}
		i = 0;
		j++;
		free_2d(str);
		free(line);
	}
	return (pixel);
}

t_pixel		stock_pixel(char *str, int i, int j)
{
	t_pixel pixel;

	pixel.x = i;
	pixel.y = j;
	pixel.z = ft_atoi(str);
	if (pixel.z > 0)
		pixel.color = 0xFF0001 * ft_atoi(str);
	else
		pixel.color = 0xFFFFFF;
	return (pixel);
}

int			len_tab(char **str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void		free_2d(char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
