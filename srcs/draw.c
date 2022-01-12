/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykassim- <ykassim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 18:39:56 by ykassim-          #+#    #+#             */
/*   Updated: 2022/01/12 16:45:24 by ykassim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void    my_mlx_pixel_put(t_data *pix, int x, int y, int color)
{
    char    *dst;

    dst = pix->addr + (y * pix->line_length + x * (pix->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void    bresenham1(t_data *pix, t_vector *v)
{
    v->dx = v->x2 - v->x1;
    v->dy = v->y2 - v->y1;
    v->e = v->x2 - v->x1;

    while(v->x1 < v->x2)
    {
        my_mlx_pixel_put(pix, v->x1, v->y1, v->color);
        v->e -= v->dy;
        if (v->e <= 0)
        {
            v->y1++;
            v->e += v->dx;
        }
        v->x1++;
    }
}

void    bresenham2(t_data *pix, t_vector *v)
{
    v->dx = v->x2 - v->x1;
    v->dy = v->y2 - v->y1;
    v->e = v->y2 - v->y1;

    while(v->y1 < v->y2)
    {
        my_mlx_pixel_put(pix, v->x1, v->y1, v->color);
        v->e -= v->dx;
        if (v->e <= 0)
        {
            v->x1++;
            v->e += v->dy;
        }
        v->y1++;
    }
}

void    bresenham3(t_data *pix, t_vector *v)
{
    v->dx = v->x2 - v->x1;
    v->dy = v->y1 - v->y2;
    v->e = v->x2 - v->x1;

    while(v->x1 < v->x2)
    {
        my_mlx_pixel_put(pix, v->x1, v->y1, v->color);
        v->e -= v->dy;
        if (v->e <= 0)
        {
            v->y1--;
            v->e += v->dx;
        }
        v->x1++;
    }
}

void    bresenham4(t_data *pix, t_vector *v)
{
    v->dx = v->x2 - v->x1;
    v->dy = v->y1 - v->y2;
    v->e = v->y2 - v->y1;

    while(v->y1 < v->y2)
    {
        my_mlx_pixel_put(pix, v->x1, v->y1, v->color);
        v->e -= v->dx;
        if (v->e <= 0)
        {
            v->x1++;
            v->e += v->dy;
        }
        v->y1--;
    }
}

void	draw_line(t_data *pix, t_vector *v)
{
    int tmp;

    if (v->x1 > v->x2)
    {
        tmp = v->x1;
        v->x1 = v->x2;
        v->x2 = tmp;
        tmp = v->y1;
        v->y1 = v->y2;
        v->y2 = tmp;
    }
    v->dx = v->x2 - v->x1;
    if (v->y1 < v->y2)
    {
        v->dy = v->y2 - v->y1;
        if (v->dx > v->dy)
            bresenham1(pix, v);
        else
            bresenham2(pix, v);
    }
    else
    {
        v->dy = v->y1 - v->y2;
        if (v->dx > v->dy)
            bresenham3(pix, v);
        else
            bresenham4(pix, v);
    }
}