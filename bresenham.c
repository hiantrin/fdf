/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiantrin <hiantrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 11:40:00 by hiantrin          #+#    #+#             */
/*   Updated: 2019/12/08 15:07:01 by helalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw_y(t_pixel **data, int max_x, void *mlx_ptr, void *win_ptr)
{
	int		i;
	int		j;

	j = 0;
	while (j < max_x)
	{
		i = 0;
		while (data[i])
		{
			if (data[i + 1] != NULL)
				line(data[i][j], data[i + 1][j], mlx_ptr, win_ptr);
			i++;
		}
		j++;
	}
}

void		draw_x(t_pixel **data, int max_x, void *mlx_ptr, void *win_ptr)
{
	int		i;
	int		j;

	i = 0;
	while (data[i])
	{
		j = 0;
		while (j < max_x - 1)
		{
			line(data[i][j], data[i][j + 1], mlx_ptr, win_ptr);
			j++;
		}
		i++;
	}
}

void		line(t_pixel pixel1, t_pixel pixel2, void *mlx_ptr, void *win_ptr)
{
	t_step		*s;
	float		max;
	float		i;

	i = 0;
	s = (t_step *)malloc(sizeof(t_step));
	max = calcul_step(pixel1, pixel2, s);
	while (i < max)
	{
		if (pixel1.color != 0xFFFFFF)
			mlx_pixel_put(mlx_ptr, win_ptr, s->x, s->y, pixel1.color);
		else if (pixel2.color != 0xFFFFFF)
			mlx_pixel_put(mlx_ptr, win_ptr, s->x, s->y, pixel2.color);
		else
			mlx_pixel_put(mlx_ptr, win_ptr, s->x, s->y, 0xFFFFFF);
		s->x = s->x + s->stepx;
		s->y = s->y + s->stepy;
		i++;
	}
	free(s);
}

float		calcul_step(t_pixel pixel1, t_pixel pixel2, t_step *s)
{
	float		max;

	s->dx = pixel2.x - pixel1.x;
	s->dy = pixel2.y - pixel1.y;
	s->stepx = s->dx > 0 ? 1 : -1;
	s->stepy = s->dy > 0 ? 1 : -1;
	s->dx = s->dx > 0 ? s->dx : s->dx * -1;
	s->dy = s->dy > 0 ? s->dy : s->dy * -1;
	max = s->dx > s->dy ? s->dx : s->dy;
	s->stepx = (s->dx / max) * s->stepx;
	s->stepy = (s->dy / max) * s->stepy;
	s->x = pixel1.x;
	s->y = pixel1.y;
	return (max);
}
