/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 00:19:03 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/01/10 11:59:41 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	print_map(int **map, int ymax, int xmax)
{
	int	x = 0;
	int	y = 0;

	while (y < ymax)
	{
		while (x < xmax)
		{
			printf(" %d", map[y][x]);
			x++;
		}
		printf("\n");
		x = 0;
		y++;
	}
}

int	get_max(t_maps *map, char *filename)
{
	int		fd;
	char	c;

	map->ymax = 0;
	map->xmax = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (1);
	while (read(fd, &c, 1) == 1)
	{
  		if (c == '\n')
			map->ymax++;
		if (map->ymax == 0 && c != ' ')
			map->xmax++;
	}
	if (close(fd) == -1)
		return (1);
	return (0);
}

int	gnl(int fd, char **dest)
{
	*dest = get_next_line(fd);
	if (!*dest)
		return (0);
	return (1);
}

int	destroy_tab(int **tab, int col)
{
	int	i;

	i = 0;
	while (i < col)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (0);
}
void	fill_table(char *filename, t_maps *map)
{
	int		fd;
	char	*line;
	char 	**split_line;
	int		y;
	int		x;

	y = 0;
	x = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1 || get_max(map, filename))
		return ;
	map->tab = ft_2tabnew(map->ymax, map->xmax);
	while (gnl(fd, &line) && y < map->ymax)
	{
		split_line = ft_split(line, ' ');
		free(line);
		while (x < map->xmax)
		{
			map->tab[y][x] = ft_atoi(split_line[x]);
			free(split_line[x]);
			x++;
		}
		free(split_line[x]);
		free(split_line);
		x = 0;
		y++;
	}
}


int	main(void)
{
	t_maps map;
	fill_table("maps/test.fdf", &map);
	print_map(map.tab, map.ymax, map.xmax);
	(void) map;
	destroy_tab(map.tab, map.ymax);
	return (0);
}
