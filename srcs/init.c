/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykassim- <ykassim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:53:45 by ykassim-          #+#    #+#             */
/*   Updated: 2022/01/17 13:38:39 by ykassim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void init(t_map *map)
{
	ft_memset(map, 0, sizeof(map));
	//ft_memset(&craft->map, 0, sizeof(craft->map));
	//ft_memset(&craft->map.v, 0, sizeof(craft->map.v));
	if (!map)
		abort_mission(3);
}

void minit(t_craft *craft)
{
	craft->mlx_ptr = mlx_init();
    craft->mlx_win = mlx_new_window(craft->mlx_ptr, 1800, 1000, "fdf");
    craft->img = mlx_new_image(craft->mlx_ptr, 1800, 1000);
    craft->addr = mlx_get_data_addr(craft->img, &craft->bits_per_pixel, &craft->line_length, &craft->endian);
}
#include <stdio.h>
