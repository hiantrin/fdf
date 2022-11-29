/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiantrin <hiantrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:44:35 by hiantrin          #+#    #+#             */
/*   Updated: 2019/12/08 14:06:50 by hiantrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define W 1500
# define H 1000

# include "libft/libft.h"
# include "libft/get_next_line.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "mlx.h"
# include "math.h"

typedef struct	s_pixel
{
	int			x;
	int			y;
	int			z;
	int			color;
	int			cen;
	int			den;
}				t_pixel;

typedef	struct	s_p
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_pixel	**pixel;
	int		number;
	char	*str;
	int		i;
}				t_p;

typedef	struct	s_step
{
	float	stepx;
	float	stepy;
	int		dx;
	int		dy;
	float	x;
	float	y;
}				t_step;

void			beginning(t_pixel **pixel, int number, char *str, int x);
int				len_tab(char **str);
void			free_2d(char **str);
t_pixel			**alloc_struct(int fd, int i);
int				len_tab(char **str);
void			print_pixel(t_p *win, int per);
void			iso(int *x, int *y, int z);
void			line(t_pixel pixel1, t_pixel pixel2,
				void *mlx_ptr, void *win_ptr);
void			draw_x(t_pixel **data, int max_x, void *mlx_ptr, void *win_ptr);
void			draw_y(t_pixel **data, int max_x, void *mlx_ptr, void *win_ptr);
void			ft_k7ez(t_pixel **lop, int number);
int				key_select(int key, t_p *win);
t_pixel			**copy_pixel(char *str, int number);
int				print_error(int fd, int argc);
int				check_nbr_of_char(int fd);
void			free_p(t_p *piw);
float			calcul_step(t_pixel pixel1, t_pixel pixel2, t_step *s);
void			chtet_lpixel(t_p *piw, t_p *win);
void			ft_dakchi_3bar(t_p *piw);
t_pixel			stock_pixel(char *str, int i, int j);

#endif
