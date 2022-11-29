/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiantrin <hiantrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:44:58 by hiantrin          #+#    #+#             */
/*   Updated: 2019/12/08 20:17:43 by hiantrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	t_pixel	**pixel;
	int		number;
	char	*str;

	fd = open(argv[1], O_RDONLY);
	number = print_error(fd, argc);
	close(fd);
	argc = 0;
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		argc++;
		free(line);
	}
	close(fd);
	str = ft_strdup(argv[1]);
	fd = open(str, O_RDONLY);
	pixel = alloc_struct(fd, argc);
	close(fd);
	beginning(pixel, number, str, argc);
	return (0);
}

int		key_select(int key, t_p *win)
{
	if (key == 53)
	{
		free_p(win);
		exit(0);
	}
	if (key == 35)
	{
		mlx_clear_window(win->mlx_ptr, win->win_ptr);
		print_pixel(win, 1);
	}
	if (key == 34)
	{
		mlx_clear_window(win->mlx_ptr, win->win_ptr);
		print_pixel(win, 0);
	}
	return (0);
}

void	beginning(t_pixel **pixel, int number, char *str, int x)
{
	t_p		*win;

	win = (t_p *)malloc(sizeof(t_p));
	win->str = str;
	win->pixel = pixel;
	win->number = number;
	win->i = x;
	win->mlx_ptr = mlx_init();
	win->win_ptr = mlx_new_window(win->mlx_ptr, W, H, "FDF");
	print_pixel(win, 0);
	mlx_key_hook(win->win_ptr, key_select, win);
	mlx_loop(win->mlx_ptr);
}
