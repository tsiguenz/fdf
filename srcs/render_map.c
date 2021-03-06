/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:57:19 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/02/07 14:51:22 by tsiguenz         ###   ########.fr       */
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
		mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
		mlx_destroy_display(mlx->mlx_ptr);
		ft_destroy_tab_two(mlx->map->tab, mlx->map->ymax);
		free(mlx->mlx_ptr);
		exit(0);
	}
	return (0);
}

int	render_map(t_maps *map)
{
	t_data	mlx;

	mlx.map = map;
	camera_init(&mlx);
	mlx.mlx_ptr = mlx_init();
	if (mlx.mlx_ptr == 0)
		return (1);
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, mlx.win_len, mlx.win_len, "fdf");
	if (mlx.win_ptr == 0)
		return (1);
	mlx.img_ptr = mlx_new_image(mlx.mlx_ptr, mlx.win_len, mlx.win_len);
	if (mlx.img_ptr == 0)
		return (1);
	mlx.addr = mlx_get_data_addr(mlx.img_ptr, &mlx.bits_per_pixel,
			&mlx.line_length, &mlx.endian);
	mlx_key_hook(mlx.win_ptr, mlx_close_esc, &mlx);
	draw_line(mlx.map, &mlx);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img_ptr, 0, 0);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
