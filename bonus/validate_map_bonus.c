/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteudle <esteudle@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:31:46 by esteudle          #+#    #+#             */
/*   Updated: 2025/02/11 19:39:50 by esteudle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

void	process_count_cpe(t_vars *vars)
{
	if (vars->count_collect < 1)
		error_handler("Nothing to collect");
	if (vars->count_player != 1)
		error_handler("No player or more than 1 player");
	if (vars->count_exit != 1)
		error_handler("No exit or more than 1 exit");
}

void	if_characters_collectibles_player_exit(t_vars *vars)
{
	char	c;

	vars->y = 0;
	while (vars->map[vars->y])
	{
		vars->x = 0;
		while (vars->map[vars->y][vars->x])
		{
			c = vars->map[vars->y][vars->x];
			if (c != 'C' && c != 'P' && c != 'E' && c != '0' && c != '1')
				error_handler("There is an unknown character");
			if (c == 'C')
				vars->count_collect++;
			if (c == 'P')
				vars->count_player++;
			if (c == 'E')
				vars->count_exit++;
			vars->x++;
		}
		vars->y++;
	}
	process_count_cpe(vars);
}

int	if_walls_rectangular(t_vars *vars)
{
	int	bottom_max;

	bottom_max = vars->map_height - 1;
	while (vars->y < vars->map_height - 1)
	{
		if (ft_strlen(vars->map[vars->y]) != ft_strlen(vars->map[vars->y + 1]))
			error_handler("Not rectangular");
		vars->y++;
	}
	while (vars->map[0][vars->x] && vars->map[bottom_max][vars->x])
	{
		if (vars->map[0][vars->x] != '1'
			|| vars->map[bottom_max][vars->x] != '1')
			error_handler("Upper or bottom wall has a hole");
		vars->x++;
	}
	vars->y = 0;
	while (vars->y < vars->map_height)
	{
		if (vars->map[vars->y][0] != '1'
			|| vars->map[vars->y][vars->x - 1] != '1')
			error_handler("Right or left wall has a hole");
		vars->y++;
	}
	return (vars->x);
}

void	validate_map(t_vars *vars)
{
	vars->map_width = if_walls_rectangular(vars);
	if_characters_collectibles_player_exit(vars);
	if_possible_to_win(vars);
}
