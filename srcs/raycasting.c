/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vangirov <vangirov@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 10:32:40 by vangirov          #+#    #+#             */
/*   Updated: 2022/09/13 15:02:43 by vangirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

typedef struct s_raycast
{
	int		screen;
	t_loc	dir_vec;
	t_loc	plane_vec;
	int		mapX;
	int		mapY;
	t_loc	deltaDist;
	t_loc	sideDist;
	int		stepX;
	int		stepY;
}	t_raycast;

void	set_rayDir(t_game *g, t_raycast *rc, int x)
{
	double	cameraX;
	t_loc	rayDir;

	//calculate ray position and direction
	cameraX = 2 * x / (double)rc->screen - 1; //x-coordinate in camera space
	rayDir = add_vecs(rc->dir_vec, sc_mult(rc->plane_vec, cameraX));
	g->ray_dirs[x] = rayDir;
	rc->deltaDist.x = sqrt(1 + \
		(g->ray_dirs[x].y * g->ray_dirs[x].y) / (g->ray_dirs[x].x * g->ray_dirs[x].x));
	rc->deltaDist.y = sqrt(1 + \
		(g->ray_dirs[x].x * g->ray_dirs[x].x) / (g->ray_dirs[x].y * g->ray_dirs[x].y));
}

void	set_step_sideDist(t_game *g, t_raycast *rc, int x)
{
	int	mapX;
	int	mapY;

	mapX = rc->mapX;
	mapY = rc->mapY;
	if (g->ray_dirs[x].x < 0)
	{
		rc->stepX = -1;
		rc->sideDist.x = (g->player->loc.x - mapX) * rc->deltaDist.x;
	}
	else
	{
		rc->stepX = 1;
		rc->sideDist.x = (mapX + 1.0 - g->player->loc.x) * rc->deltaDist.x;
	}
	if (g->ray_dirs[x].y < 0)
	{
		rc->stepY = -1;
		rc->sideDist.y = (g->player->loc.y - mapY) * rc->deltaDist.y;
	}
	else
	{
		rc->stepY = 1;
		rc->sideDist.y = (mapY + 1.0 - g->player->loc.y) * rc->deltaDist.y;
	}
}

void	set_side_dist(t_game *g, t_raycast *rc, int x, int side)
{
	if(side == 0)
		rc->sideDist.x = (rc->sideDist.x - rc->deltaDist.x);
	else
		rc->sideDist.y = (rc->sideDist.y - rc->deltaDist.y);
	if (rc->sideDist.x < rc->sideDist.y)
		g->distances[x] = rc->sideDist.x;
	else
		g->distances[x] = rc->sideDist.y;
	g->sides[x] = side;
}

void	perform_rc(t_game *g, t_raycast *rc, int x)
{
	int hit = 0;
	int side;
	int mapX = rc->mapX;
	int mapY = rc->mapY;

	while (hit == 0)
	{
		if (rc->sideDist.x < rc->sideDist.y)
		{
			rc->sideDist.x += rc->deltaDist.x;
			mapX += rc->stepX;
			side = 0;
		}
		else
		{
			rc->sideDist.y += rc->deltaDist.y;
			mapY += rc->stepY;
			side = 1;
		}
		if (g->map[mapY * 24 + mapX] > 0)
			hit = 1;
	}
	set_side_dist(g, rc, x, side);
}

void cast_rays(t_player	*p)
{
	t_raycast	rc;

	rc.screen = p->game->graphics->screen_width;
	rc.dir_vec = dir2vec(p->direction);
	rc.plane_vec = dir2vec(p->direction + dtr(90));
	p->game->distances = malloc(sizeof(double) * rc.screen);
	p->game->sides = malloc(sizeof(int) * rc.screen);
	p->game->ray_dirs = malloc(sizeof(t_loc) * rc.screen);
	rc.mapX = (int)p->loc.x;
	rc.mapY = (int)p->loc.y;

	for(int x = 0; x < rc.screen; x++)
	{
		set_rayDir(p->game, &rc, x);
		set_step_sideDist(p->game, &rc, x);
		perform_rc(p->game, &rc, x);
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
// 	rc->mapX = (int)p->loc.x;
// 	rc->mapY = (int)p->loc.y;
// }
