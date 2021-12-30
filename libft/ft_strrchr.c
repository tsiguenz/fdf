/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debian <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 01:34:51 by debian            #+#    #+#             */
/*   Updated: 2021/11/30 20:58:13 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p_s;
	int		len;

	len = ft_strlen(s);
	p_s = (char *) s;
	if (p_s[len] == (unsigned char) c)
		return (&p_s[len]);
	while (len >= 0)
	{
		if (p_s[len] == (unsigned char) c)
			return (&p_s[len]);
		len--;
	}
	return (0);
}
