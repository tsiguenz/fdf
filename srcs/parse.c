/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 23:22:06 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/01/05 19:49:58 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	print_map(char ***map, int len)
{
	int	x = 0;
	int	y = 0;

	while (y < len)
	{
		while (map[y][x])
		{
			printf("%s ", map[y][x]);
			x++;
		}
		x = 0;
		y++;
	}
}

char	***new_map(char *line, char ***map, int len)
{
	char	***new_map;

	new_map = ft_calloc(len + 1, sizeof(char ***));
	if (!new_map)
		return (0);
	if (map)
		new_map = map;
	new_map[len - 1] = ft_split(line, ' ');	
//	free(map);
	return (new_map);
}

char	***parse(char *file)
{
	int		len;
	int 	fd;
	char	***map;
	char	*get_line;

	len = 0;
	map = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	get_line = get_next_line(fd);
	while (get_line)
	{
		printf("len %d\n", len);
		map = new_map(get_line, map, len++);
		free(get_line);
		get_line = get_next_line(fd);
	}
	return (map);
}

int	main(int argc, char **argv)
{
	char	***map;

	if (argc != 2)
		return (0);
	map = parse(argv[1]);
	if (map == 0)
		return (0);
	print_map(map, 10);
	free(map);
	return (0);
}
