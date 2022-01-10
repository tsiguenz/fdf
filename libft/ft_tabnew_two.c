/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabnew_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 01:32:06 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/01/10 14:31:25 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	**ft_tabnew_two(int col, int line)
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
