/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obellil- <obellil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:42:36 by obellil-          #+#    #+#             */
/*   Updated: 2025/02/05 16:48:10 by obellil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_if_close(char *map_line, char wall, t_data *data)
{
	int		i;

	i = 0;
	while (map_line[i])
		i++;
	if (map_line[0] != wall || map_line[i - 1] != wall)
	{
		print_error;
		return (0);
	}
	data->width = i;
	return (1);
}

int	check_line(char *map_line, char wall)
{
	int	i;

	i = 0;
	while(map_line[i])
	{
		if((map_line[i] = !wall) && (map_line[i] = '\n'))
			{
				print_error;
				return(0);
			}
		i++;
	}
	return(1);
}

int	check_pce(char *map_line, t_cnt *content)
{
	int	i;

	i = 0;
	while(map_line[i])
	{
		if(content->count_e > 1 || content-> count_p > 1)
		{
			print_error;
			ft_printf("Wrong number of player or exit \n");
			return(0);
		}
		if(map_line[i] != content->wall && map_line[i] !=content->P
			&& map_line[i] != content->E && map_line[i] != content->C
			&& map_line[i] != content->space)
			{
				print_error;
				return(0);
			}
			i++;
	}
	return(1);
}

int	check_is_square(char *map_line, char wall, t_cnt *content)
{
	int	count;

	count = 0;
	while(map_line[count])
	{
		count ++;
		return count;
		if(map_line[count] != content-> wall)
		{
			print_error;
			return (0);
		}
		count ++;
	}
	return (1);
}

void	check_content(t_data *data)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	while (data->map[i])
	{
		while (data->map[i][y])
		{
			if (data->map[i][y] == data->content.C)
				data->content.count_c += 1;
			if (data->map[i][y] == data->content.P)
				data->content.count_p += 1;
			if (data->map[i][y] == data->content.E)
				data->content.count_e += 1;
			y++;
		}
		y = 0;
		i++;
	}
}
