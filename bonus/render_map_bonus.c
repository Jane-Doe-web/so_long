/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteudle <esteudle@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:31:14 by esteudle          #+#    #+#             */
/*   Updated: 2025/02/11 18:54:31 by esteudle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

void	set_img(t_vars *vars)
{
	int	tile_size;

	tile_size = TILE_SIZE;
	vars->wall = mlx_xpm_file_to_image(vars->mlx, WALL,
			&tile_size, &tile_size);
	vars->floor = mlx_xpm_file_to_image(vars->mlx, FLOOR,
			&tile_size, &tile_size);
	vars->exit = mlx_xpm_file_to_image(vars->mlx, EXIT,
			&tile_size, &tile_size);
	vars->collect = mlx_xpm_file_to_image(vars->mlx, COLLECT,
			&tile_size, &tile_size);
	vars->player = mlx_xpm_file_to_image(vars->mlx, PLAYER_IDLE,
			&tile_size, &tile_size);
	vars->start = mlx_xpm_file_to_image(vars->mlx, START,
			&tile_size, &tile_size);
	vars->foe = mlx_xpm_file_to_image(vars->mlx, ENEMY,
			&tile_size, &tile_size);
	if (!vars->wall || !vars->floor || !vars->exit
		|| !vars->collect || !vars->player
		|| !vars->start || !vars->foe)
	{
		free_images(vars);
		error_handler("Failed to load images", vars);
	}
}

void	draw_img(t_vars *vars, void *img, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->window, img,
		TILE_SIZE * x, TILE_SIZE * y);
}

void	render_background_and_walls(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			if (vars->map[i][j] == '1')
				draw_img(vars, vars->wall, j, i);
			else
				draw_img(vars, vars->floor, j, i);
			j++;
		}
		i++;
	}
}

void	render_the_rest(t_vars *vars)
{
	int	i;
	int	j;

	draw_img(vars, vars->start, vars->init_player_x, vars->init_player_y);
	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			if (vars->map[i][j] == 'C')
				draw_img(vars, vars->collect, j, i);
			if (vars->map[i][j] == 'E')
				draw_img(vars, vars->exit, j, i);
			if (vars->map[i][j] == 'P')
				draw_img(vars, vars->player, j, i);
			if (vars->map[i][j] == 'X')
				draw_img(vars, vars->foe, j, i);
			j++;
		}
		i++;
	}
}

void	render_map(t_vars *vars)
{
	render_background_and_walls(vars);
	render_the_rest(vars);
}
