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
	int	next_x;

	y = vars->enemies[i].en_y;
	x = vars->enemies[i].en_x;
	next_x = x + vars->enemies[i].direction_x;
	if (next_x >= 0 && next_x < vars->map_width && vars->map[y][next_x] != '1'
		&& vars->map[y][next_x] != 'C' && vars->map[y][next_x] != 'E')
		vars->enemies[i].en_x = next_x;
	else
		vars->enemies[i].direction_x *= -1;
}

void	vertical_walk(t_vars *vars, int i)
{
	int	y;
	int	x;
	int	next_y;

	y = vars->enemies[i].en_y;
	x = vars->enemies[i].en_x;
	next_y = y + vars->enemies[i].direction_y;
	if (next_y >= 0 && next_y < vars->map_height && vars->map[next_y][x] != '1'
		&& vars->map[next_y][x] != 'C' && vars->map[next_y][x] != 'E')
		vars->enemies[i].en_y = next_y;
	else
		vars->enemies[i].direction_y *= -1;
}

void	walking(t_vars *vars, int i)
{
	if (i % 2 == 0)
		horizontal_walk(vars, i);
	else
		vertical_walk(vars, i);
}

int	move_enemy(t_vars *vars)
{
	static int	frame;
	int			i;

	usleep (50000);
	if (frame++ <= 10)
		return (0);
	frame = 0;
	i = -1;
	while (++i < vars->count_enem)
	{
		if (vars->enemies[i].en_y != vars->init_player_y
			|| vars->enemies[i].en_x != vars->init_player_x)
			vars->map[vars->enemies[i].en_y][vars->enemies[i].en_x] = '0';
		walking (vars, i);
		if (vars->enemies[i].en_y == vars->player_y
			&& vars->enemies[i].en_x == vars->player_x)
		{
			you_lose(vars);
			return (0);
		}
		vars->map[vars->enemies[i].en_y][vars->enemies[i].en_x] = 'X';
	}
	return (0);
}
