/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 18:28:50 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/01/12 00:45:05 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	errors(int err_code)
{
	if (err_code == 0)
	{
		ft_putstr_fd("Bad number of arguments\n", 1);
		return (0);
	}
	else if (err_code == 1)
		ft_putstr_fd("Error while opening file\n", 1);
	else if (err_code == 2)
		ft_putstr_fd("Error while closing file\n", 1);
	else if (err_code == 3)
		ft_putstr_fd("Bad format file\n", 1);
	else if (err_code == 4)
		ft_putstr_fd("File is empty\n", 1);
	return (1);
}
