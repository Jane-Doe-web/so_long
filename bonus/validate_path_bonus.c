/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteudle <esteudle@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:32:25 by esteudle          #+#    #+#             */
/*   Updated: 2025/02/11 19:45:29 by esteudle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

void	free_map(char **map, int height)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (i < height)
	{
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
}

char	**duplicate_map(t_vars *vars)
{
	char	**copy_map;
	int		i;

	i = 0;
	copy_map = malloc(sizeof(char *) * (vars->map_height + 1));
	if (!copy_map)
		return (NULL);
	while (i < vars->map_height)
	{
		copy_map[i] = ft_strdup(vars->map[i]);
		if (!copy_map[i])
		{
			free_map(copy_map, i);
			copy_map = NULL;
			return (NULL);
		}
		i++;
	}
	copy_map[i] = NULL;
	return (copy_map);
}

void	fill(t_vars *vars, char target, int row, int col)
{
	if (row < 0 || col < 0 || row >= vars->map_height || col >= vars->map_width)
		return ;
	if (vars->copy_map[row][col] == 'A' || vars->copy_map[row][col] == '1')
		return ;
	if (vars->copy_map[row][col] == 'C')
	{
		vars->reachable_collect++;
		vars->copy_map[row][col] = '0';
	}
	if (vars->copy_map[row][col] == 'E')
	{
		vars->exit_flag = 1;
		vars->exit_y = row;
		vars->exit_x = col;
		vars->copy_map[row][col] = '0';
	}
	vars->copy_map[row][col] = 'A';
	fill(vars, target, row - 1, col);
	fill(vars, target, row + 1, col);
	fill(vars, target, row, col - 1);
	fill(vars, target, row, col + 1);
}

void	flood_fill(char **map, t_vars *vars)
{
	int		i;
	int		j;
	char	target;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != 'P')
			j++;
		if (map[i][j] == 'P')
			break ;
		i++;
	}
	vars->player_y = i;
	vars->player_x = j;
	vars->init_player_y = i;
	vars->init_player_x = j;
	map[i][j] = '0';
	target = map[i][j];
	fill(vars, target, i, j);
	if (vars->reachable_collect != vars->count_collect)
		error_handler("Collectibles are not reachable", vars);
	if (!vars->exit_flag)
		error_handler("Exit is not reachable", vars);
}

void	if_possible_to_win(t_vars *vars)
{
	vars->copy_map = NULL;
	vars->copy_map = duplicate_map(vars);
	if (vars->copy_map)
	{
		flood_fill(vars->copy_map, vars);
		free_map (vars->copy_map, vars->map_height);
	}
}
