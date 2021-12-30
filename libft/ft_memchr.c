/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:11:38 by tsiguenz          #+#    #+#             */
/*   Updated: 2021/11/30 21:32:04 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p_s;

	i = 0;
	p_s = (unsigned char *) s;
	if (n == 0)
		return (0);
	if (*p_s == (unsigned char) c)
		return (p_s);
	while (i < n)
	{
		if (p_s[i] == (unsigned char) c)
			return ((void *) p_s + i);
		i++;
	}
	return (0);
}
