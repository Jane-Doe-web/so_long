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

void	error_handler(char *str, t_vars *vars)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd(str, 1);
	if (vars->map)
	{
		free_map(vars->map, vars->map_height);
		vars->map = NULL;
	}
	if (vars->copy_map)
	{
		free_map(vars->copy_map, vars->map_height);
		vars->copy_map = NULL;
	}
	exit (1);
}

void	start_game_window(t_vars *vars)
{
	int	x;
	int	y;
	int	screen_width;
	int	screen_height;

	vars->mlx = mlx_init();
	if (!vars->mlx)
		error_handler("Failed to initialize minilibx", vars);
	mlx_get_screen_size(vars->mlx, &screen_width, &screen_height);
	x = vars->map_width * TILE_SIZE;
	y = vars->map_height * TILE_SIZE;
	if (x > screen_width || y > screen_height)
	{
		exit_function(vars);
		ft_printf("Map is too big for this screen", vars);
	}
	vars->window = mlx_new_window(vars->mlx, x, y, "Berlin");
	if (!vars->window)
		error_handler("Failed to create window", vars);
}

int	main(int argc, char *argv[])
{
	t_vars	vars;

	if (argc != 2)
	{
		printf("Error\nThe number of args is invalid");
		exit (1);
	}
	if (ft_strlen(argv[1]) < 4
		|| ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4) != 0)
	{
		printf("Error\nThe extension is invalid");
		exit (1);
	}
	ft_memset(&vars, 0, sizeof(t_vars));
	vars.map = read_map(argv[1], &vars);
	if (!vars.map)
		error_handler("Cannot load the map", &vars);
	validate_map(&vars);
	start_game_window(&vars);
	set_img(&vars);
	render_map (&vars);
	mlx_hook(vars.window, 2, 1L << 0, &handle_key, &vars);
	mlx_hook(vars.window, 17, 0, &handle_exit, &vars);
	mlx_loop(vars.mlx);
}
