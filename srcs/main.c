#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../includes/fdf.h"


int main(void)
{
    t_data      data;
    t_vector    v;

    data.mlx_ptr = mlx_init();
    data.mlx_win = mlx_new_window(data.mlx_ptr, 1000, 600, "fdf");
    data.img = mlx_new_image(data.mlx_ptr, 1000, 600);
    data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
    v.x1 = 100;
    v.y1 = 100;
    v.x2 = 90;
    v.y2 = 15;
    v.color = 0x00FF0000;
    draw_line(&data, &v);

    mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, data.img, 0, 0);
    mlx_loop(data.mlx_ptr);
}
