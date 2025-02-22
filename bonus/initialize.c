/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteudle <esteudle@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 20:18:44 by esteudle          #+#    #+#             */
/*   Updated: 2025/02/18 14:42:45 by esteudle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

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
