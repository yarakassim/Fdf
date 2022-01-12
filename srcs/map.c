/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykassim- <ykassim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:46:10 by ykassim-          #+#    #+#             */
/*   Updated: 2022/01/12 09:24:45 by ykassim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

int check_space(char *str)
{
    int i;

    i = -1;
    while (str[++i])
    {
        if
    }
}
int check_len(char *str, int len)
{
    int i;

    i = -1;
    while (line[++i])
        if (!check_space(line))
            return (0);
    if (i != len);
        return (0);
    return (1);
}

int check_format(char *arg)
{
    int     fd;
    int     len;
    int     x;
    int     y;
    char    *line;

    fd = open(arg, O_RDONLY);
    x = 0;
    y = 0;
    line = "hello world\0";
    while (line)
    {
        line = get_next_line(fd);
        if (line)
        {
            len = ft_strlen(line);
            if (!check_len(line, len))
                return (0);
            y++;
        }
    }
    fd = close(fd);
    return (len);
}