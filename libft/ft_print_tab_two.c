/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tab_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:54:58 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/01/25 11:10:07 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_tab_two(int **tab, int col, int line)
{
	int	x;
	int	y;

	y = 0;
	while (y < col)
	{
		x = 0;
		while (x < line)
		{
			if (tab[y][x] > 9 && x > 0)
				write(1, " ", 1);
			else if (x > 0)
				write(1, "  ", 2);
			ft_putnbr_fd(tab[y][x], 1);
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
}
