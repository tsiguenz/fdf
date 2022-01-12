/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:44:00 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/01/12 23:37:26 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	t_maps	map;

	if (argc != 2)
		return (errors(0));
	if (check_file(argv[1], &map) || init_map(argv[1], &map))
		return (0);
	ft_print_tab_two(map.tab, map.ymax, map.xmax);
	ft_destroy_tab_two(map.tab, map.ymax);
	return (0);
}
