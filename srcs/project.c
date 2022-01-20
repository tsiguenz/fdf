/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 23:21:51 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/01/20 19:31:41 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	ft_max(float a, float b)
{
	if (a < b)
		return (b);
	return (a);
}

static float ft_abs(float a)
{
	if (a < 0)
		return (-a);
	return (a);
}

void	isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.523599);
	*y = -z + (*x + *y) * sin(0.523599);
}
void	bresenham(t_data *img, float x1, float y1, int z1, float x2, float y2, int z2)
{
	float	x_step;
	float	y_step;
	int	max;

	(void) z1;
	(void) z2;
	x1 *= 10;
	x2 *= 10;
	y1 *= 10;
	y2 *= 10;
	x_step = x2 - x1;
	y_step = y2 - y1;
//	isometric(&x1, &y1, z1);
//	isometric(&x2, &y2, z2);
	max = ft_max(ft_abs(x_step), ft_abs(y_step));
	x_step /= max;
	y_step /= max;
	printf("x1 %d, x2%d, y1%d, y2%d, x_step %d, y_step %d\n", (int)x1, (int)x2, (int) y1, (int)y2, (int)x_step, (int)y_step);
	while (((int)x1 - (int)x2) || ((int)y1 - (int)y2))
	{
		pixel_put(img, x1, y1, 0x00FFFFFF);
		x1 += x_step;
		y1 += y_step;
	//printf("%d\n", (int)x1 - (int)y1);
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
