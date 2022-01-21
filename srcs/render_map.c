/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:57:19 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/01/21 11:33:57 by tsiguenz         ###   ########.fr       */
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

//	x1 = ((i - j) * cos(0.523599)) * l;
//	y1 = (-map.tab[j][i] + (i + j) * sin(0.523599)) * l;
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
	img.orig = 400;
	mlx_key_hook(vars.win, mlx_close_esc, &vars);
	draw_line(map, &img);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 50, 50);
	mlx_loop(vars.mlx);
	return(0);
}
