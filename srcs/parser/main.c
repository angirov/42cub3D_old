/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vangirov <vangirov@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 16:57:30 by mokatova          #+#    #+#             */
/*   Updated: 2022/09/14 20:15:13 by vangirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_parser	game;

	if (argc != 2)
		quit_game(&game, WRNG_ARG);
	game = (t_parser){0};
	game.mlx = mlx_init();
	parse(&game, argv[1]);
	quit_game(&game, errno);
}
