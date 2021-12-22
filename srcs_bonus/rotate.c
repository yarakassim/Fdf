/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazenag <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 18:11:25 by eazenag           #+#    #+#             */
/*   Updated: 2021/07/23 14:52:19 by eazenag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/fdf_bonus.h"

int	ft_print_profil(t_mlx *map)
{
	int	info;

	mlx_clear_window(map->ptr, map->window);
	mlx_destroy_image(map->ptr, map->image);
	map->unitY = 0.1;
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

int	ft_rotate(int button, t_mlx *map)
{
	int	info;

	mlx_clear_window(map->ptr, map->window);
	mlx_destroy_image(map->ptr, map->image);
	if (button == ROTATE_DOWN_KEY)
		map->unitY = map->unitY * 1.3;
	else if (button == ROTATE_UP_KEY)
		map->unitY = map->unitY * 0.8;
	map->unitZ = sqrt((map->unitX * map->unitX) + (map->unitY * map->unitY));
	map->image = mlx_new_image(map->ptr, map->size_imX, map->size_imY);
	if (map->image == NULL)
		return (ft_quit(map));
	map->data = (int *)(mlx_get_data_addr(map->image, &info, &info, &info));
	if (map->data == NULL)
		return (ft_quit(map));
	ft_draw_map(map);
	if (map->unitY < 0.1)
	{
		map->neg = 1;
		map->unitY *= -1;
	}
	return (0);
}

int	ft_rotate_neg(int button, t_mlx *map)
{
	int	info;

	mlx_clear_window(map->ptr, map->window);
	if (button == ROTATE_DOWN_KEY)
		map->unitY = map->unitY * 0.8;
	else if (button == ROTATE_UP_KEY)
		map->unitY = map->unitY * 1.3;
	map->unitZ = sqrt((map->unitX * map->unitX) + (map->unitY * map->unitY));
	map->image = mlx_new_image(map->ptr, map->size_imX, map->size_imY);
	if (map->image == NULL)
		return (ft_quit(map));
	map->data = (int *)(mlx_get_data_addr(map->image, &info, &info, &info));
	if (map->data == NULL)
		return (ft_quit(map));
	ft_draw_map(map);
	if (map->unitY > -0.1)
	{
		map->neg = 0;
		map->unitY *= -1;
	}
	return (0);
}
