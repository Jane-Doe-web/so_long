#include "so_long.h"
void	free_map(char **map, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

char	**duplicate_map(t_vars *vars)
{
	char	**copy_map;
	int	i;

	i = 0;
	copy_map = malloc(sizeof(char *) * vars->map_height + 1);
	if (!copy_map)
		return(NULL);
	while (i < vars->map_height)
	{
		copy_map[i] = ft_strdup(vars->map[i]);
		if (!copy_map[i])
		{
			free_map(copy_map, i);
			return(NULL);
		}
		i++;
	}
	copy_map[i] = NULL;
	return(copy_map);
}
void	flood_fill(char **map, t_vars *vars) 
{
	int	i;
	int	j;
	char	target;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				vars->player_y = i;
				vars->player_x = j;
				map[i][j] == '0';
			}	
		}
	}
target = map[i][j];

}

void	if_possible_to_win(t_vars *vars)
{
	char **copy_map;

	copy_map = duplicate_map(vars);
	flood_fill(copy_map, vars);
}