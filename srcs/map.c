/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykassim- <ykassim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:46:10 by ykassim-          #+#    #+#             */
/*   Updated: 2022/01/11 13:34:45 by ykassim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

int check_format(char *arg)
{
    int     fd;
    int     len;
    char    *line;

    fd = open(arg, O_RDONLY);
    line = "hello world";
    while (line)
    {
        line = get_next_line(fd);
        if (line && len)
        {
            printf("line : %s", line);
            len = ft_strlen(line);
        }
    }
    return (1);
}