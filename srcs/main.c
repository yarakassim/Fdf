#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../includes/fdf.h"

void	*ft_memset	(void *b, int c, size_t len)
{
	unsigned char	*rep;

	rep = (unsigned char *)b;
	while (len)
	{
		*rep = (unsigned char)c;
		rep++;
		len--;
	}
	return (b);
}

int key_hook(int keycode, t_data *data)
{
    if (keycode == 65307)
    {
        mlx_destroy_window(data->mlx_ptr, data->mlx_win);
        exit(0);
    }
    return (0);
}

int main(int ac, char **av)
{
    t_data      data;
    t_vector    v;

    if (ac != 2)
    {
        write(0,"sorry, wrong number of arguments\n", 33);
        return(0);
    }
    if (!check_format(av[1]))
    {
        write(0, "sorry, map is not properly formatted\n", 37);
        return (0);
    }
    init(&data);
    ft_memset(&v, 0, sizeof(t_vector));
    v.x1 = 100;
    v.y1 = 300;
    v.x2 = 900;
    v.y2 = 300;
    v.color = 0x00FF0000;
    draw_line(&data, &v);
    mlx_key_hook(data.mlx_win, key_hook, &data);
    mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, data.img, 0, 0);
    mlx_loop(data.mlx_ptr);
}
