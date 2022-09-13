/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vangirov <vangirov@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 10:32:40 by vangirov          #+#    #+#             */
/*   Updated: 2022/09/13 11:06:30 by vangirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void cast_rays(t_player	*p)
{
	int		screen = p->game->graphics->screen_width;	//px
	// int		fov = 90;		// degrees
	
	t_loc	dir_vec = dir2vec(p->direction);
	// t_loc	center = add_vecs(p->loc, dir_vec);
	t_loc	plane_vec = dir2vec(p->direction + dtr(90));
	
	p->game->distances = malloc(sizeof(double) * screen);
	p->game->sides = malloc(sizeof(int) * screen);
	p->game->ray_dirs = malloc(sizeof(t_loc) * screen);

	for(int x = 0; x < screen; x++)
	{
		printf(">>> Ray %2d ", x);
		t_loc	rayDir;
		double	cameraX;

		//calculate ray position and direction
		cameraX = 2 * x / (double)screen - 1; //x-coordinate in camera space
		rayDir = add_vecs(dir_vec, sc_mult(plane_vec, cameraX));
		p->game->ray_dirs[x] = rayDir;
		printf("rD.x: %lf ", rayDir.x);
		printf("rD.y: %lf\t", rayDir.y);
		// draw_line(p->loc, add_vecs(p->loc, norm_vec(rayDir)), p->game->grid.scale, WHITE, p->game->graphics);
	
		double	deltaDistX = sqrt(1 + (rayDir.y * rayDir.y) / (rayDir.x * rayDir.x));
		double	deltaDistY = sqrt(1 + (rayDir.x * rayDir.x) / (rayDir.y * rayDir.y));
		// double deltaDistX = (rayDir.x == 0) ? 1e30 : ft_abs(1 / rayDir.x);
		// double deltaDistY = (rayDir.y == 0) ? 1e30 : ft_abs(1 / rayDir.y);
		printf("dX: %lf ", deltaDistX);
		printf("dY: %lf ", deltaDistY);
		//which box of the map we're in
		int mapX = (int)p->loc.x;
		int mapY = (int)p->loc.y;
		//length of ray from current position to next x or y-side
		double sideDistX;
		double sideDistY;
		//length of ray from one x or y-side to next x or y-side
		// double perpWallDist;//////////////////////////////////////
		//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;
		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?

		//calculate step and initial sideDist
		if (rayDir.x < 0)
		{
			stepX = -1;
			sideDistX = (p->loc.x - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - p->loc.x) * deltaDistX;
		}
		if (rayDir.y < 0)
		{
			stepY = -1;
			sideDistY = (p->loc.y - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - p->loc.y) * deltaDistY;
		}
		// perform DDA
		printf("StepX: %d SDX: %lf ", stepX, sideDistX);
		printf("StepY: %d SDY: %lf ", stepY, sideDistY);
		while (hit == 0)
		{
			//jump to next map square, either in x-direction, or in y-direction
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			//Check if ray has hit a wall
			if (p->game->map[mapY*24 + mapX] > 0)
				hit = 1;
		}
		printf("side: %d", side);
		printf("SideDistX: %lf ", sideDistX);
		printf("SideDistY: %lf\n", sideDistY);
		if(side == 0)
			sideDistX = (sideDistX - deltaDistX);
		else
			sideDistY = (sideDistY - deltaDistY);
		// t_loc	hit_point;
		if (sideDistX < sideDistY)
		{
			// hit_point = sc_mult(norm_vec(rayDir), sideDistX);
			p->game->distances[x] = sideDistX;
		}
		else
		{
			// hit_point = sc_mult(norm_vec(rayDir), sideDistY);
			p->game->distances[x] = sideDistY;
		}
		p->game->sides[x] = side;
		// draw_line(p->loc, add_vecs(p->loc, hit_point), p->game->grid.scale, RED, p->game->graphics);
	}
	for(int x = 0; x < screen; x++)
		// printf("%2d: %lf\n", x, p->game->distances[x]);
	{
		int h = p->game->graphics->screen_height;
		int lineHeight = (int)(h / p->game->distances[x]);
		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + h / 2;
		if(drawStart < 0)drawStart = 0;
		int drawEnd = lineHeight / 2 + h / 2;
		if(drawEnd >= h)drawEnd = h - 1;
		int color = RED;
		if (p->game->sides[x] == 1) {color = color / 2;}
		draw_line((t_loc){x, drawStart}, (t_loc){x, drawEnd}, 1, color, p->game->graphics);
	}
}
