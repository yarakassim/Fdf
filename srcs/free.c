/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykassim- <ykassim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 13:05:43 by ykassim-          #+#    #+#             */
/*   Updated: 2022/01/17 13:32:56 by ykassim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
# include <stdio.h>
void    liberation(char *ptr)
{
    if (ptr)
        free(ptr);
    ptr = NULL;
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