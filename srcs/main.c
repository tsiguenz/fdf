/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:44:00 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/01/21 18:16:54 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(void)
{
	t_maps	map;

//	if (argc != 2)
//		return (errors(0));
	if (check_file("maps/42.fdf", &map) || init_map("maps/42.fdf", &map))
		return (0);
	ft_print_tab_two(map.tab, map.ymax, map.xmax);
	render_map(map);
	ft_destroy_tab_two(map.tab, map.ymax);
	return (0);
}
