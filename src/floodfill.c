/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obellil- <obellil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:04:57 by obellil-          #+#    #+#             */
/*   Updated: 2025/05/08 10:45:52 by obellil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map_array(char **map)
{
	int	i;

	i = 0;
	while (map && map[i])
		free(map[i++]);
	free(map);
}

char	**dup_map(char **map)
{
	int		i;
	char	**new_map;

	i = 0;
	while (map[i])
		i++;
	new_map = malloc(sizeof(char *) * (i + 1));
	if (!new_map)
		return (NULL);
	i = 0;
	while (map[i])
	{
		new_map[i] = ft_strdup(map[i]);
		if (!new_map[i])
			return (free_map_array(new_map), NULL);
		i++;
	}
	new_map[i] = NULL;
	return (new_map);
}

int	find_player_pos(char **map, int *x, int *y)
{
	*y = 0;
	while (map[*y])
	{
		*x = 0;
		while (map[*y][*x])
		{
			if (map[*y][*x] == 'P')
				return (1);
			(*x)++;
		}
		(*y)++;
	}
	return (0);
}

int	check_reachability(t_data *data)
{
	int		x;
	int		y;
	char	**map_copy;

	if (!find_player_pos(data->map, &x, &y))
		return (print_error("Error : Player not found\n"), 0);
	map_copy = dup_map(data->map);
	if (!map_copy)
		return (print_error("Error : Map duplication failed\n"), 0);
	flood_fill(map_copy, x, y);
	y = -1;
	while (map_copy[++y])
	{
		x = -1;
		while (map_copy[y][++x])
			if (map_copy[y][x] == 'C')
				return (print_error(ERROR_C_E), free_map_array(map_copy), 0);
	}
	return (free_map_array(map_copy), 1);
}

void	flood_fill(char **map, int x, int y)
{
	if (!map[x] || map[x][y] == '\0')
		return ;
	if (map[x][y] == 'E' || map[x][y] == 'X' || map[x][y] == '1')
		return ;
	if (map[x][y] == '0' || map[x][y] == 'C' || map[x][y] == 'P')
		map[x][y] = 'X';
	if (map[x + 1] && map[x + 1][y] != '\0')
		flood_fill(map, x + 1, y);
	if (x > 0 && map[x - 1] && map[x - 1][y] != '\0')
		flood_fill(map, x - 1, y);
	if (map[x] && map[x][y + 1] != '\0')
		flood_fill(map, x, y + 1);
	if (map[x] && y > 0 && map[x][y - 1] != '\0')
		flood_fill(map, x, y - 1);
}
