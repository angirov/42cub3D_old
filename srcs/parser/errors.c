/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vangirov <vangirov@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:06:56 by mokatova          #+#    #+#             */
/*   Updated: 2022/09/14 22:19:37 by vangirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	quit_game(t_parser *game, int err_number)
{
	if (err_number)
	{
		ft_putendl_fd("Error", 2);
		if (err_number == WRNG_ARG)
			ft_putendl_fd("Please, make sure there's one argument - *.cub", 2);
		else if (err_number == MAP_RULES)
			ft_putendl_fd("Please, make sure the map follows the rules", 2);
		else
			ft_putendl_fd(strerror(err_number), 2);
	}
	clean_n_free(game);
	// free(game->mlx);
	exit(err_number);
}

void	clean_n_free(t_parser *game)
{
	int	i;

	if (game->map->values)
		free_array(game->map->values);
	if (game->map)
		free(game->map);
	if (game->settings)
		free(game->settings);
	i = 0;
	while (i < 4)
	{
		if (game->settings->textures[i].ptr)
			mlx_destroy_image(game->mlx, game->settings->textures[i].ptr);
		i++;
	}
}

void	free_array(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		free(argv[i++]);
	free(argv);
	argv = NULL;
}
