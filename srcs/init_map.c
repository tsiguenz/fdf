/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 00:19:03 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/01/10 17:09:58 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	gnl(int fd, char **dest)
{
	*dest = get_next_line(fd);
	if (!*dest)
		return (0);
	return (1);
}

static int	get_max(t_maps *map, char *filename)
{
	int		i;
	int		fd;
	char	*line;

	i = 1;
	map->ymax = 0;
	map->xmax = 1;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (1);
	while (gnl(fd, &line))
	{
		while (line[i])
		{
			if (line[i] != ' ' && line[i - 1] == ' ')
				map->xmax++;
			i++;
		}
		free(line);
		map->ymax++;
	}
	if (close(fd) == -1)
		return (1);
	return (0);
}

static void	fill_table(char *filename, t_maps *map)
{
	int		fd;
	char	*line;
	char	**split_line;
	int		y;
	int		x;

	y = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1 || get_max(map, filename))
		return ;
	map->tab = ft_tabnew_two(map->ymax, map->xmax);
	while (gnl(fd, &line) && y < map->ymax)
	{
		x = 0;
		split_line = ft_split(line, ' ');
		free(line);
		while (x < map->xmax)
		{
			map->tab[y][x] = ft_atoi(split_line[x]);
			free(split_line[x++]);
		}
		free(split_line[x]);
		free(split_line);
		y++;
	}
}

int	init_map(char *filename, t_maps *map)
{
	if (!filename && !map)
		return (1);
	fill_table(filename, map);
	return (0);
}
