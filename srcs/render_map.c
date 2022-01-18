/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:57:19 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/01/18 22:07:08 by tsiguenz         ###   ########.fr       */
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

int	render_map(t_maps map)
{

	t_vars 	vars;
	t_data	img;

	(void) map;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 700, 700, "fdf");
	img.img = mlx_new_image(vars.mlx, 500, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	mlx_key_hook(vars.win, mlx_close_esc, &vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	draw_line(&img, 10, 10, 150, 150);
	draw_line(&img, 20, 20, 30, 100);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 100, 100);
	mlx_loop(vars.mlx);
	return(0);
}
