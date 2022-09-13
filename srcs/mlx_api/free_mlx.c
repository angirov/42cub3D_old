#include "mlx_api.h"

void api_free_graphics_linux(void *mlx_ptr, void *win_ptr, void *img_prt)
{
	// mlx_destroy_image(mlx_ptr, img_prt);
	// mlx_destroy_window(mlx_ptr, win_ptr);
	// mlx_destroy_display(mlx_ptr);
}

void api_free_graphics_macos(void *mlx_ptr, void *win_ptr, void *img_prt)
{
	mlx_destroy_image(mlx_ptr, img_prt);
	mlx_destroy_window(mlx_ptr, win_ptr);
}

///////////////////////////////////////////////////////////

void api_put_pixel(t_graphics *api_data, int x, int y, int color)
{
	char *dst;

	if (x >= 0 && x < api_data->screen_width && y >= 0 && y < api_data->screen_height)
	{
		dst = api_data->img_addr + (y * api_data->line_length + x * (api_data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

t_graphics	*api_init_graphics(int width, int height, char *title)
{
	t_graphics *api_data;

	api_data = (t_graphics *)malloc(sizeof(t_graphics));
	api_data->screen_width = width;
	api_data->screen_height = height;
	api_data->mlx_ptr = mlx_init();
	// if (!api_data->mlx_ptr)
	// 	api_error(api_data, "mlx_init failed");
	api_data->win_ptr = mlx_new_window(api_data->mlx_ptr, width, height, title);
	// if (!api_data->mlx_ptr)
	// 	api_error(api_data, "mlx_new_window failed");
	api_data->img_prt = mlx_new_image(api_data->mlx_ptr, width, height);
	// if (!api_data->img_prt)
	// 	api_error(api_data, "mlx_new_image failed");
	api_data->img_addr = mlx_get_data_addr(api_data->img_prt,
										   &api_data->bits_per_pixel, &api_data->line_length,
										   &api_data->endian);
	return (api_data);
}
