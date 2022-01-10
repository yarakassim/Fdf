/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykassim- <ykassim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:34:30 by yarakassim        #+#    #+#             */
/*   Updated: 2022/01/10 15:12:20 by ykassim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "get_next_line.h"
# include "libft.h"
# include <stdio.h>

typedef struct      s_data
{
    void	*mlx_ptr;
    void	*mlx_win;
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}                 t_data;

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

void    my_mlx_pixel_put(t_data *pix, int x, int y, int color);
void    bresenham1(t_data *pix, t_vector *v);
void    bresenham2(t_data *pix, t_vector *v);
void    bresenham3(t_data *pix, t_vector *v);
void    bresenham4(t_data *pix, t_vector *v);
void    draw_line(t_data *pix, t_vector *v);
void    *ft_memset(void *b, int c, size_t len);
int     key_hook(int keycode, t_data *data);
void    init(t_data *data);

#endif
