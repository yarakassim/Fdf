/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykassim- <ykassim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:46:10 by ykassim-          #+#    #+#             */
/*   Updated: 2022/02/19 11:13:30 by ykassim-         ###   ########.fr       */
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
	freedom((void **)col);
	if (map->x_column == 0)
		map->x_column = count;
	else if (count != map->x_column)
		return (0);
	return (1);
}

void	wireframe_in_3_2_1(char *arg, t_map *map)
{
	int		**array;
	int		i;

	array = (int **)malloc(sizeof(int *) * (map->y_row + 1));
	if (!array)
		abort_mission(3);
	i = -1;
	while (++i < map->y_row)
	{
		array[i] = (int *)malloc(sizeof(int) * (map->x_column + 1));
		if (!array[i])
		{
			freedom((void **)array);
			abort_mission(3);
		}
	}
	init_array(array, arg, map);

	// int x = -1;
	// int y;
	// while (array[++x])
	// {
	// 	y = 0;
	// 	printf("array[%d] = {", x );
	// 	while (array[x][y])
	// 	{
	// 		printf(" %d", array[x][y]);
	// 		y++;
	// 	}
	// 	printf(" }\n");
	// }
	i = 0;
	if (array[i])
	{
		while (array[i])
		{
			free(array[i]);
			i++;
		}
		free(array);
	}
}

int	parse_again(int **array, char **line, t_map *map, int i)
{
	char		**col;
	int			j;
	
	col = ft_split(*line, ' ');
	liberation(*line);
	if (!col)
		return (0);
	j = -1;
	while(++j < map->x_column)
		array[i][j] = ft_atoi(col[j]); 
	freedom((void **)col);
	col = NULL;
	i++;
	return (1);
}