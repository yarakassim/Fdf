/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykassim- <ykassim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 08:51:14 by ykassim-          #+#    #+#             */
/*   Updated: 2022/01/14 14:41:30 by ykassim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void abort_mission(int signal)
{
	if (signal == 1)
        write(0,"sorry, wrong number of arguments\n", 33);
	else
		if (signal == 2)
			write(0, "sorry, map is not properly formatted\n", 37);
	else
		if (signal == 3)
			write(0, "sorry, initialization failed\n", 29);
	else
		if (signal == 4)
			write(0, "sorry, couldn't read file\n", 26);
	exit(0);
}