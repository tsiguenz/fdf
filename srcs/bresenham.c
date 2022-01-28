/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 18:38:41 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/01/28 12:52:02 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int    update_above(t_point2d *p0, t_point2d *pd, t_point2d *ps, int err)
{
    err += pd->y;
    p0->x += ps->x;
    return (err);
}

int    update_below(t_point2d *p0, t_point2d *pd, t_point2d *ps, int err)
{
    err += pd->x;
    p0->y += ps->y;
    return (err);
}

void		bresenham(t_data *mlx, t_point2d orig1, t_point2d orig2)
{
    t_point2d	pd;
    t_point2d	ps;
    int			err;
    int			err2;

    pd.x = ft_abs(orig2.x - orig1.x);
    pd.y = -ft_abs(orig2.y - orig1.y);
    ps.x = 1 - 2 * (orig1.x >= orig2.x);
    ps.y = 1 - 2 * (orig1.y >= orig2.y);
    err = pd.x + pd.y;
    while (1)
    {
        pixel_put(mlx, orig1.x + mlx->xorig, orig1.y + mlx->yorig, 0x00FFFFFF);
        err2 = 2 * err;
        if ((orig1.x == orig2.x && orig1.y == orig2.y) \
        || (orig1.x == orig2.x && err2 >= pd.y) \
		|| (err2 <= pd.x && orig1.y == orig2.y))
            break ;
        if (err2 >= pd.y)
            err = update_above(&orig1, &pd, &ps, err);
        if (err2 <= pd.x)
            err = update_below(&orig1, &pd, &ps, err);
    }
}
