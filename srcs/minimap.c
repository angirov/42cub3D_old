/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vangirov <vangirov@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 10:31:21 by vangirov          #+#    #+#             */
/*   Updated: 2022/09/15 20:23:26 by vangirov         ###   ########.fr       */
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
		draw_line(g->player->loc, add_vecs(g->player->loc, hit_point), g->scale, YELLOW, g->graphics);
	}
}

// int	map_value(t_game *g, int x, int y)
// {
// 	return (g->map[y * g->grid.width + x]);
// }

int	map_value(t_game *g, int x, int y)
{
	return (g->map[y * g->parser->map->columns + x]);
}

void	fill_grid(t_game *g, int x, int y, int scale)
{
	// int s = g->scale;
	if (map_value(g, x, y) > 0)
		// printf("%d", g->map[y * g->parser->map.width + x]);
		fill_sqare(g, (t_loc){x, y}, 1, GRAY);
}

void	map_background(t_game *g)
{
	fill_rect(g, (t_loc){0, 0}, g->parser->map->columns, g->parser->map->rows, L_GRAY);
}

void	draw_grid(t_game *g)
{
	int	x;
	int	y;
	int	s;

	s = g->scale;
	y = 0;
	while (y < g->parser->map->rows)
	{
		x = 0;
		while (x < g->parser->map->columns)
		{
			if (x < g->parser->map->columns)
			{
				draw_line((t_loc){x, y}, (t_loc){x + 1, y}, s, GRAY, g->graphics);
			}
			if (y <= g->parser->map->rows)
				draw_line((t_loc){x, y}, (t_loc){x, y + 1}, s, GRAY, g->graphics);
			fill_grid(g, x, y, s);
			x++;
		}
		y++;
	}
}
