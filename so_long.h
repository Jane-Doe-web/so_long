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
}  	t_vars;

#endif