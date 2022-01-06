#include "../includes/fdf.h"

void	print_map(int **map, int ymax, int xmax)
{
	int	x = 0;
	int	y = 0;

	while (y < ymax)
	{
		while (x < xmax)
		{
			printf("%d ", map[y][x]);
			x++;
		}
		x = 0;
		y++;
	}
}

int	get_ymax(char *filename)
{
	int		fd;
	char	c;
	int		ymax;

	ymax = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (1);
	while (read(fd, &c, 1) == 1)
  		if (c == '\n')
			ymax++;
	return (ymax);
}

int	get_xmax(char **split_line)
{
	int	i;

	i = 0;
	while (split_line[i])
		i++;
	return (i);
}

int	**malloc_tab(int ymax, int xmax)
{
	int	i;
	int	**tab;

	i = 0;
	tab = ft_calloc(ymax, sizeof(int *));
	if (tab == NULL)
		return (NULL);
	while (i < xmax)
	{
		tab[ymax - 1] = ft_calloc(xmax, sizeof(int));
		if (tab == NULL)
			return (NULL);
		i++;
	}
	return (tab);
}

void	init(char *file_name, t_maps *map)
{
	int		fd;
	char	*line;
	char 	**split_line;
	int		y;
	int		x;

	y = 0;
	x = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return ;
	line = get_next_line(fd);
	split_line = ft_split(line, ' ');
	map->xmax = get_xmax(split_line);
	map->ymax = get_ymax(file_name);
	map->tab = malloc_tab(map->ymax, map->xmax);
	while (y < map->ymax)
	{
		while (x < map->xmax)
		{
			map->tab[y][x] = ft_atoi(split_line[x]);
			x++;
		}
		split_line = ft_split(get_next_line(fd), ' ');
		x = 0;
		y++;
	}
	printf("%s" ,line);
	free(line);
//	destroy(split_line);
}


int	main(void)
{
	t_maps map;

	init("maps/42.fdf", &map);
//	print_map(map.tab, map.ymax, map.xmax);
	(void) map;
//	destroy_tab(map);
	return (0);
}
