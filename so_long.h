#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "mlx_linux/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
#include <X11/keysym.h>

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
	int	map_height; 
	int	map_width;
	int	x; //map coordinates
	int	y; //map coordinates
	int	count_collect; //number of collectibles
	int	count_player; // number of P
	int	count_exit; // number of exits
	int	player_y; //player pos
	int	player_x; //player pos
	int	init_player_y; //initial position
	int	init_player_x;//initial position
	int	exit_flag; //if exit is reachable	
	int	reachable_collect; //if all collectibles are reachable
	int	steps;

}  	t_vars;

char    *trim_line(char *line);
char	**duplicate_map(t_vars *vars);
char	**read_map(char *map_path, t_vars *vars);
void	initialize_game(t_vars *vars);
void	process_count_cpe(t_vars *vars);
void	if_characters_collectibles_player_exit (t_vars *vars);
void	error_handler(char *str);
void	validate_map (t_vars *vars);
void	if_possible_to_win(t_vars *vars);
void	free_map(char **map, int height);
void	fill(char **map, t_vars *vars, char target, int row, int col);
void	flood_fill(char **map, t_vars *vars);
void	start_game_window(t_vars *vars);
void	draw_img(t_vars *vars, void *img, int x, int y);
void	render_map(t_vars *vars);
void	set_img(t_vars *vars);
void	draw_img(t_vars *vars, void *img, int x, int y);
void	render_background_and_walls(t_vars *vars);
void	render_the_rest(t_vars *vars);
void	move_player(t_vars *vars, int i, int j);
void	you_win(t_vars *vars);
void	exit_function(t_vars *vars);
void	free_images(t_vars *vars);
int	handle_exit(t_vars *vars);
int	handle_key(int keysym, t_vars *vars);
int	if_walls_rectangular (t_vars *vars);
int	open_map_file(char *map_path);

#endif