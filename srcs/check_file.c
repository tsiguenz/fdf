/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 17:12:57 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/01/12 00:39:53 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	get_xmax(char *line)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	if (!line)
		return (0);
	while (line[i])
	{
		if (!ft_isdigit(line[i]) && line[i] != ' ' && line[i] != '\n')
			return (0);
		if (ft_isdigit(line[i]) && line[i + 1] == ' ')
			ret++;
		i++;
	}
	if (line[i - 2] != ' ')
		ret++;
	if (ret == -1)
		return (0);
	return (ret);
}

int	check_file(char *filename, t_maps map)
{
	int		tmp;
	int		fd;
	char	*line;

	(void) map;
	tmp = -1;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (errors(1));
	while (ft_gnl(fd, &line))
	{
		if (tmp != -1 && (tmp != get_xmax(line) || get_xmax(line) == 0))
		{
			free(line);
			if (close(fd) == -1)
				return (errors(2));
			return (errors(3));
		}
		tmp = get_xmax(line);
		free(line);
	}
	if (close(fd) == -1)
		return (errors(2));
	if (tmp == -1)
		return (errors(4));
	return (0);
}
