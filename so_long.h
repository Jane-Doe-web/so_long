#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "mlx_linux/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# define WALL "./textures/walls.xpm"
# define FLOOR "./textures/floor.xpm"
# define PLAYER_IDLE "./textures/idle.xpm"
# define PLAYER_LEFT "./textures/walk_left.xpm"
# define PLAYER_RIGHT "./textures/walk_right.xpm"
# define COLLECTIBLE "./textures/kebab.xpm"
# define EXIT "./textures/train.xpm"

# define TILE_SIZE 64

typedef struct vars
{
	void	*mlx;
	char	**map;
	int	map_height;
	int	map_width;
	int	x; //position on the map
	int	y; //position on the map
	int	count_collect;
	int	count_player;
	int	count_exit;
}  	t_vars;

void	error_handler(char *str);
char    *trim_line(char *line);
int	open_map_file(char *map_path);
void	initialize_game(t_vars *vars, char *argv);
char	**read_map(char *map_path, t_vars *vars);
void	process_count_CPE(t_vars *vars);
int	if_characters_collectibles_player_exit (t_vars *vars);
int	if_walls_rectangular (t_vars *vars);
int	validate_map (t_vars *vars);

#endif