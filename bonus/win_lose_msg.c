/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_lose_msg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteudle <esteudle@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 20:19:06 by esteudle          #+#    #+#             */
/*   Updated: 2025/02/15 20:19:13 by esteudle         ###   ########.fr       */
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

void	you_lose(t_vars *vars)
{
	ft_putstr_fd("Tut mir leid!!!💩💩💩\n", 1);
	ft_putstr_fd("You stepped into the poop!\n", 1);
	ft_putstr_fd("No Berghain today! Go home and wash your shoes!\n", 1);
	exit_function(vars);
}
