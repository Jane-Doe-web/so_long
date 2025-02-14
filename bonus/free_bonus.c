/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteudle <esteudle@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:28:20 by esteudle          #+#    #+#             */
/*   Updated: 2025/02/11 18:31:55 by esteudle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

void	free_images(t_vars *vars)
{
	if (vars->wall)
		mlx_destroy_image(vars->mlx, vars->wall);
	if (vars->floor)
		mlx_destroy_image(vars->mlx, vars->floor);
	if (vars->exit)
		mlx_destroy_image(vars->mlx, vars->exit);
	if (vars->collect)
		mlx_destroy_image(vars->mlx, vars->collect);
	if (vars->player)
		mlx_destroy_image(vars->mlx, vars->player);
	if (vars->start)
		mlx_destroy_image(vars->mlx, vars->start);
}

void	exit_function(t_vars *vars)
{
	free_images(vars);
	if (vars->window != NULL)
		mlx_destroy_window(vars->mlx, vars->window);
	vars->window = NULL;
	if (vars->mlx)
	{
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		vars->mlx = NULL;
	}
	if (vars->map != NULL)
	{
		free_map(vars->map, vars->map_height);
		vars->map = NULL;
	}
	exit(EXIT_SUCCESS);
}
