/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 23:22:06 by tsiguenz          #+#    #+#             */
/*   Updated: 2021/12/30 16:24:38 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	**parse(char *file)
{
	int 	fd;
	int		**map;
	char	*get_line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	get_line = get_next_line(fd);
	return (map);
}

int	*map_split(char *line, int *map)
{
	return (map);
}

void	print_map(int **map)
{
	int	x = 0;
	int	y = 0;

	while (map[x][y] != -1)
	{
		while (map[x][y] != -1)
		{
			printf("%d ", map[x][y]);
			x++;
		}
		printf("\n");
		x = 0;
		y++;
	}
}

int	main(int argc, char **argv)
{
	int	**map;

	if (argc != 2)
		return (0);
	map = parse(argv[1]);
//	if (map == 0)
//		return (0);
	printf("%d\n", ft_atoi(" 1 2"));
//	print_map(map);
	return (0);
}
