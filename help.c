/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiantrin <hiantrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 23:37:42 by hiantrin          #+#    #+#             */
/*   Updated: 2019/12/08 15:03:12 by helalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_pixel(t_p *win, int per)
{
	int		i;
	int		j;
	t_p		*piw;

	piw = (t_p *)malloc(sizeof(t_p));
	chtet_lpixel(piw, win);
	i = 0;
	if (per == 0)
	{
		while (piw->pixel[i])
		{
			j = 0;
			while (j < piw->number)
			{
				iso(&piw->pixel[i][j].x,
				&piw->pixel[i][j].y, piw->pixel[i][j].z);
				j++;
			}
			i++;
		}
	}
	ft_dakchi_3bar(piw);
	free_p(piw);
}

void	chtet_lpixel(t_p *piw, t_p *win)
{
	int i;
	int j;

	piw->mlx_ptr = win->mlx_ptr;
	piw->win_ptr = win->win_ptr;
	piw->pixel = copy_pixel(win->str, win->i);
	piw->number = win->number;
	piw->str = ft_strdup(win->str);
	ft_k7ez(piw->pixel, piw->number);
	i = 0;
	while (piw->pixel[i])
	{
		j = 0;
		while (j < piw->number)
		{
			piw->pixel[i][j].x *= piw->pixel[i][j].cen;
			piw->pixel[i][j].y *= piw->pixel[i][j].den;
			piw->pixel[i][j].z *= 3;
			j++;
		}
		i++;
	}
}

void	ft_dakchi_3bar(t_p *piw)
{
	int i;
	int j;

	i = 0;
	while (piw->pixel[i])
	{
		j = 0;
		while (j < piw->number)
		{
			piw->pixel[i][j].x += W / 4;
			piw->pixel[i][j].y += H / 4;
			j++;
		}
		i++;
	}
	draw_x(piw->pixel, piw->number, piw->mlx_ptr, piw->win_ptr);
	draw_y(piw->pixel, piw->number, piw->mlx_ptr, piw->win_ptr);
}

void	free_p(t_p *piw)
{
	int i;

	i = 0;
	while (piw->pixel[i])
	{
		free(piw->pixel[i]);
		i++;
	}
	free(piw->pixel);
	free(piw->str);
	free(piw);
}
