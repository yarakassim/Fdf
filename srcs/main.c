#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../includes/fdf.h"

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

void	draw_line(data_t *pix, int x1, int y1, int x2, int y2, int color)
{
    int x, y, dx, dy, p;

    dy = y2 - y1;
    dx = x2 - x1;
    y = y1;
    x = x1;
    p = 2 * dy - dx;
    while (x < x2)
    {
        if (p >= 0) 
        {
            my_mlx_pixel_put(pix, x, y, color);
            y += 1;
            p = p + 2 * dy - 2 * dx;
        }
        else
        {
            my_mlx_pixel_put(pix, x, y, color);
            p = p + 2 * dy;
        }
        x += 1;
    }
}

int main(void)
{
    data_t  data;

    data.mlx_ptr = mlx_init();
    data.mlx_win = mlx_new_window(data.mlx_ptr, 1920, 1080, "fdf");
    data.img = mlx_new_image(data.mlx_ptr, 1920, 1080);
    data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
    
    draw_line(&data, 1000, 394, 1250, 400, 0x00FF0000);

    mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, data.img, 0, 0);
    mlx_loop(data.mlx_ptr);
}
