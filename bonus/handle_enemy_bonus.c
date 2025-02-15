/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_enemy_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteudle <esteudle@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 20:19:34 by esteudle          #+#    #+#             */
/*   Updated: 2025/02/15 20:19:41 by esteudle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

void	horizontal_walk(t_vars *vars, int i)
{
	int	y;
	int	x;

	y = vars->enemies[i].en_y;
	x = vars->enemies[i].en_x;
	if (vars->enemies[i].direction_x == 1)
	{
		if (x + 1 < vars->map_width && vars->map[y][x + 1] != '1' 
			&& vars->map[y][x + 1] != 'C' && vars->map[y][x + 1] != 'E' 
			&& (y != vars->init_player_y || x + 1!= vars->init_player_x))
				vars->enemies[i].en_x++;
		else
			vars->enemies[i].direction_x = -1;
	}
	else
	{
		if (vars->map[y][x - 1] != '1' && vars->map[y][x - 1] != 'C'
			&& vars->map[y][x - 1] != 'E' && (y != vars->init_player_y
			|| x - 1 != vars->init_player_x))
				vars->enemies[i].en_x--;
		else
			vars->enemies[i].direction_x = 1;
	}
}
void	vertical_walk(t_vars *vars, int i)
{
	int	y;
	int	x;

	y = vars->enemies[i].en_y;
	x = vars->enemies[i].en_x;
	if (vars->enemies[i].direction_y == 1)
	{
		if (vars->map[y + 1][x] != '1' && vars->map[y + 1][x] != 'C'
			&& vars->map[y + 1][x] != 'E' && (x != vars->init_player_x
			&& y + 1 != vars->init_player_y))
				vars->enemies[i].en_y++;
		else
			vars->enemies[i].direction_y = -1;
	}
	else
	{
		if (vars->map[y - 1][x] != '1' && vars->map[y - 1][x] != 'C'
			&& vars->map[y - 1][x] != 'E' && (x != vars->init_player_x
			&& y - 1 != vars->init_player_y))
				vars->enemies[i].en_y--;
		else
			vars->enemies[i].direction_y = 1;
	}
}

int	move_enemy(t_vars *vars)
{
	usleep (50000);
	static int	frame;
	int	i;

	if (frame++ <= 10)
		return(0);
	frame = 0;
	i = 0;
	while (i < vars->count_enem)
	{
		vars->map[vars->enemies[i].en_y][vars->enemies[i].en_x] = '0';
		if (i % 2 == 0)
			horizontal_walk(vars, i);
		else
			vertical_walk(vars, i);
		vars->map[vars->enemies[i].en_y][vars->enemies[i].en_x] = 'X';
		i++;
	}
	return(0);
}

