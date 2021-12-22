/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazenag <eazenag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 15:26:21 by eli               #+#    #+#             */
/*   Updated: 2021/08/10 11:37:29 by eazenag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/fdf_bonus.h"

int	**ft_map(char *av, t_mlx map)
{
	char	*line;
	int		**tab;
	int		i;
	int		fd;

	fd = open(av, O_RDONLY);
	i = 0;
	tab = malloc(sizeof(int *) * map.nbr_lines);
	if (tab == NULL)
		return (NULL);
	while (i < map.nbr_lines)
	{
		tab[i] = malloc(sizeof(int) * map.nbr_col);
		if (get_next_line(fd, &line, 0) == -1 || line == NULL)
		{
			free(tab);
			return (NULL);
		}
		ft_fill_tab(tab[i], line);
		free(line);
		i++;
	}
	get_next_line(fd, &line, 1);
	close (fd);
	return (tab);
}

void	ft_fill_tab(int *tab, char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[j])
	{
		if (line[j] != ' ' && ((j > 0 && line[j - 1] == ' ') || j == 0))
		{
			tab[i] = ft_atoi(&line[j]);
			i++;
		}
		j++;
	}
}

int	ft_count_line(char *av, t_mlx *map)
{
	int		fd;
	char	*line;

	fd = open(av, O_RDONLY);
	if (fd == -1 || get_next_line(fd, &line, 0) != 1)
		return (-1);
	map->nbr_lines = 1;
	map->nbr_col = ft_maplen(line);
	map->higher = 0;
	map->lower = 0;
	ft_find_higher(line, map);
	free(line);
	while (get_next_line(fd, &line, 0) != 0)
	{
		(map->nbr_lines)++;
		if (ft_maplen(line) != map->nbr_col)
			map->nbr_col = -2;
		ft_find_higher(line, map);
		free(line);
	}
	free(line);
	close(fd);
	if (map->nbr_col <= 0)
		return (-1);
	return (1);
}

int	ft_maplen(char *s)
{
	unsigned int	i;
	int				j;

	j = 0;
	i = 0;
	while (s[j])
	{
		if (s[j] >= '0' && s[j] <= '9' && (s[j] != ' '
				&& ((j > 0 && s[j - 1] == ' ') || j == 0)))
			i++;
		j++;
	}
	return (i);
}

void	ft_find_higher(char *str, t_mlx *map)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && ((i > 0 && str[i - 1] == ' ') || i == 0))
		{
			if (ft_atoi(&str[i]) > map->higher)
				map->higher = ft_atoi(&str[i]);
			if (ft_atoi(&str[i]) < map->lower)
				map->lower = ft_atoi(&str[i]);
		}
		i++;
	}
}
