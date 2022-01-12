/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykassim- <ykassim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:46:10 by ykassim-          #+#    #+#             */
/*   Updated: 2022/01/12 16:45:15 by ykassim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

int parse_map(char *arg, t_data *data)
{
    int     fd;
   // int     len;
    char    *line;
  //  char    **tmp;

    fd = open(arg, O_RDONLY);
    data->col = 0;
    data->row = 0;
    line = ft_strdup("");
    while (line)
    {
        line = get_next_line(fd);
        if (line)
        {
            tmp = ft_split(line, ' ');
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
            data->row++;
        }
    }
    close(fd);
    return (1);
}