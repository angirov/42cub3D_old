/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vangirov <vangirov@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 10:32:40 by vangirov          #+#    #+#             */
/*   Updated: 2022/09/13 15:21:28 by vangirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

typedef struct s_raycast
{
	int		screen;
	t_loc	dir_vec;
	t_loc	plane_vec;
	int		map_x;
	int		map_y;
	t_loc	delta;
	t_loc	side_dist;
	int		step_x;
	int		step_y;
}	t_raycast;

void	set_ray_dir(t_game *g, t_raycast *rc, int x)
{
	double	camera;
	t_loc	ray_dir;

	camera = 2 * x / (double)rc->screen - 1;
	ray_dir = add_vecs(rc->dir_vec, sc_mult(rc->plane_vec, camera));
	g->ray_dirs[x] = ray_dir;
	rc->delta.x = sqrt(1 + (g->ray_dirs[x].y * g->ray_dirs[x].y) \
		/ (g->ray_dirs[x].x * g->ray_dirs[x].x));
	rc->delta.y = sqrt(1 + (g->ray_dirs[x].x * g->ray_dirs[x].x) \
		/ (g->ray_dirs[x].y * g->ray_dirs[x].y));
}

void	set_step_side_dist(t_game *g, t_raycast *rc, int x)
{
	int	map_x;
	int	map_y;

	map_x = rc->map_x;
	map_y = rc->map_y;
	if (g->ray_dirs[x].x < 0)
	{
		rc->step_x = -1;
		rc->side_dist.x = (g->player->loc.x - map_x) * rc->delta.x;
	}
	else
	{
		rc->step_x = 1;
		rc->side_dist.x = (map_x + 1.0 - g->player->loc.x) * rc->delta.x;
	}
	if (g->ray_dirs[x].y < 0)
	{
		rc->step_y = -1;
		rc->side_dist.y = (g->player->loc.y - map_y) * rc->delta.y;
	}
	else
	{
		rc->step_y = 1;
		rc->side_dist.y = (map_y + 1.0 - g->player->loc.y) * rc->delta.y;
	}
}

void	set_side_dist(t_game *g, t_raycast *rc, int x, int side)
{
	if (side == 0)
		rc->side_dist.x = (rc->side_dist.x - rc->delta.x);
	else
		rc->side_dist.y = (rc->side_dist.y - rc->delta.y);
	if (rc->side_dist.x < rc->side_dist.y)
		g->distances[x] = rc->side_dist.x;
	else
		g->distances[x] = rc->side_dist.y;
	g->sides[x] = side;
}

void	perform_rc(t_game *g, t_raycast *rc, int x)
{
	int	hit;
	int	side;

	hit = 0;
	while (hit == 0)
	{
		if (rc->side_dist.x < rc->side_dist.y)
		{
			rc->side_dist.x += rc->delta.x;
			rc->map_x += rc->step_x;
			side = 0;
		}
		else
		{
			rc->side_dist.y += rc->delta.y;
			rc->map_y += rc->step_y;
			side = 1;
		}
		if (g->map[rc->map_y * 24 + rc->map_x] > 0)
			hit = 1;
	}
	set_side_dist(g, rc, x, side);
}

void	cast_rays(t_player *p)
{
	t_raycast	rc;
	int			x;

	rc.screen = p->game->graphics->screen_width;
	rc.dir_vec = dir2vec(p->direction);
	rc.plane_vec = dir2vec(p->direction + dtr(90));
	p->game->distances = malloc(sizeof(double) * rc.screen);
	p->game->sides = malloc(sizeof(int) * rc.screen);
	p->game->ray_dirs = malloc(sizeof(t_loc) * rc.screen);
	x = 0;
	while (x < rc.screen)
	{
		rc.map_x = (int)p->loc.x;
		rc.map_y = (int)p->loc.y;
		set_ray_dir(p->game, &rc, x);
		set_step_side_dist(p->game, &rc, x);
		perform_rc(p->game, &rc, x);
		x++;
	}
}

// void	init_raycasting(t_player *p, t_raycast *rc)
// {
// 	rc->screen = p->game->graphics->screen_width;	//px
// 	rc->dir_vec = dir2vec(p->direction);
// 	rc->plane_vec = dir2vec(p->direction + dtr(90));
// 	p->game->distances = malloc(sizeof(double) * rc->screen);
// 	p->game->sides = malloc(sizeof(int) * rc->screen);
// 	p->game->ray_dirs = malloc(sizeof(t_loc) * rc->screen);
// 	rc->map_x = (int)p->loc.x;
// 	rc->map_y = (int)p->loc.y;
// }
