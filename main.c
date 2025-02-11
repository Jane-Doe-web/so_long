/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteudle <esteudle@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:29:59 by esteudle          #+#    #+#             */
/*   Updated: 2025/02/11 18:39:04 by esteudle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	error_handler(char *str)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd(str, 1);
	exit (1);
}

void	initialize_game(t_vars *vars)
{
	vars->map_height = 0;
	vars->map_width = 0;
	vars->x = 0;
	vars->y = 0;
	vars->count_collect = 0;
	vars->count_player = 0;
	vars->count_exit = 0;
	vars->exit_flag = 0;
	vars->reachable_collect = 0;
	vars->steps = 0;
	vars->mlx = NULL;
	vars->window = NULL;
	vars->wall = NULL;
	vars->floor = NULL;
	vars->player = NULL;
	vars->exit = NULL;
	vars->start = NULL;
	vars->collect = NULL;
	vars->img = NULL;
	vars->map = NULL;
	vars->player_y = 0;
	vars->player_x = 0;
	vars->init_player_y = 0;
	vars->init_player_x = 0;
}

void	start_game_window(t_vars *vars)
{
	int	x;
	int	y;

	vars->mlx = mlx_init();
	if (!vars->mlx)
		error_handler("Failed to initialize minilibx");
	x = vars->map_width * TILE_SIZE;
	y = vars->map_height * TILE_SIZE;
	vars->window = mlx_new_window(vars->mlx, x, y, "so_long");
	if (!vars->window)
		error_handler("Failed to create window");
}

int	main(int argc, char *argv[])
{
	t_vars	vars;

	if (argc != 2)
		error_handler("The number of args is invalid");
	if (ft_strlen(argv[1]) < 4 
		|| ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4) != 0)
		error_handler("The extension is invalid");
	initialize_game(&vars);
	vars.map = read_map(argv[1], &vars);
	if (!vars.map)
		error_handler("Cannot load the map");
	validate_map(&vars);
	start_game_window(&vars);
	set_img(&vars);
	render_map (&vars);
	mlx_hook(vars.window, 2, 1L << 0, &handle_key, &vars);
	mlx_hook(vars.window, 17, 0, &handle_exit, &vars);
	mlx_loop(vars.mlx);
}
