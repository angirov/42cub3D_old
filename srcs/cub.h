/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vangirov <vangirov@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 19:05:05 by vangirov          #+#    #+#             */
/*   Updated: 2022/09/13 17:37:30 by vangirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

/* for strerror */
# include <string.h>
# include <errno.h>

/* for perror */
# include <stdio.h> 

# include <stdlib.h>
# include <stddef.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

# define _USE_MATH_DEFINES
# define SHIFT_VAL 100
# define ANGLE_DIV 36

// window
# define WIDTH 1600
# define HEIGHT 800
# define HORISONT 0.7
# define TITLE "Fdf"

// colors
# define WHITE 0xffffff
# define RED 0xe80c0c
# define YELLOW 0xffff00 // e69138
# define GRAY 0x444444
# define L_GRAY 0xbebebe


# include "mlx_api.h"

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

typedef struct s_fpoint
{
	float	x;
	float	y;
	float	z;
	int		color;
}	t_fpoint;

typedef struct s_map	t_map;
typedef struct s_game	t_game;

typedef struct s_loc
{
	double	x;
	double	y;
} t_loc;

typedef struct s_player
{
	t_game	*game;
	t_loc	loc;
	double	direction;
	double	rotation_rate;
	double	speed;
}	t_player;

typedef struct s_grid
{
	int	heigth;
	int	width;
	int	scale;
}	t_grid;

typedef struct s_game
{
	t_graphics	*graphics;
	t_player	*player;
	t_grid		grid;
	int			px_width;
	int			px_heigth;
	int			*map; //(*map)[24];  // https://stackoverflow.com/questions/1052818
	t_loc		*ray_dirs;
	double		*distances;
	int			*sides;
	double		*wallhits;
}	t_game;

void	set_sizes(t_game *game, int width, int heigth, int scale);
void	player_set_location(t_player *player, t_loc loc);

// void	player_move_forward(t_player *player);
// void	player_move_back(t_player *player);
// void	player_move_right(t_player *player);
// void	player_move_left(t_player *player);
// void	player_turn_right(t_player *player);
// void	player_turn_left(t_player *player);

void	player_move_N(t_player *player);
void	player_move_S(t_player *player);
void	player_move_E(t_player *player);
void	player_move_W(t_player *player);

void	player_turn_right(t_player *player);
void	player_turn_left(t_player *player);

// math.c
double	vec_len(t_loc vec);
t_loc	norm_vec(t_loc vec);
t_loc	dir2vec(double radians);
t_loc	add_vecs(t_loc vec1, t_loc vec2);
t_loc	sc_mult(t_loc vec, double scalar);
double	rtd(double radians);
double	dtr(double degrees);
double	ft_abs(double num);
double	ft_max(double a, double b);

// drawing.c
void	ft_put_pixel(t_graphics *graphics, int x, int y, int color);
void	draw_line(t_loc l0, t_loc l1, int scale, int color, t_graphics *g);
void	ft_plot_f_line(t_fpoint p0, t_fpoint p1, int color, t_graphics *g);
void	ft_plot_line(t_point p0, t_point p1, int color, t_graphics *g);
void	fill_sqare(t_game *g, t_loc corner, int side, int color);
void	fill_rect(t_game *g, t_loc corner, int x, int y, int color);

// minimap.c
void	draw_rays(t_game *g);
int map_value(t_game *g, int x, int y);
void	fill_grid(t_game *g, int x, int y, int scale);
void	map_background(t_game *g);
void	draw_grid(t_game *g);

// raycasting.c
void cast_rays(t_player	*p);
void	draw_walls(t_game *g);

// key_hooks.c
int		deal_key(int key, t_game *game);

// exit.c //////////////////////////////////////////////////////
// void	ft_error(t_fdf *data, char *message);
// void	ft_escape(t_fdf *data);
// void	ft_free_data(t_fdf *data);
// int		ft_destroy(t_fdf *data);

#endif
