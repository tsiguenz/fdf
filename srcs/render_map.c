/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:57:19 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/01/25 12:46:14 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	pixel_put(t_data *data, int x, int y, unsigned int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static int	mlx_close_esc(int keycode, t_data *mlx)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		exit(0);
	}
	return (0);
}

void	camera_init(t_maps map, t_data *mlx)
{
	int	x;
	int	y;
	int	offsetx;
	int	offsety;

	x = map.xmax;
	y = map.ymax;
	mlx->win_len = 700;
	if (map.xmax != map.ymax)
		mlx->zoom = (mlx->win_len - 200) / map.xmax - map.ymax;
	else
		mlx->zoom = (mlx->win_len - 200) / map.xmax;
	offsetx = cos(deg_to_rad(30)) * x - sin(deg_to_rad(30)) * y;
	offsety = cos(deg_to_rad(30)) * y + sin(deg_to_rad(30)) * x;
	printf("x %d, y %d, zoom %d\n", offsetx, offsety ,mlx->zoom);
	offsetx *= mlx->zoom;
	offsety *= mlx->zoom;
	mlx->xorig = (mlx->win_len - offsetx) / 2;
	mlx->yorig = (mlx->win_len - offsety) / 2;
	printf("x %d, y %d, zoom %d %d\n", offsetx, offsety ,mlx->zoom, map.zmax);
	mlx->zscale = 1;
}

int	render_map(t_maps map)
{

	t_data	mlx;

	camera_init(map, &mlx);
	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, mlx.win_len, mlx.win_len, "fdf");
	mlx.img_ptr = mlx_new_image(mlx.mlx_ptr, mlx.win_len, mlx.win_len);
	mlx.addr = mlx_get_data_addr(mlx.img_ptr, &mlx.bits_per_pixel,
								&mlx.line_length, &mlx.endian);
	mlx_key_hook(mlx.win_ptr, mlx_close_esc, &mlx);
	draw_line(map, &mlx);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img_ptr, 0, 0);
	mlx_loop(mlx.mlx_ptr);
	return(0);
}
