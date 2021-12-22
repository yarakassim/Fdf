/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazenag <eazenag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 17:03:22 by eli               #+#    #+#             */
/*   Updated: 2021/05/20 15:41:40 by eazenag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif
# define ERROR -1
# define END_LINE 1
# define END_FILE 0
# define FALSE -1

typedef struct s_struct
{
	int		fd;
	char	buffer[BUFFER_SIZE + 1];
	void	*next;
}			t_struct;

char		*ft_join(char *s1, char *s2);
void		ft_memset_gnl(void *b, int c, size_t len);
char		*ft_strdup_gnl(char *str);
int			get_next_line(int fd, char **line, int free_all);
t_struct	*lst_add(t_struct **struct_pointer, int filed);
#endif
