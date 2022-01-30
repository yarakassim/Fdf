/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykassim- <ykassim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:34:30 by yarakassim        #+#    #+#             */
/*   Updated: 2022/01/30 01:25:42 by ykassim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../mlx/mlx.h"
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct      s_vector
{
    int x1;
    int x2;
    int y1;
    int y2;
    int dx;
    int dy;
    int e;
    int color;
}               t_vector;

typedef struct      s_map
{
    int     x_column;
    int     y_row;
	int		z_alt_max;
	int		z_alt_min;
	t_vector v;
}				t_map;

typedef struct      s_craft
{
    void	*mlx_ptr;
    void	*mlx_win;
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}           	t_craft;

void    my_mlx_pixel_put(t_craft *pix, int x, int y, int color);
void    bresenham1(t_craft *pix, t_vector *v);
void    bresenham2(t_craft *pix, t_vector *v);
void    bresenham3(t_craft *pix, t_vector *v);
void    bresenham4(t_craft *pix, t_vector *v);
void    draw_line(t_craft *pix, t_vector *v);
void 	abort_mission(int signal);
void    init(t_map *map);
void	minit(t_craft *craft);
void    liberation(char *ptr);
void	wireframe_in_3_2_1(char	*arg, t_map *map);
int     key_hook(int keycode, t_craft *craft);
int     parse_map(char *arg, t_map *map);
int     check_values(char **line, t_map *map);
int     column_count(char **col, int n);
void	release(t_craft *craft);
void	init_array(int **array, char *arg, t_map *map);
int		parse_again(int **array, char **line, t_map *map);

#endif
