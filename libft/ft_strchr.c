/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 09:04:34 by tsiguenz          #+#    #+#             */
/*   Updated: 2021/11/30 20:57:39 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (s[i] == (unsigned char) c)
		return ((char *)s);
	while (s[i])
	{
		if ((char)s[i] == (unsigned char) c)
			return ((char *)(s + i));
		i++;
	}
	if ((char)s[i] == (unsigned char) c)
		return ((char *)(s + i));
	return (0);
}
