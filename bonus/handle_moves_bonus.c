/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteudle <esteudle@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:29:32 by esteudle          #+#    #+#             */
/*   Updated: 2025/02/11 18:34:10 by esteudle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

void	you_win(t_vars *vars)
{
	ft_putstr_fd("You won! 🔥🔥🔥\n", 1);
	ft_putstr_fd("This is S9 to Berghain!\n", 1);
	ft_putstr_fd("Zurück bleiben, bitte!\n", 1);
	exit_function(vars);
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
	if (vars->map[upd_y][upd_x] != '1'
		&& vars->map[upd_y][upd_x] != 'E')
	{
		vars->map[vars->player_y][vars->player_x] = '0';
		vars->player_y = upd_y;
		vars->player_x = upd_x;
		vars->map[upd_y][upd_x] = 'P';
		render_map(vars);
		vars->steps++;
		ft_putstr_fd("Number of steps:", 1);
		ft_printf("%d\n", vars->steps);
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
