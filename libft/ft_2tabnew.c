/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2tabnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 01:32:06 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/01/09 17:46:04 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	**ft_2tabnew(int col, int line)
{
	int	i;
	int	**tab;

	i = 0;
	if (!col || !line)
		return (0);
	tab = malloc(col * sizeof(int *));
	if (!tab)
		return (0);
	while (i < col)
	{
		tab[i] = malloc(line * sizeof(int));
		if (!tab)
			return (0);
		i++;
	}
	return (tab);
}

