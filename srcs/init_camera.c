/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:34:39 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/02/07 15:42:36 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	init_orig(t_maps *map, t_data *mlx)
{
	t_point3d	x3;
	t_point3d	y3;
	t_point2d	x2;
	t_point2d	y2;

	x3 = fill_point3d(map->xmax / 2, map->ymax / 2, 0);
	y3 = fill_point3d(map->ymax / 2, map->ymax / 2, 0);
	x2 = isometric(x3, mlx);
	y2 = isometric(y3, mlx);
	mlx->xorig = mlx->win_len / 2 - x2.x;
	mlx->yorig = mlx->win_len / 2 - y2.y;
}

static void	init_values(t_point2d p, t_point2d *max, t_point2d *min, int i)
{
	if (i == 0)
	{
		if (p.x > max->x)
			max->x = p.x;
		if (p.x < min->x)
			min->x = p.x;
		if (p.y > max->y)
			max->y = p.y;
		if (p.y < min->y)
			min->y = p.y;
	}
	if (i == 1)
	{
		if (p.y > max->y)
			max->y = p.y;
		if (p.y < min->y)
			min->y = p.y;
	}
}

static int	init_zoom(t_maps *map, t_data *mlx)
{
	int			x;
	int			y;
	t_point2d	p;
	t_point2d	max;
	t_point2d	min;

	y = 0;
	mlx->zoom += 1;
	max = fill_point2d(0, 0);
	min = fill_point2d(0, 0);
	while (y < map->ymax && mlx->zoom)
	{
		x = 0;
		while (x < map->xmax)
		{
			p = isometric(fill_point3d(x, y, 0), mlx);
			init_values(p, &max, &min, 0);
			x++;
		}
		y++;
	}
	if (max.x - min.x > mlx->win_len - 50 || max.y - min.y > mlx->win_len - 50)
		return (mlx->zoom - 1);
	return (init_zoom(map, mlx));
}

static int	init_zscale(t_maps *map, t_data *mlx)
{
	int			x;
	int			y;
	t_point2d	p;
	t_point2d	max;
	t_point2d	min;

	y = 0;
	mlx->zscale += 1;
	max = fill_point2d(0, 0);
	min = fill_point2d(0, 0);
	while (y < map->ymax)
	{
		x = 0;
		while (x < map->xmax)
		{
			p = isometric(fill_point3d(x, y, map->tab[y][x]), mlx);
			init_values(p, &max, &min, 1);
			x++;
		}
		y++;
	}
	if (max.y - min.y > mlx->win_len - 50 || max.y - min.y < 50)
		return (mlx->zscale / 5);
	return (init_zscale(map, mlx));
}

void	camera_init(t_data *mlx)
{
	mlx->win_len = 700;
	mlx->zoom = 0;
	mlx->zscale = 0;
	mlx->zoom = init_zoom(mlx->map, mlx);
	if (mlx->map->zmax != 0)
		mlx->zscale = init_zscale(mlx->map, mlx);
	init_orig(mlx->map, mlx);
}
