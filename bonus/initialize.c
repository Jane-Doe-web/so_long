/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteudle <esteudle@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 20:18:44 by esteudle          #+#    #+#             */
/*   Updated: 2025/02/15 20:18:57 by esteudle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

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
	vars->count_enem = 0;
}

void	initialize_enemy_direction(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->count_enem)
	{
		vars->enemies[i].direction_x = 1;
		vars->enemies[i].direction_y = 1;
		i++;
	}
}

void	initialize_enemies(t_vars *vars)
{
	int	i;
	
	vars->y = 0;
	i = 0;
	vars->enemies = malloc(sizeof(t_enemy) * vars->count_enem);
	if (!vars->enemies)
		exit(1);
	while (vars->map[vars->y])
	{
		vars->x = 0;
		while (vars->map[vars->y][vars->x])
		{
			if (vars->map[vars->y][vars->x] == 'X')
			{
				vars->enemies[i].en_y = vars->y;
				vars->enemies[i].en_x = vars->x;
				i++;
			}
			vars->x++;
		}
		vars->y++;
	}
	initialize_enemy_direction(vars);
}
