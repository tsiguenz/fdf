/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:51:40 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/02/07 11:44:10 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_point2d	isometric(t_point3d point, t_data *mlx)
{
	t_point2d	ret;

	point.x *= mlx->zoom;
	point.y *= mlx->zoom;
	point.z *= mlx->zscale;
	ret.x = (point.x - point.y) / sqrt(2);
	ret.y = (point.x - 2 * point.z + point.y) / sqrt(6);
	return (ret);
}

void	draw_line(t_maps map, t_data *mlx)
{
	int			x;
	int			y;
	t_point3d	p1;
	t_point3d	p2;

	y = 0;
	while (++y < map.ymax)
	{
		x = 0;
		while (x < map.xmax)
		{
			p1 = fill_point3d(x, y, map.tab[y][x]);
			if (x < map.xmax - 1)
			{
				p2 = fill_point3d(x + 1, y, map.tab[y][x + 1]);
				bresenham(mlx, isometric(p1, mlx), isometric(p2, mlx));
			}
			if (y < map.ymax - 1)
			{
				p2 = fill_point3d(x, y + 1, map.tab[y + 1][x]);
				bresenham(mlx, isometric(p1, mlx), isometric(p2, mlx));
			}
			x++;
		}
	}
}
