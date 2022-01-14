/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykassim- <ykassim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 13:05:43 by ykassim-          #+#    #+#             */
/*   Updated: 2022/01/14 16:52:13 by ykassim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void    liberation(char *ptr)
{
    if (ptr)
        free(ptr);
    ptr = NULL;
}

int super_liberation(t_map *map, int fd)
{
    map->tab = freedom(map->tab);
    close(fd);
	return (0);
}

void	release(t_craft *craft)
{
	if (craft->img)
        mlx_destroy_image(craft->mlx_ptr, craft->img);
    if(craft->mlx_win)
		mlx_destroy_window(craft->mlx_ptr, craft->mlx_win);
    mlx_destroy_display(craft->mlx_ptr);
    free(craft->mlx_ptr);
}