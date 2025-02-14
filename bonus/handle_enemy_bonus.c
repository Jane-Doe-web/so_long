#include "so_long_bonus.h"
int	can_walk_horizontally(t_vars *vars, int i)
{
	if (vars->enemies[i].en_x + 1 != '1')
		return(1);
	return(0);
}
int	can_walk_vertically(t_vars *vars, int i)
{
	if (vars->enemies[i].en_y + 1 != '1')
		return(1);
	return(0);
}
void	change_direction(t_vars *vars, int i)
{
	while (vars->enemies[i].en_x - 1 != '1')
		vars->enemies[i].en_x--;
}
void	move_enemy(t_vars *vars)
{
	static int	frame;
	int	i;

	frame = 0;
	if (frame++ > 10)
		return(0);
	frame = 0;
	i = 0;
	while (vars->enemies[i++] && i < vars->count_enem)
	{
		if (i % 2 == 0)
		{
			if (can_walk_horizontally(vars, i))
				vars->enemies[i].en_x++;
			else
				change_direction(vars, i);
		}
	}
}