#include "cub.h"

void	player_set_location(t_player *player, t_loc loc)
{
	player->loc.x = loc.x;
	player->loc.y = loc.y;
}

void	player_move_N(t_player *player)
{
	player->loc.y -= player->speed;
}
void	player_move_S(t_player *player)
{
	player->loc.y += player->speed;
}
void	player_move_E(t_player *player)
{
	player->loc.x += player->speed;
}
void	player_move_W(t_player *player)
{
	player->loc.x -= player->speed;
}

void	player_turn_right(t_player *player)
{
	player->direction += player->rotation_rate;
}

void	player_turn_left(t_player *player)
{
	player->direction -= player->rotation_rate;
}


void	set_sizes(t_game *game, int grid_width, int grid_heigth, int scale)
{
	game->grid.width = grid_width;
	game->grid.heigth = grid_heigth;
	game->grid.scale = scale;
	game->px_width = game->grid.width * game->grid.scale;
	game->px_heigth = game->grid.heigth * game->grid.scale;
}