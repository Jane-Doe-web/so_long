#include "so_long.h"

int	open_map_file(char *map_path)
{
	int	fd;
	
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Failed to open the map file\n", 2);
		return (-1);
	}
	return (fd);
}

char    *trim_line(char *line)
{
	int len = ft_strlen(line);
	if (line[len - 1] == '\n')  // Check if the last character is a newline
		line[len - 1] = '\0';  
	return (line);
}
char	**read_map(char *map_path, t_vars *vars)
{
	int     fd;
	char    **map;
	char    *line;
	
	fd = open_map_file (map_path);
	while ((line = get_next_line(fd)) != NULL)
	{
		vars->map_height++;
		free(line);
	}
	close(fd);
	map = malloc(sizeof(char *) * (vars->map_height + 1));
	if (!map)
		return (NULL);
	fd = open_map_file (map_path);
	vars->map_height = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		map[vars->map_height] = line;
		trim_line(line);
		vars->map_height++;
	}
	map[vars->map_height] = NULL;
	close(fd);
	return (map);
}
