/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exits_linux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vangirov <vangirov@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:00:36 by vangirov          #+#    #+#             */
/*   Updated: 2022/09/13 11:06:30 by vangirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_error(t_fdf *data, char *message)
{
	ft_destroy(data);
	perror(message);
	exit(1);
}

void	ft_escape(t_fdf *data)
{
	ft_destroy(data);
	exit(0);
}

void	ft_free_data(t_fdf *data)
{
	int	i;

	i = 0;
	while (i < data->height)
		free(data->matrix[i++]);
	free(data->matrix);
	free(data);
}

// void	ft_free_mlx_linux(void *mlx_ptr, void *win_ptr, void *img_prt)
// {
// 	mlx_destroy_image(mlx_ptr, img_prt);
// 	mlx_destroy_window(mlx_ptr, win_ptr);
// 	mlx_destroy_display(mlx_ptr);
// }

// void	ft_free_mlx_macos(void *mlx_ptr, void *win_ptr, void *img_prt)
// {
// 	mlx_destroy_image(mlx_ptr, img_prt);
// 	mlx_destroy_window(mlx_ptr, win_ptr);
// }

int	ft_destroy(t_fdf *data)
{
	api_free_graphics_linux(data->graphics->mlx_ptr, data->graphics->win_ptr, data->graphics->img_prt);
	free(data->graphics->mlx_ptr);
	ft_free_data(data);
	exit(1);
}

