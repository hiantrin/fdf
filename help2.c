/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiantrin <hiantrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 11:45:55 by hiantrin          #+#    #+#             */
/*   Updated: 2019/12/08 15:00:49 by helalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_k7ez(t_pixel **lop, int number)
{
	int		max;
	int		min;
	int		i;
	int		j;

	max = 1;
	min = 1;
	i = 0;
	while (lop[i] != NULL)
		i++;
	while (max * i < H / 2)
		max++;
	while (min * number < W / 2)
		min++;
	i = -1;
	while (lop[++i])
	{
		j = 0;
		while (j < number)
		{
			lop[i][j].cen = min;
			lop[i][j].den = max;
			j++;
		}
	}
}

void		iso(int *x, int *y, int z)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}

t_pixel		**copy_pixel(char *str, int number)
{
	t_pixel **pixel;
	int		fd;

	fd = open(str, O_RDONLY);
	pixel = alloc_struct(fd, number);
	close(fd);
	return (pixel);
}
