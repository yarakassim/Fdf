/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazenag <eazenag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 15:26:08 by eli               #+#    #+#             */
/*   Updated: 2021/08/02 15:12:54 by eazenag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_free(t_mlx *map)
{
	int	i;

	i = 0;
	if (map->image)
		mlx_destroy_image(map->ptr, map->image);
	if (map->window)
	{
		mlx_clear_window(map->ptr, map->window);
		mlx_destroy_window(map->ptr, map->window);
		mlx_destroy_display(map->ptr);
		free(map->ptr);
	}
	while (i < map->nbr_lines)
	{
		free(map->tab[i]);
		i++;
	}
	free(map->tab);
	return (-1);
}

int	ft_quit(int keycode, t_mlx *map)
{
	if (keycode != ESC_KEY)
		return (0);
	ft_free(map);
	exit(1);
}

void	ft_draw_map(t_mlx *map)
{
	int		lines;
	int		i;

	i = 0;
	lines = map->nbr_lines;
	while (--lines)
	{
		map->Xa = map->beginX;
		map->Ya = map->beginY;
		ft_draw(map, &(map->tab[i]), map->tab[i][1], 0);
		map->beginX += map->unitX;
		map->beginY += map->unitY;
		map->beginY += (map->unitZ * map->tab[i][0]);
		map->beginY += (map->unitZ * -map->tab[i + 1][0]);
		i++;
		mlx_put_image_to_window(map->ptr, map->window, map->image, 0, 0);
	}
}

int	main(int ac, char **av)
{
	int		**tab;
	t_mlx	map;

	if (ac != 2 || ft_count_line(av[1], &map) == -1)
	{
		write(1, "Invalid map\n", 12);
		return (-1);
	}
	tab = ft_map(av[1], map);
	map.tab = tab;
	if (tab == NULL)
		return (-1);
	if (ft_config_units(&map) == -1)
		return (ft_free(&map));
	ft_draw_map(&map);
	mlx_key_hook(map.window, ft_quit, &map);
	mlx_loop(map.ptr);
	ft_free(&map);
	return (0);
}
