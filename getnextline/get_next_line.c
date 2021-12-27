/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykassim- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 11:03:30 by ykassim-          #+#    #+#             */
/*   Updated: 2021/09/27 15:55:18 by ykassim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*juno;
	char		buffer[BUFFER_SIZE + 1];
	int			ret;

	if (fd == -1)
		return (NULL);
	while (len_index(juno, '\n') == -1)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		buffer[ret] = '\0';
		if (ret > 0)
		{
			if (!juno)
				juno = ft_dup(buffer, len_index(buffer, '\0'));
			else
				juno = ft_join(juno, buffer);
		}
		else
			break ;
	}
	return (operation_juno_line(&juno));
}

/*int main(void)
{
	int fd;
	fd = open(O_RDONLY);
	get_next_line(fd);
	return (0);
}*/
