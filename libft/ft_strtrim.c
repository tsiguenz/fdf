/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 10:21:15 by tsiguenz          #+#    #+#             */
/*   Updated: 2021/11/30 17:43:40 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	all_set(const char *str, const char *set)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!is_set(str[i], set))
			return (0);
		i++;
	}
	return (1);
}

static int	len_lt(const char *s1, const char *set)
{
	int	i;

	i = 0;
	while (is_set(s1[i], set) == 1)
		i++;
	return (i);
}

static int	len_rt(const char *s1, const char *set)
{
	int	i;
	int	j;

	i = ft_strlen(s1) - 1;
	j = 0;
	while (i >= 0 && is_set(s1[i], set))
	{
		i--;
		j++;
	}
	return (j);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	int		i;
	int		j;
	int		len_dest;
	char	*dest;

	i = len_lt(s1, set);
	j = 0;
	len_dest = ft_strlen(s1) - (i + len_rt(s1, set)) + 1;
	if (all_set(s1, set))
		return (ft_strdup(""));
	if (!set)
		return (ft_strdup(s1));
	dest = ft_calloc(len_dest, sizeof(char));
	if (dest == 0)
		return (0);
	while (i < ft_strlen(s1) - len_rt(s1, set))
	{
		dest[j] = s1[i];
		i++;
		j++;
	}
	return (dest);
}
