#include "so_long.h"

/*initialize_game(t_vars vars, char *path)
{

}*/

char **read_map(char *map_path)
{
	int	fd;
	char	**map;
	int 	i;
	char	*line;
	int	line_count;

	line_count = 0;
	i = 0;
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return(NULL);
	while ((line = get_next_line(fd)) != NULL)
	{
		line_count++;
		free(line);
	}
	close(fd);
	map = malloc(sizeof(char *) * line_count + 1);
	if (!map)
		return(NULL);
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return(NULL);
	while ((line = get_next_line(fd)) != NULL)
	{
		map[i] = line;
		i++;
	}
	map[i] = NULL;
	close(fd);
	return(map);
}

int main(int argc, char *argv[])
{
    t_vars	vars;
    if (argc != 2)
    {
        ft_putstr_fd("The number of arguments is invalid", 2);
        exit (1);
    }
    if (ft_strlen(argv[1]) < 4 
            || ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4) != 0)
    {
        ft_putstr_fd("The extension is invalid", 2);
        exit (1);
    }
    //initialize_game(&vars, argv[1]);
    vars.map = read_map(argv[1]);

    /*
    
    parse_map(&program, argv[1]);
    start_game(&program);
    clean(&program);
    }*/

}