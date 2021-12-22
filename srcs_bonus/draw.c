/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazenag <eazenag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 17:12:39 by eli               #+#    #+#             */
/*   Updated: 2021/07/23 15:06:33 by eazenag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes_bonus/fdf_bonus.h"

void	ft_draw_small_line(t_mlx *map, double Xa, double Ya)
{
	double	deltaX;
	double	deltaY;
	int		pixels;
	int		cur;

	deltaX = (Xa + map->unitX) - Xa;
	deltaY = (Ya + map->unitY) - Ya;
	pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
	deltaX /= pixels;
	deltaY /= pixels;
	while (pixels)
	{
		cur = ((int)Ya * map->size_imX) + (int)Xa;
		if (cur > 0 && cur < map->size_imX * map->size_imY
			&& (int)Xa < map->size_imX && (int)Xa > 0)
			map->data[cur] = map->color;
		Xa += deltaX;
		Ya += deltaY;
		--pixels;
	}
}

void	draw_plane_line(t_mlx *map)
{
	double	deltaX;
	double	deltaY;
	int		pixels;
	int		cur;

	deltaX = (map->Xa + map->unitX) - map->Xa;
	deltaY = (map->Ya - map->unitY) - map->Ya;
	pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
	deltaX /= pixels;
	deltaY /= pixels;
	while (pixels)
	{	
		cur = ((int)map->Ya) * map->size_imX + (int)map->Xa;
		if (cur > 0 && cur < map->size_imX * map->size_imY
			&& (int)map->Xa < map->size_imX && (int)map->Xa > 0)
			map->data[cur] = map->color;
		map->Xa += deltaX;
		map->Ya += deltaY;
		--pixels;
	}
}

void	ft_draw_mid_line(t_mlx *map, double Xa, double Ya, int height)
{
	double	deltaX;
	double	deltaY;
	int		pixels;
	int		cur;

	deltaX = (Xa + map->unitX) - Xa;
	deltaY = (Ya + ((height * map->unitZ) + map->unitY)) - Ya;
	pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
	deltaX /= pixels;
	deltaY /= pixels;
	while (pixels)
	{
		cur = ((int)Ya) * map->size_imX + (int)Xa;
		if (cur > 0 && cur < map->size_imX * map->size_imY
			&& (int)Xa < map->size_imX && (int)Xa > 0)
			map->data[cur] = map->color;
		Xa += deltaX;
		Ya += deltaY;
		--pixels;
	}
}

void	ft_draw_up_down_line(t_mlx *map, int height)
{
	double	deltaX;
	double	deltaY;
	int		pixels;
	int		dirY;
	int		cur;

	dirY = (map->unitZ * -height) + map->unitY;
	deltaX = (map->Xa + map->unitX) - map->Xa;
	deltaY = (map->Ya - dirY) - map->Ya;
	pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
	deltaX /= pixels;
	deltaY /= pixels;
	while (pixels)
	{
		cur = ((int)map->Ya) * map->size_imX + (int)map->Xa;
		if (cur > 0 && cur < map->size_imX * map->size_imY
			&& (int)map->Xa < map->size_imX && (int)map->Xa > 0)
			map->data[cur] = map->color;
		map->Xa += deltaX;
		map->Ya += deltaY;
		--pixels;
	}
}

void	ft_draw(t_mlx *map, int **tab, int height, int n)
{
	while (n < map->nbr_col - 1 && tab[0][n] == height)
	{
		draw_plane_line(map);
		n++;
		if (tab[1][n] == tab[0][n])
			ft_draw_small_line(map, map->Xa, map->Ya);
		else
			ft_draw_mid_line(map, map->Xa, map->Ya, - (tab[1][n] - height));
		if (n + 1 < map->nbr_col)
			height = tab[0][n + 1];
	}
	if (n < map->nbr_col - 1 && tab[0][n] != height)
	{
		ft_draw_up_down_line(map, tab[0][n] - height);
		n++;
		if (tab[1][n] == tab[0][n])
			ft_draw_small_line(map, map->Xa, map->Ya);
		else
			ft_draw_mid_line(map, map->Xa, map->Ya, - (tab[1][n] - height));
		if (n + 1 < map->nbr_col)
			ft_draw(map, tab, tab[0][n + 1], n);
	}
}
