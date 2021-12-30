/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debian <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 23:36:51 by debian            #+#    #+#             */
/*   Updated: 2021/11/29 21:45:21 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!*little)
		return ((char *) big);
	while (big[i] != 0 && i < len)
	{
		j = 0;
		while (big[i + j] && little[j] && big[i + j] == little[j]
			&& i + j < len)
		{
			if (little[j + 1] == 0)
				return ((char *)(big + i));
			j++;
		}
		i++;
	}
	return (0);
}
