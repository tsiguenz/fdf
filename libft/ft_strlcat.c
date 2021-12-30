/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debian <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 00:40:04 by debian            #+#    #+#             */
/*   Updated: 2021/11/24 18:17:58 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	att_len;

	i = ft_strlen(dst);
	j = 0;
	if (i < size)
		att_len = ft_strlen(src) + ft_strlen(dst);
	else
		att_len = ft_strlen(src) + size;
	while (src[j] && i < size - 1 && size > 0)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	if (size != 0 && i < size)
		dst[i] = '\0';
	return (att_len);
}
