/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vangirov <vangirov@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 15:57:53 by vangirov          #+#    #+#             */
/*   Updated: 2022/09/13 11:06:30 by vangirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"


void	ft_clear_image(t_graphics *graphics)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			ft_put_pixel(graphics, x, y, 0x00000000);
			x++;
		}
		y++;
	}
}

void draw_player(t_player *player);
void	draw_all(t_game *game);

int	deal_key(int key, t_game *game)
{
	if (key == KEY_LEFT)
	{
		player_move_W(game->player);
		printf("move W\n");
	}
	if (key == KEY_UP)
	{
		player_move_N(game->player);
		printf("move N\n");
	}
	if (key == KEY_RIGHT)
	{
		player_move_E(game->player);
		printf("move E\n");
	}
	if (key == KEY_DOWN)
	{
		player_move_S(game->player);
		printf("move S\n");
	}

	if (key == KEY_Q)
		player_turn_left(game->player);
	if (key == KEY_W)
		player_turn_right(game->player);

	printf("loc: %lf : %lf\n",	game->player->loc.x,
								game->player->loc.y);
	// printf("squ: %d : %d\n",	(int)game->player->loc.x,
	// 							(int)game->player->loc.y);
	printf("dir: %lf\n", rtd(game->player->direction));
	
	ft_clear_image(game->graphics);
	draw_all(game);

	return (0);
}
