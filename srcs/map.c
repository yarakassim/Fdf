/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykassim- <ykassim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:46:10 by ykassim-          #+#    #+#             */
/*   Updated: 2022/01/14 16:52:25 by ykassim-         ###   ########.fr       */
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
    map->row = 0;
	line = ft_strdup("");
	while (line)
    {
		liberation(line);
        line = ft_strdup(get_next_line(fd));
        if (line)
        {
            map->tab = ft_split(line, ' ');
            if (!map->tab || !check_col(map))
            {
				printf("col : %d  >>  col : %d  >>  ", map->col, col_count(map->tab));
				liberation(line);
				super_liberation(map, fd);
				return (0);	
			}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
            map->tab = freedom(map->tab);
			map->row++;
        }
    }
    liberation(line);
    close(fd);
    return (1);
}

int     check_col(t_map *map)
{
    if (map->row == 0)
        map->col = col_count(map->tab);
    else
        if (map->col != col_count(map->tab))
            return (0);
    return (1);
}

int col_count(char **tab)
{
    int len;

    if (!tab)
        return (0);
    len = -1;
	while (tab[++len]);
    return (len);
}

void	wireframe_in_3_2_1(char *arg, t_map *map)
{
    init_array(arg, map);
}