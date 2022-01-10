/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykassim- <ykassim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:53:45 by ykassim-          #+#    #+#             */
/*   Updated: 2022/01/10 14:55:28 by ykassim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void init(t_data *data)
{
    data->mlx_ptr = mlx_init();
    data->mlx_win = mlx_new_window(data->mlx_ptr, 1800, 1000, "fdf");
    data->img = mlx_new_image(data->mlx_ptr, 1800, 1000);
    data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
}