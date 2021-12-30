/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 23:22:06 by tsiguenz          #+#    #+#             */
/*   Updated: 2021/12/30 14:42:02 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	**parse(char *file)
{
	int fd;
	int	**map;

	fd = open(file, O_RDONLY);
//	printf("gnl %s", get_next_line(fd));
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
	printf("%d\n", ft_strlen("test"));
//	print_map(map);
	return (0);
}
