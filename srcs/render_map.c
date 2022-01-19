/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:57:19 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/01/19 12:21:01 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	pixel_put(t_data *data, int x, int y, unsigned int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	mlx_close_esc(int keycode, t_vars *vars)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	(void) button;
	mlx_pixel_put(vars->mlx, vars->win, x, y, 0x00FFFFFF);
	return (0);
}

void	isometric(t_maps map, t_data *img)
{
	(void) map;
	(void) img;
	int	x, y, l;
	float u, v;	
	l = 10;
	x = 0;
	y = 0;
	(void) l;
	while (y < map.ymax)
	{
		while (x < map.xmax)
		{
			u = ((x - map.tab[y][x]) * cos(0.5)) * l;
			v = (y + (x + map.tab[y][x]) * sin(0.5)) * l;
		//	u = x*cos(0) + y*cos(0+2.1) + map.tab[y][x]*cos(0-2.1);
		//	v = x*sin(0) + y*sin(0+2.1) + map.tab[y][x]*sin(0-2.1);
			printf("u = %f, v = %f\n", u, v);
			pixel_put(img, u, v, 0x00FFFFFF);
			x++;
		}
		y++;
		x = 0;
	}
}

int	render_map(t_maps map)
{

	t_vars 	vars;
	t_data	img;

	(void) map;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1000, 1000, "fdf");
	img.img = mlx_new_image(vars.mlx, 800, 800);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	mlx_key_hook(vars.win, mlx_close_esc, &vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
//	draw_line(&img, 10, 10, 150, 150);
//	draw_line(&img, 100, 200, 30, 10);
//	draw_line(&img, 10, 200, 200, 10);
	isometric(map, &img);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 100, 100);
	mlx_loop(vars.mlx);
	return(0);
}
