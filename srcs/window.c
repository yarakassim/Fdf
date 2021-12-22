/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazenag <eazenag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 15:26:37 by eli               #+#    #+#             */
/*   Updated: 2021/07/23 14:50:47 by eazenag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_config_units(t_mlx *map)
{
	map->unitX = 12;
	map->unitY = 6;
	map->unitZ = sqrt((map->unitX * map->unitX) + (map->unitY * map->unitY));
	if (ft_create_window(map, map->nbr_lines, map->nbr_col) == -1)
		return (-1);
	map->beginX = map->size_imX / 15;
	if (map->lower < 0)
		map->lower *= -1;
	map->beginY = map->size_imY - ((map->lower * map->unitZ)
			+ (map->nbr_lines * map->unitY));
	return (0);
}

void	ft_define_size_im(t_mlx *map, int nbr_lines, int nbr_col)
{
	map->size_imX = ((nbr_lines + nbr_col) * (map->unitX)) + 50;
	map->size_imY = (nbr_col + nbr_lines) * (map->unitY)
		- ((map->lower - map->higher) * (map->unitZ));
	while (map->size_imX > 800 || map->size_imY > 700)
	{
		map->unitX /= 1.1;
		map->unitY /= 1.1;
		map->unitZ /= 1.1;
		map->size_imX = ((nbr_col + nbr_lines) * map->unitX) + 50;
		map->size_imY = (nbr_col + nbr_lines) * (map->unitY)
			- ((map->lower - map->higher) * (map->unitZ));
	}
}

int	ft_create_window(t_mlx *map, int nbr_lines, int nbr_col)
{
	int		pixel_bits;
	int		line_bytes;
	int		endian;

	map->ptr = mlx_init();
	if (map->ptr == NULL)
		return (-1);
	ft_define_size_im(map, nbr_lines, nbr_col);
	map->window = mlx_new_window(map->ptr, map->size_imX + 1,
			map->size_imY + 1, "Map");
	if (map->window == NULL)
		return (-1);
	map->image = mlx_new_image(map->ptr, map->size_imX, map->size_imY);
	if (map->image == NULL)
		return (-1);
	map->data = (int *)(mlx_get_data_addr(map->image, &pixel_bits,
				&line_bytes, &endian));
	if (map->data == NULL)
		return (-1);
	map->color = 0xC7E5F5;
	return (0);
}
