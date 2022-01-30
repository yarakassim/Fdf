#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../includes/fdf.h"

int key_hook(int keycode, t_craft *craft)
{
    if (keycode == 65307)
    {
		if (craft->mlx_ptr)
			release(craft);
        exit(0);
    }
    return (0);
}

int main(int ac, char **av)
{
    t_craft		craft;
	t_map		map;
    t_vector    v;

    if (ac != 2)
		abort_mission(1);
	init(&map);
    if (!parse_map(av[1], &map))
		abort_mission(2);
	wireframe_in_3_2_1(av[1], &map);
	minit(&craft);
    v.x1 = 100;
    v.y1 = 300;
    v.x2 = 900;
    v.y2 = 300;
    v.color = 0x00FF0000;
    draw_line(&craft, &v);
    mlx_key_hook(craft.mlx_win, key_hook, &craft);
    mlx_put_image_to_window(craft.mlx_ptr, craft.mlx_win, craft.img, 0, 0);
    mlx_loop(craft.mlx_ptr);
}
