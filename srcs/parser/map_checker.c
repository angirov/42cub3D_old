/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vangirov <vangirov@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 21:14:33 by mokatova          #+#    #+#             */
/*   Updated: 2022/09/14 20:15:13 by vangirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	any_wrong_symbols(t_parser *game, char **values)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (values[i])
	{
		j = 0;
		while (values[i][j])
		{
			if (values[i][j] != '1' && values[i][j] != '0'
				&& values[i][j] != ' ' && values[i][j] != 'N'
				&& values[i][j] != 'S' && values[i][j] != 'E'
				&& values[i][j] != 'W')
				quit_game(game, MAP_RULES);
			j++;
		}
		i++;
	}
}

void	are_borders_in_place(t_parser *game, char **values)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map->rows)
	{
		j = 0;
		while (values[i][j] == ' ')
			j++;
		if (values[i][j] != '1')
			quit_game(game, MAP_RULES);
		else if (values[i][game->map->columns - 1] != '1')
			quit_game(game, MAP_RULES);
		i++;
	}
	j = 0;
	while (j < game->map->columns)
	{
		if (values[0][j] != '1' && values[0][j] != ' ')
			quit_game(game, MAP_RULES);
		else if (values[game->map->rows - 1][j] != '1'
			&& values[game->map->rows - 1][j] != ' ')
			quit_game(game, MAP_RULES);
		j++;
	}
}

void	any_extra_players(t_parser *game, char **values)
{
	int	i;
	int	j;
	int	player;

	i = 0;
	player = 0;
	while (values[i])
	{
		j = 0;
		while (values[i][j])
		{
			if (values[i][j] == 'N' || values[i][j] == 'S'
				|| values[i][j] == 'E' || values[i][j] == 'W')
				player++;
			j++;
		}
		i++;
	}
	if (player != 1)
		quit_game(game, MAP_RULES);
}
