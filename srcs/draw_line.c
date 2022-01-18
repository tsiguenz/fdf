/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 23:21:51 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/01/18 23:39:25 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
/*
void	draw_line(t_data *img, int x1, int y1, int x2, int y2)
{
		int	dx;
		int	dy;
		int	e;

		dx = x2 - x1;
		dy = y2 - y1;
		e = 0;
		while(x1 <= x2)
		{
			pixel_put(img, x1, y1, 0x00FFFFFF);
			e += dy;
			if ((e * 2) >= dx)
			{
				y1++;
				e -= dx;
			}
			x1++;
		}
}
*/

void	draw_line(t_data *img, int x1, int y1, int x2, int y2)
{
    int w;
    int h;
	int	dx1;
	int	dy1;
	int	dx2;
	int	dy2;
	int	longest;
	int	shortest;
	int	numerator;

	w = x2 - x1;
	h = y2 - y1;
	dx1 = 0;
	dy1 = 0;
	dx2 = 0;
	dy2 = 0;
    if (w < 0)
		dx1 = -1;
	else if (w>0)
		dx1 = 1;
    if (h<0)
		dy1 = -1;
	else if (h>0)
		dy1 = 1 ;
    if (w<0)
		dx2 = -1;
	else if (w>0)
		dx2 = 1 ;
    longest = abs(w);
    shortest = abs(h);
    if (!(longest>shortest))
	{
        longest = abs(h);
        shortest = abs(w);
        if (h<0)
			dy2 = -1;
		else if (h>0)
			dy2 = 1;
        dx2 = 0;            
    }
    numerator = longest >> 1;
    for (int i=0;i<=longest;i++)
	{
        pixel_put(img, x1,y1, 0x00FFFFFF);
        numerator += shortest;
        if (!(numerator<longest))
		{
            numerator -= longest;
            x1 += dx1;
            y1 += dy1;
        } else
		{
            x1 += dx2;
            y1 += dy2;
        }
    }
}
