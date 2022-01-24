/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:51:40 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/01/24 17:15:22 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	isometric(float *x, float *y, int z)
{
	int	angle;

	angle = 30;
	*x = *x * cos(deg_to_rad(angle)) - *y * sin(deg_to_rad(angle));
	*y = *y * cos(deg_to_rad(angle)) + *x * sin(deg_to_rad(angle)) - z;
}

static void	bresenham(t_data *mlx, float x1, float y1, float z1, float x2, float y2, float z2)
{
	float	x_step;
	float	y_step;
	int		max;

	(void) z1;
	(void) z2;
	x1 *= mlx->zoom;
	x2 *= mlx->zoom;
	y1 *= mlx->zoom;
	y2 *= mlx->zoom;
	isometric(&x1, &y1, z1 * mlx->zscale);
	isometric(&x2, &y2, z2 * mlx->zscale);
	x_step = x2 - x1;
	y_step = y2 - y1;
	max = ft_max(ft_abs(x_step), ft_abs(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(x1 - x2) || (int)(y1 - y2))
	{
		pixel_put(mlx, x1 + mlx->xorig, y1 + mlx->yorig, 0xFFFFFFFF);
		//printf("x1 = %f, y1 = %f\n", img->xorig + x1, img->yorig + y1);
		x1 += x_step;
		y1 += y_step;
	}
}

void	draw_line(t_maps map, t_data *img)
{
	int	x;
	int	y;

	y = 0;
	while (y < map.ymax)
	{
		x = 0;
		while (x < map.xmax)
		{
			if (x < map.xmax - 1)
				bresenham(img, x, y, map.tab[y][x], x + 1, y, map.tab[y][x + 1]);
			if (y < map.ymax - 1)
				bresenham(img, x, y, map.tab[y][x], x, y + 1, map.tab[y + 1][x]);
			x++;
		}
		y++;
	}
}
