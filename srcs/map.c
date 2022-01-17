/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykassim- <ykassim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:46:10 by ykassim-          #+#    #+#             */
/*   Updated: 2022/01/17 14:53:33 by ykassim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

int parse_map(char *arg, t_map *map)
{
	char	*line;
    int     fd;

    fd = open(arg, O_RDONLY);
	if (fd < 0)
		abort_mission(4);
    map->x_column = 0;
	map->y_row = 0;
	map->z_alt_max = 0;
	map->z_alt_min = 0;
	line = NULL;
	line = get_next_line(fd);
	while (line)
    {
		if (!check_values(&line, map))
			abort_mission(2);
		map->y_row++;
		line = get_next_line(fd);
	}
    liberation(line);
    close(fd);
    return (1);
}

int     check_values(char **line, t_map *map)
{
	char	**col;
	int		count;

	col = ft_split(*line, ' ');
	liberation(*line);
	if (!col)
		return (0);
	count = -1;
	while (col[++count])
	{
		if (ft_atoi(col[count]) > map->z_alt_max)
			map->z_alt_max = ft_atoi(col[count]);
		if (ft_atoi(col[count]) < map->z_alt_min)
			map->z_alt_min = ft_atoi(col[count]);
	}
	freedom(col);
	if (map->x_column == 0)
		map->x_column = count;
	else if (count != map->x_column)
		return (0);
	return (1);
}

/*void	wireframe_in_3_2_1(char *arg, t_map *map)
{
}*/