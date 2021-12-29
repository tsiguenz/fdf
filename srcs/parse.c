/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 23:22:06 by tsiguenz          #+#    #+#             */
/*   Updated: 2021/12/29 23:49:30 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	**parse(char *file)
{
	int fd;
	int	**map;

	fd = open("maps/42.fdf", O_RDONLY);
	printf("gnl %s", get_next_line(fd));
	return (map);
}

int	main(int argc, char **argv)
{
	int	**map;
	int	x = 0;
	int	y = 0;

	if (argc != 2)
		return (0);
	map = parse(argv[1]);
int	map1[5][5] =   {{0, 0, 0, -1},
					{0, 2, 6, -1},
					{0, 4, 0, -1},
					{0, 2, 6, -1},
					{-1,-1,-1,-1}};
	while (map1[x][y] != -1)
	{
		while (map1[x][y] != -1)
		{
			printf("%d ", map1[x][y]);
			x++;
		}
		printf("\n");
		x = 0;
		y++;
	}
	return (0);
}
