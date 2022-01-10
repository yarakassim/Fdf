#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../includes/fdf.h"
#include "../includes/get_next_line.h"

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
        mlx_destroy_window(data->mlx_ptr, data->mlx_win);
    return (0);
}

int main(int ac, char **av)
{
    t_data      data;
    t_vector    v;

    if (ac != 2)
    {
        printf("sorry, wrong number of arguments\n");
        return(0);
    }
    int fd;
    fd = open(av[1], O_RDONLY);
    get_next_line(fd);
    init(&data);
    ft_memset(&v, 0, sizeof(t_vector));
    v.x1 = 900;
    v.y1 = 900;
    v.x2 = 100;
    v.y2 = 300;
    v.color = 0x00FF0000;
    draw_line(&data, &v);
    mlx_key_hook(data.mlx_win, key_hook, &data);
    mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, data.img, 0, 0);
    mlx_loop(data.mlx_ptr);
}
