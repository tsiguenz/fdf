/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 22:20:22 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/01/25 18:47:24 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"
# include <math.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

# define ESC 65307
# define PI 3.1415926535

typedef struct s_maps {
	int	**tab;
	int	ymax;
	int	xmax;
	int	zmax;
}				t_maps;

typedef struct s_data {
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		xorig;
	int		yorig;
	int		zoom;
	int		zscale;
	int		win_len;
}				t_data;

typedef struct 	s_point3d {
	int	x;
	int	y;
	int	z;
}				t_point3d;

typedef struct 	s_point2d {
	int	x;
	int	y;
}				t_point2d;

void		print_tab(int **tab, int ymax, int xmax);
int			init_map(char *filename, t_maps *map);
int			check_file(char *filename, t_maps *map);
int			errors(int err_code);
int			render_map(t_maps map);
void 		pixel_put(t_data *data, int x, int y, unsigned int color);
void		draw_line(t_maps map, t_data *mlx);
float		deg_to_rad(int deg);
t_point2d	isometric(t_point3d point, t_data *mlx);
void		bresenham(t_data *mlx, t_point2d orig1, t_point2d orig2);
#endif
