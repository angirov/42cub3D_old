/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vangirov <vangirov@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 21:13:20 by mokatova          #+#    #+#             */
/*   Updated: 2022/09/14 21:21:58 by vangirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	calculate_map_size(t_parser *game, int fd, char *line, t_list **list)
{
	// int		i;

	// i = 0;
	game->map = malloc(sizeof(t_map));
	game->map->rows = 0;
	game->map->columns = 0;
	*list = ft_lstnew(ft_strdup(line));
	while (line)
	{
		game->map->rows++;
		if ((int)ft_strlen(line) > game->map->columns)
			game->map->columns = ft_strlen(line);
		free(line);
		line = get_next_line(fd);
		if (line)
			ft_lstadd_back(list, ft_lstnew(ft_strdup(line)));
	}
}

void	malloc_map(t_parser *game)
{
	int	i;

	i = 0;
	game->map->values = malloc(sizeof(char *) * game->map->rows);
	if (!game->map->values)
		quit_game(game, errno);
	while (i < game->map->rows)
	{
		game->map->values[i] = malloc(sizeof(char) * game->map->columns);
		if (!game->map->values[i])
			quit_game(game, errno);
		i++;
	}
}

void	assign_values(t_parser *game, int fd, t_list *list)
{
	int	i;

	i = 0;
	while (list)
	{
		ft_strlcpy(game->map->values[i++], (char *)list->content,
			ft_strlen((char *)list->content) + 1);
		list = list->next;
	}
}

void	is_map_ok(t_parser *game)
{
	any_wrong_symbols(game, game->map->values);
	are_borders_in_place(game, game->map->values);
	any_extra_players(game, game->map->values);
}

void	clear_list(t_list **list)
{
	t_list	*tmp;

	while (*list)
	{
		tmp = *list;
		*list = (*list)->next;
		free((void *) tmp->content);
		free((void *) tmp);
	}
	*list = NULL;
}
