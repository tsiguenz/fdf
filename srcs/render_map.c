/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:57:19 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/01/21 18:16:38 by tsiguenz         ###   ########.fr       */
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

int	render_map(t_maps map)
{

	t_data	mlx;

	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, 1000, 1000, "fdf");
	mlx.img_ptr = mlx_new_image(mlx.mlx_ptr, 900, 900);
	mlx.addr = mlx_get_data_addr(mlx.img_ptr, &mlx.bits_per_pixel,
								&mlx.line_length, &mlx.endian);
	mlx.orig = 300;
	mlx.zoom = 40;
	mlx.zscale = 2;
	mlx_key_hook(mlx.win_ptr, mlx_close_esc, &mlx);
	draw_line(map, &mlx);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img_ptr, 50, 50);
	mlx_loop(mlx.mlx_ptr);
	return(0);
}
