#include "so_long.h"

void	error_handler(char *str)
{
	ft_putstr_fd(str, 2);
	exit (1);
}
void	initialize_game(t_vars *vars, char *argv)
{
	vars->map_height = 0;
	vars->map_width = 0;
	vars->x = 0;
	vars->y = 0;
	vars->count_collect = 0;
	vars->count_player = 0;
	vars->count_exit = 0;
}
int	main(int argc, char *argv[])
{
	t_vars vars;
	
	if (argc != 2)
		error_handler("The number of arguments is invalid");
	if (ft_strlen(argv[1]) < 4 || ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4) != 0)
		error_handler("The extension is invalid");
	initialize_game(&vars, argv[1]);
	vars.map = read_map(argv[1], &vars);
	if (!vars.map)
		error_handler("Cannot load the map");
	vars.count_collect = validate_map(&vars);

    // Debug: Print map to check if it loads correctly
    int i = 0;
    while (vars.map[i])
    {
        printf("%s\n", vars.map[i]);
        free(vars.map[i]);  
        i++;
    }
    free(vars.map);  
}
