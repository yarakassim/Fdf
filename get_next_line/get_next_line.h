/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykassim- <ykassim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 09:56:07 by ykassim-          #+#    #+#             */
/*   Updated: 2022/01/11 15:52:41 by ykassim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

#define BUFFER_SIZE 400

char	*get_next_line(int fd);
int		len_index(char *str, char c);
char	*operation_juno_line(char **juno);
char	*ft_dup(char *str, int len);
char	*ft_join(char *s1, char *s2);

#endif
