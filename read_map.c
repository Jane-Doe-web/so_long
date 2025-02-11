/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteudle <esteudle@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:30:35 by esteudle          #+#    #+#             */
/*   Updated: 2025/02/11 18:45:46 by esteudle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	open_map_file(char *map_path)
{
	int		fd;
	char	buffer[1];

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		error_handler("Failed to open map file");
	if (read(fd, buffer, 1) == 0)
	{
		close(fd);
		error_handler("Map file is empty");
	}
	close(fd);
	return (open(map_path, O_RDONLY));
}

char	*trim_line(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (line[len - 1] == '\n')
		line[len - 1] = '\0';
	return (line);
}

char	**read_map(char *map_path, t_vars *vars)
{
	int		fd;
	char	**map;
	char	*line;

	fd = open_map_file (map_path);
	while ((line = get_next_line(fd)) != NULL)
	{
		vars->map_height++;
		free(line);
	}
	close(fd);
	map = malloc(sizeof(char *) * (vars->map_height + 1));
	if (!map)
		return (NULL);
	fd = open_map_file (map_path);
	vars->map_height = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		map[vars->map_height] = line;
		trim_line(line);
		vars->map_height++;
	}
	map[vars->map_height] = NULL;
	close(fd);
	return (map);
}
