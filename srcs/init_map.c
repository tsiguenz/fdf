/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 00:19:03 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/01/25 12:37:09 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	fill_table(int fd, t_maps *map)
{
	char	*line;
	char	**split_line;
	int		y;
	int		x;

	y = 0;
	map->tab = ft_tabnew_two(map->ymax, map->xmax);
	while (ft_gnl(fd, &line) && y < map->ymax)
	{
		x = 0;
		split_line = ft_split(line, ' ');
		free(line);
		if (!split_line)
			return (1);
		while (x < map->xmax)
		{
			map->tab[y][x] = ft_atoi(split_line[x]);
			free(split_line[x++]);
		}
		free(split_line[x]);
		free(split_line);
		y++;
	}
	return (0);
}

static void	fill_zstruct(t_maps *map)
{
	int	max;
	int	x;
	int	y;

	max = 0;
	y = 0;
	while (y < map->ymax)
	{
		x = 0;
		while (x < map->xmax)
		{
			if (ft_abs(map->tab[y][x]) > max)
				max = ft_abs(map->tab[y][x]);
			x++;
		}
		y++;
	}
	map->zmax = max;
}

int	init_map(char *filename, t_maps *map)
{
	int	fd;

	if (!filename || !map)
		return (1);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (errors(1));
	if (fill_table(fd, map))
		return (1);
	fill_zstruct(map);
	if (close(fd) == -1)
		return (errors(2));
	return (0);
}
