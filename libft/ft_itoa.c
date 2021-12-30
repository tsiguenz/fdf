/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:01:35 by tsiguenz          #+#    #+#             */
/*   Updated: 2021/12/01 12:00:00 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strrev(char *str)
{
	int		i;
	int		j;
	char	tmp;

	i = 0;
	j = ft_strlen(str) - 1;
	tmp = 0;
	while (i <= j)
	{
		tmp = *(str + i);
		*(str + i) = *(str + j);
		*(str + j) = tmp;
		i++;
		j--;
	}
}

static int	len_itoa(int n)
{
	int	len;

	len = 1;
	if (n == -2147483648)
	{
		return (11);
	}
	if (n < 0)
	{
		len++;
		n = n * -1;
	}
	while (n > 9)
	{
		len++;
		n = n / 10;
	}
	return (len + 1);
}

static int	is_neg(int n)
{
	if (n == -2147483648)
		return (1);
	if (n < 0)
		return (-1);
	return (1);
}

char	*ft_itoa(int n)
{
	int		i;
	int		neg;
	char	*dest;

	i = 0;
	neg = is_neg(n);
	n = n * neg;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	dest = ft_calloc((len_itoa(n) + 1), sizeof(char));
	if (dest == 0)
		return (0);
	while (n > 9)
	{
		dest[i++] = (n % 10) + 48;
		n = (n - (n % 10)) / 10;
	}
	dest[i] = n + 48;
	if (neg == -1)
		dest[++i] = '-';
	ft_strrev(dest);
	return (dest);
}
