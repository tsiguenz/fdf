/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:57:19 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/01/19 17:47:56 by tsiguenz         ###   ########.fr       */
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

void	isometric(t_maps map, t_data *img)
{
	(void) map;
	(void) img;
	int	i, j, l;
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	int	org = 200;
	l = 20;
	i = 0;
	j = 0;
	(void) l;
	(void) x2;
	(void) y2;
	while (j < map.ymax)
	{
		while (i < map.xmax)
		{
		//	x1 = ((i - map.tab[j][i]) / sqrt(2)) * l;
		//	y1 = ((i + 2 * j + map.tab[j][i]) / sqrt(6)) * l;
			x1 = (i - j) * l / 2;
			y1 = (i + j) * l / 2;
			printf("u = %d, v = %d\n", x1, y1);
			pixel_put(img, org + x1, org + y1, 0x00FFFFFF);
		//	draw_line(img, org + x1, org + y1, org + x2, org + y2);
			x2 = x1;
			y2 = y1;
			i++;
		}
		j++;
		i = 0;
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
	isometric(map, &img);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 100, 100);
	mlx_loop(vars.mlx);
	return(0);
}
