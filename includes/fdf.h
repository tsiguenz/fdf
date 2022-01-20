/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 22:20:22 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/01/20 17:34:56 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include <math.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

# define ESC 65307

typedef struct s_maps {
	int	**tab;
	int	ymax;
	int	xmax;
	int	zoom;
}				t_maps;

typedef struct s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	print_tab(int **tab, int ymax, int xmax);
int		init_map(char *filename, t_maps *map);
int		check_file(char *filename, t_maps *map);
int		errors(int err_code);
int		render_map(t_maps map);
int		mlx_close_esc(int keycode, t_vars *vars);
void	pixel_put(t_data *data, int x, int y, unsigned int color);
void	draw_line(t_maps map, t_data *img);
#endif
