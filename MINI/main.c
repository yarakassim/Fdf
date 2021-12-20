#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <mlx.h>

typedef struct    data_s
{
    void	*mlx_ptr;
    void	*mlx_win;
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}                 data_t;

void    my_mlx_pixel_put(data_t *pix, int x, int y, int color)
{
    char    *dst;

    dst = pix->addr + (y * pix->line_length + x * (pix->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int main(void)
{
    data_t  data;

    data.mlx_ptr = mlx_init();
    data.mlx_win = mlx_new_window(data.mlx_ptr, 1920, 1080, "fdf");
    data.img = mlx_new_image(data.mlx_ptr, 1920, 1080);
    data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
    my_mlx_pixel_put(&data, 55, 55, 0x00FF0000);
    mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, data.img, 0, 0);
    mlx_loop(data.mlx_ptr);
}
