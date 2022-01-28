/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:30:39 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/01/28 18:36:32 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

float	deg_to_rad(int deg)
{
	return ((float)(deg * PI / 180));
}

t_point3d	fill_point3d(int x, int y, int z)
{
	t_point3d	p;

	p.x = x;
	p.y = y;
	p.z = z;
	return (p);
}

t_point2d	fill_point2d(int x, int y)
{
	t_point2d	p;

	p.x = x;
	p.y = y;
	return (p);
}

