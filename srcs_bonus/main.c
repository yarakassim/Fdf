/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazenag <eazenag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 15:26:08 by eli               #+#    #+#             */
/*   Updated: 2021/08/02 15:15:15 by eazenag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/fdf_bonus.h"

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

int	ft_quit(t_mlx *map)
{
	ft_free(map);
	exit(1);
}

void	ft_draw_map(t_mlx *map)
{
	int		col;
	int		lines;
	int		i;
	double	beginX;
	double	beginY;

	i = 0;
	col = map->nbr_col;
	lines = map->nbr_lines;
	beginX = map->beginX;
	beginY = map->beginY;
	while (--lines)
	{
		map->Xa = map->beginX;
		map->Ya = map->beginY;
		ft_draw(map, &(map->tab[i]), map->tab[i][1], 0);
		map->beginX += map->unitX;
		map->beginY += map->unitY + (map->unitZ * map->tab[i][0]);
		map->beginY += (map->unitZ * -map->tab[i + 1][0]);
		i++;
		mlx_put_image_to_window(map->ptr, map->window, map->image, 0, 0);
	}
	map->beginX = beginX;
	map->beginY = beginY;
	map->nbr_col = col;
}

int	key_hook(int keycode, t_mlx *map)
{
	static int	im = 0;

	im ++;
	if (im == 1)
		return (0);
	if (keycode == ESC_KEY)
		ft_quit(map);
	if (keycode == ROTATE_UP_KEY || keycode == ROTATE_DOWN_KEY)
	{
		if (map->neg == 0)
			ft_rotate(keycode, map);
		else
			ft_rotate_neg(keycode, map);
		return (0);
	}
	if (keycode == UP_KEY || keycode == DOWN_KEY || keycode == RIGHT_KEY
		|| keycode == LEFT_KEY)
		ft_zoom(keycode, map);
	if (keycode == SPACE)
		ft_print_profil(map);
	return (0);
}

int	main(int ac, char **av)
{
	t_mlx	map;

	if (ac != 2 || ft_count_line(av[1], &map) == -1)
	{
		write(1, "Invalid map\n", 12);
		return (-1);
	}
	map.tab = ft_map(av[1], map);
	if (map.tab == NULL)
		return (-1);
	if (ft_config_units(&map) == -1)
		return (ft_free(&map));
	map.mouvY = 0;
	map.mouvY = 0;
	map.rotateX = 1;
	map.rotateY = 1;
	map.zoom = 1;
	map.neg = 0;
	ft_draw_map(&map);
	mlx_key_hook(map.window, key_hook, &map);
	mlx_mouse_hook(map.window, mouse_hook, &map);
	mlx_loop(map.ptr);
	ft_free(&map);
	return (0);
}
