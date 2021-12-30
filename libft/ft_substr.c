/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 19:10:15 by tsiguenz          #+#    #+#             */
/*   Updated: 2021/11/29 22:17:15 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*dest;

	i = 0;
	if (start > (size_t) ft_strlen(s))
		return (ft_strdup(""));
	dest = ft_calloc((len + 1), sizeof(char));
	if (dest == 0)
		return (0);
	while (s[start] && i < len)
	{
		dest[i] = s[start];
		i++;
		start++;
	}
	return (dest);
}
