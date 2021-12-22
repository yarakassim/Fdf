/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazenag <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 15:12:05 by eazenag           #+#    #+#             */
/*   Updated: 2021/07/23 15:13:23 by eazenag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include  "../minilibx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <math.h>
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"

# define UP_KEY 122
# define DOWN_KEY 119
# define LEFT_KEY 97
# define RIGHT_KEY 115
# define ROTATE_UP_KEY 65362
# define ROTATE_DOWN_KEY 65364
# define SPACE 32
# define ZOOM 1
# define UNZOOM 3
# define ESC_KEY 65307

typedef struct s_mlx
{
	void	*ptr;
	void	*window;
	int		nbr_lines;
	int		nbr_col;
	void	*image;
	int		*data;
	int		size_imX;
	int		size_imY;
	int		higher;
	int		lower;
	double	beginX;
	double	beginY;
	double	Xa;
	double	Ya;
	int		**tab;
	int		color;
	double	unitX;
	double	unitY;
	double	unitZ;
	double	zoom;
	double	mouvX;
	double	mouvY;
	int		neg;
	double	rotateX;
	double	rotateY;
}			t_mlx;

void	ft_draw_map(t_mlx *map);
int		ft_quit(t_mlx *map);
int		key_hook(int keycode, t_mlx *map);
int		ft_free(t_mlx *map);

int		ft_config_units(t_mlx *map);
int		ft_create_window(t_mlx *map, int nbr_lines, int nbr_col);
void	ft_define_size_im(t_mlx *map, int nbr_lines, int nbr_col);

void	draw_plane_line(t_mlx *map);
void	ft_draw(t_mlx *map, int **tab, int height, int n);
void	ft_draw_small_line(t_mlx *map, double Xa, double Ya );
void	ft_draw_up_down_line(t_mlx *map, int height);

int		**ft_map(char *av, t_mlx map);
void	ft_fill_tab(int *tab, char *line);
int		ft_count_line(char *av, t_mlx *map);
int		ft_maplen(char *s);
void	ft_find_higher(char *str, t_mlx *map);

int		mouse_hook(int button, int x, int y, t_mlx *map);
int		ft_zoom(int button, t_mlx *map);

int		ft_rotate(int button, t_mlx *map);
int		ft_rotate_neg(int button, t_mlx *map);
int		ft_print_profil(t_mlx *map);

#endif
