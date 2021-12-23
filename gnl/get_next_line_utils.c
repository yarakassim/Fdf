/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykassim- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 15:28:44 by ykassim-          #+#    #+#             */
/*   Updated: 2021/07/14 12:01:07 by ykassim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	len_index(char *str, char c)
{
	int	n;

	if (str == NULL)
		return (-1);
	n = 0;
	if (c == '\0')
	{
		while (str[n])
			n++;
		return (n);
	}
	while (str[n])
	{
		if (str[n] == c)
			return (n);
		n++;
	}
	return (-1);
}

char	*ft_dup(char *str, int len)
{
	char	*dup;
	int		i;

	if (!str)
		return (str);
	if (len > len_index(str, '\0'))
		len = len_index(str, '\0');
	dup = malloc(sizeof(char) * len + 1);
	if (!dup)
		return (NULL);
	i = -1;
	while (str[++i] && len--)
		dup[i] = str[i];
	dup[i] = '\0';
	return (dup);
}

char	*ft_join(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;
	int		len;

	if (!s1 || !s2)
		return (NULL);
	len = len_index(s1, '\0') + len_index(s2, '\0');
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		str[++j] = s1[i];
	free(s1);
	i = -1;
	while (s2[++i])
		str[++j] = s2[i];
	str[++j] = '\0';
	return (str);
}

char	*operation_juno_line(char **juno)
{
	char	*tmp;
	char	*line;

	line = NULL;
	if (len_index(*juno, '\n') != -1)
	{	
		line = ft_dup(*juno, len_index(*juno, '\n') + 1);
		tmp = ft_dup(&(*juno)[len_index(*juno, '\n') + 1],
				len_index(*juno, '\0'));
		free(*juno);
		*juno = tmp;
	}
	else if (*juno && *juno[0] != '\0')
	{
		line = ft_dup(*juno, len_index(*juno, '\0'));
		free(*juno);
		*juno = NULL;
	}
	else if (*juno)
	{
		free(*juno);
		*juno = NULL;
	}
	return (line);
}
