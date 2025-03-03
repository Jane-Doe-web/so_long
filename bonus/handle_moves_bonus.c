/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_moves_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteudle <esteudle@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:29:32 by esteudle          #+#    #+#             */
/*   Updated: 2025/02/18 14:42:10 by esteudle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

int	game_loop(void *param)
{
	t_vars	*vars;

	vars = (t_vars *)param;
	move_enemy(vars);
	render_map(vars);
	put_steps_to_the_window(vars);
	return (0);
}

void	put_steps_to_the_window(t_vars *vars)
{
	char	*str;
	char	*steps_str;
	int		x;
	int		y;

	mlx_set_font(vars->mlx, vars->window, "10x20");
	steps_str = ft_itoa(vars->steps);
	str = ft_strjoin("Number of steps: ", steps_str);
	y = vars->map_height * TILE_SIZE - TILE_SIZE / 2;
	x = vars->map_width * TILE_SIZE / 4;
	mlx_string_put(vars->mlx, vars->window, x, y, 0x000000, str);
	free(str);
	free(steps_str);
}

void	move_player(t_vars *vars, int i, int j)
{
	int	upd_y;
	int	upd_x;

	upd_y = vars->player_y + i;
	upd_x = vars->player_x + j;
	if (vars->map[upd_y][upd_x] == 'C')
		vars->count_collect--;
	if (vars->map[upd_y][upd_x] == 'E'
		&& vars->count_collect == 0)
		you_win(vars);
	if (vars->map[upd_y][upd_x] == 'X')
		you_lose(vars);
	if (vars->map[upd_y][upd_x] != '1')
	{
		if (vars->player_y == vars->exit_y && vars->player_x == vars->exit_x)
			vars->map[vars->player_y][vars->player_x] = 'E';
		else
			vars->map[vars->player_y][vars->player_x] = '0';
		vars->player_y = upd_y;
		vars->player_x = upd_x;
		vars->map[upd_y][upd_x] = 'P';
		render_map(vars);
		vars->steps++;
	}
}

int	handle_key(int keysym, t_vars *vars)
{
	if (keysym == XK_w)
		move_player(vars, -1, 0);
	if (keysym == XK_s)
		move_player(vars, 1, 0);
	if (keysym == XK_a)
		move_player(vars, 0, -1);
	if (keysym == XK_d)
		move_player(vars, 0, 1);
	if (keysym == XK_Escape)
		exit_function(vars);
	return (0);
}

int	handle_exit(t_vars *vars)
{
	exit_function(vars);
	return (0);
}
