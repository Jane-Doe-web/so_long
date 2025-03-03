/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteudle <esteudle@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:47:56 by esteudle          #+#    #+#             */
/*   Updated: 2025/02/18 14:48:02 by esteudle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "mlx_linux/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <X11/keysym.h>
# include <mlx.h>

# define WALL  "./textures/wall.xpm"
# define FLOOR "./textures/floor.xpm"
# define PLAYER_IDLE "./textures/player_idle.xpm"
# define PLAYER_LEFT "./textures/walk_left.xpm"
# define PLAYER_RIGHT "./textures/walk_right.xpm"
# define COLLECT "./textures/collectible.xpm"
# define EXIT "./textures/exit.xpm"
# define START "./textures/start.xpm"

# define TILE_SIZE 64

typedef struct vars
{
	void	*mlx;
	void	*window;
	void	*wall;
	void	*floor;
	void	*player;
	void	*exit;
	void	*start;
	void	*collect;
	void	*img;
	char	**map;
	char	**copy_map;
	int		map_height;
	int		map_width;
	int		x;
	int		y;
	int		count_collect;
	int		count_player;
	int		count_exit;
	int		player_y;
	int		player_x;
	int		init_player_y;
	int		init_player_x;
	int		exit_flag;
	int		reachable_collect;
	int		steps;
	int		exit_y;
	int		exit_x;
}	t_vars;

void	process_count_cpe(t_vars *vars);
void	if_characters_collectibles_player_exit(t_vars *vars);
void	error_handler(char *str, t_vars *vars);
void	count_map_height(char *map_path, t_vars *vars);
void	validate_map(t_vars *vars);
void	if_possible_to_win(t_vars *vars);
void	free_map(char **map, int height);
void	fill(t_vars *vars, char target, int row, int col);
void	flood_fill(char **map, t_vars *vars);
void	start_game_window(t_vars *vars);
void	draw_img(t_vars *vars, void *img, int x, int y);
void	render_map(t_vars *vars);
void	set_img(t_vars *vars);
void	render_background_and_walls(t_vars *vars);
void	render_the_rest(t_vars *vars);
void	move_player(t_vars *vars, int i, int j);
void	you_win(t_vars *vars);
void	exit_function(t_vars *vars);
void	free_images(t_vars *vars);
char	*trim_line(char *line);
char	**duplicate_map(t_vars *vars);
char	**read_map(char *map_path, t_vars *vars);
int		handle_exit(t_vars *vars);
int		handle_key(int keysym, t_vars *vars);
int		if_walls_rectangular(t_vars *vars);
int		open_map_file(char *map_path, t_vars *vars);

#endif
