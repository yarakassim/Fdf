/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_trans.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazenag <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 14:13:44 by eazenag           #+#    #+#             */
/*   Updated: 2021/07/28 16:32:14 by eazenag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/fdf_bonus.h"

int	mouse_hook(int button, int x, int y, t_mlx *map)
{
	int	info;

	map->zoom = 1;
	(void)x;
	(void)y;
	if (button == ZOOM)
		map->zoom = 1.3;
	else if (button == UNZOOM)
		map->zoom = 0.8;
	else
		return (0);
	mlx_clear_window(map->ptr, map->window);
	mlx_destroy_image(map->ptr, map->image);
	map->unitX = map->unitX * map->zoom;
	map->unitY = map->unitY * map->zoom;
	map->unitZ = sqrt((map->unitX * map->unitX) + (map->unitY * map->unitY));
	map->image = mlx_new_image(map->ptr, map->size_imX, map->size_imY);
	if (map->image == NULL)
		return (ft_quit(map));
	map->data = (int *)(mlx_get_data_addr(map->image, &info, &info, &info));
	if (map->data == NULL)
		return (ft_quit(map));
	ft_draw_map(map);
	return (0);
}

int	ft_zoom(int keycode, t_mlx *map)
{
	int			info;

	map->mouvY = 0;
	map->mouvX = 0;
	if (keycode == DOWN_KEY)
		map->mouvY -= 10;
	else if (keycode == UP_KEY)
		map->mouvY += 10;
	else if (keycode == RIGHT_KEY)
		map->mouvX += 10;
	else if (keycode == LEFT_KEY)
		map->mouvX -= 10;
	mlx_clear_window(map->ptr, map->window);
	mlx_destroy_image(map->ptr, map->image);
	map->image = mlx_new_image(map->ptr, map->size_imX, map->size_imY);
	if (map->image == NULL)
		return (ft_quit(map));
	map->data = (int *)(mlx_get_data_addr(map->image, &info,
				&info, &info));
	if (map->data == NULL)
		return (ft_quit(map));
	map->beginX += map->mouvX;
	map->beginY += map->mouvY;
	ft_draw_map(map);
	return (0);
}
