/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_tab_two.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:55:00 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/01/11 18:15:21 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_destroy_tab_two(int **tab, int col)
{
	int	i;

	i = 0;
	if (!*tab)
		return (1);
	while (i < col)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (0);
}
