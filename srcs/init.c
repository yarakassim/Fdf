/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykassim- <ykassim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:53:45 by ykassim-          #+#    #+#             */
/*   Updated: 2022/01/14 17:12:43 by ykassim-         ###   ########.fr       */
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
void	init_array(char *arg, t_map *map)
{
	int 	fd;
	char	*line;
	int		y;
	int		x;
	int		i;

	fd = open(arg, O_RDONLY);
	if (fd < 0)
		abort_mission(4);
	map->array = malloc(sizeof(int *) * map->row);
	line = ft_strdup("");
	y = 0;
	x = -1;
	i = -1;
	while (line)
    {
		liberation(line);
        line = ft_strdup(get_next_line(fd));
        if (line)
        {
            map->tab = ft_split(line, ' ');
			while (map->tab[++i])
			{
				map->array[y] = malloc(sizeof(int) * map->col);
				map->array[y][++x] = ft_atoi(map->tab[i]);
			}
			y++;
			i = -1;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
            map->tab = freedom(map->tab);
        }
    }
    liberation(line);
    close(fd);
	y = -1;
	x = -1;
	printf("array[%d] = {", y);
	while (++y < map->row)
	{
		while (++x < map->col)
			printf(" %d ", map->array[y][x]);
		x = -1;
		printf("}\n");
	}			
}