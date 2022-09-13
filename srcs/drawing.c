/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vangirov <vangirov@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 10:23:34 by vangirov          #+#    #+#             */
/*   Updated: 2022/09/13 11:06:30 by vangirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// Here all rastarization functions are collected

void	ft_put_pixel(t_graphics *graphics, int x, int y, int color)
{
	api_put_pixel(graphics, x, y, color);
}

void	draw_line(t_loc l0, t_loc l1, int scale, int color, t_graphics *g)
{
	t_point	pt_px0;
	t_point	pt_px1;

	pt_px0.x = l0.x * scale;
	pt_px0.y = l0.y * scale;
	pt_px0.color = color;
	pt_px1.x = l1.x * scale;
	pt_px1.y = l1.y * scale;
	pt_px1.color = color;
	ft_plot_line(pt_px0, pt_px1, color, g);
}

void	ft_plot_f_line(t_fpoint p0, t_fpoint p1, int color, t_graphics *g)
{
	float	dx;
	float	dy;
	float	max;

	dx = p1.x - p0.x;
	dy = p1.y - p0.y;
	max = ft_max(ft_abs(dx), ft_abs(dy));
	dx /= max;
	dy /= max;
	while ((int)(p0.x - p1.x) || (int)(p0.y - p1.y))
	{
		ft_put_pixel(g, p0.x, p0.y, color);
		p0.x += dx;
		p0.y += dy;
	}
}

void	ft_plot_line(t_point p0, t_point p1, int color, t_graphics *g)
{
	t_fpoint	fpoint0;
	t_fpoint	fpoint1;

	fpoint0.x = p0.x;
	fpoint1.x = p1.x;
	fpoint0.y = p0.y;
	fpoint1.y = p1.y;
	fpoint0.color = p0.color;
	fpoint1.color = p1.color;
	ft_plot_f_line(fpoint0, fpoint1, color, g);
}

void	fill_sqare(t_game *g, t_loc corner, int side, int color)
{
	int corner_x;
	int corner_y;

	corner_x = corner.x * g->grid.scale;
	corner_y = corner.y * g->grid.scale;
	
	for (int i = 0; i < side*g->grid.scale; i++)
		for (int j = 0; j < side*g->grid.scale; j++)
			api_put_pixel(g->graphics, corner_x + i, corner_y + j, color);
}

void	fill_rect(t_game *g, t_loc corner, int x, int y, int color)
{
	int corner_x;
	int corner_y;

	corner_x = corner.x * g->grid.scale;
	corner_y = corner.y * g->grid.scale;
	
	for (int i = 0; i < y*g->grid.scale; i++)
		for (int j = 0; j < x*g->grid.scale; j++)
			api_put_pixel(g->graphics, corner_x + i, corner_y + j, color);
}
