/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 16:28:51 by tsiguenz          #+#    #+#             */
/*   Updated: 2021/12/29 23:26:26 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, unsigned int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	ft_close(int keycode, t_vars *vars)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(1);
	}
	return (0);
}

int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	printf("button : %d, x : %d, y : %d\n", button, x, y);
	mlx_pixel_put(vars->mlx, vars->win, x, y, 0x00FFFFFF);
	return (0);
}
/*
int	main(void)
{
	t_vars 	vars;
	t_data	img;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 700, 700, "fdf");
//	img.img = mlx_new_image(vars.mlx, 500, 500);
//	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
//								&img.endian);
//	my_mlx_pixel_put(&img, 0, 0, 0x00FF0000);
//	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 100, 100);
	mlx_key_hook(vars.win, ft_close, &vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
*/
