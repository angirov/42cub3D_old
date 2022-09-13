/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vangirov <vangirov@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 10:31:21 by vangirov          #+#    #+#             */
/*   Updated: 2022/09/13 11:06:30 by vangirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	draw_rays(t_game *g)
{
	t_loc	hit_point;
	int		screen = g->graphics->screen_width;	//px

	for(int x = 0; x < screen; x += screen / 100)
	{
		hit_point = sc_mult(norm_vec(g->ray_dirs[x]), g->distances[x]);
		draw_line(g->player->loc, add_vecs(g->player->loc, hit_point), g->grid.scale, YELLOW, g->graphics);
	}
}

int map_value(t_game *g, int x, int y)
{
	return (g->map[y * g->grid.width + x]);
}

void	fill_grid(t_game *g, int x, int y, int scale)
{
	// int s = g->grid.scale;
	if (map_value(g, x, y) > 0)
		// printf("%d", g->map[y * g->grid.width + x]);
		fill_sqare(g, (t_loc){x, y}, 1, GRAY);
}

void	map_background(t_game *g)
{
	fill_rect(g, (t_loc){0, 0}, g->grid.width, g->grid.heigth, L_GRAY);
}

void	draw_grid(t_game *g)
{
	int	x;
	int	y;
	int	s;

	printf("Hello scale: \n");
	s = g->grid.scale;
	y = 0;
	while (y < g->grid.heigth)
	{
		x = 0;
		while (x < g->grid.width)
		{
			if (x < g->grid.width)
			{
				draw_line((t_loc){x, y}, (t_loc){x + 1, y}, s, GRAY, g->graphics);
			}
			if (y <= g->grid.heigth)
				draw_line((t_loc){x, y}, (t_loc){x, y + 1}, s, GRAY, g->graphics);
			fill_grid(g, x, y, s);
			x++;
		}
		y++;
	}
}
