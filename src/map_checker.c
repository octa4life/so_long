/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obellil- <obellil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 19:54:25 by obellil-          #+#    #+#             */
/*   Updated: 2025/04/02 16:06:33 by obellil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_square_map(char **map)
{
	int		y;
	int		x;
	int		count_x;

	if (!map || !map[0])
		return (print_error("Error\nMap is NULL or empty\n"));
	count_x = 0;
	while (map[0][count_x])
		count_x++;
	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x])
			x++;
		if (x != count_x)
			return (print_error("Error\nMap must be a rectangle or a square\n"));
		y++;
	}
	return(1);
}

int	check_col(char *map_line, char wall, t_data *data)
{
	int		i;

	i = 0;
	while (map_line[i])
		i++;
	if (map_line[0] != wall || map_line[i - 1] != wall)
	{
		print_error("Error\nMap column not close\n");
		return (0);
	}
	data->width = i;
	return (1);
}

int	check_line(char *map_line, char wall)
{
	int		i;

	i = 0;
	while (map_line[i])
	{
		if (map_line[i] != wall)
		{
			print_error("Error\nMap line not close\n");
			return (0);
		}
		i++;
	}
	return (1);
}

void	check_obj(t_data *data)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	while (data->map[i])
	{
		while (data->map[i][y])
		{
			if (data->map[i][y] == data->content.collect)
				data->content.count_c += 1;
			if (data->map[i][y] == data->content.player)
				data->content.count_p += 1;
			if (data->map[i][y] == data->content.exit)
				data->content.count_e += 1;
			y++;
		}
		y = 0;
		i++;
	}
}

int	check_other_obj(char *map_line, t_texture*content)
{
	int		i;

	i = 0;
	while (map_line[i])
	{
		if (content->count_e > 1 || content->count_p > 1)
		{
			print_error("Error\nWrong number of player or exit\n");
			return (0);
		}
		if (map_line[i] != content->wall && map_line[i] != content->player
			&& map_line[i] != content->exit && map_line[i] != content->collect
			&& map_line[i] != content->space)
		{
			print_error("Error\nUnknown symbol(s) in map\n");
			return (0);
		}
		i++;
	}
	return (1);
}


