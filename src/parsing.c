/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octavie <octavie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 09:15:24 by obellil-          #+#    #+#             */
/*   Updated: 2025/05/05 09:34:17 by octavie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	check_col(char *map_line, char wall, t_data *data)
{
    int		i;
    
	i = 0;
	while (map_line[i])
    i++;
	if (map_line[0] != wall || map_line[i - 1] != wall)
	{
        print_error("Error : Map column not close\n");
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
            print_error("Error : Map line not close\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_other(char *map_line, t_cnt *content)
{
    int		i;
    
	i = 0;
	while (map_line[i])
	{
        if (content->count_e > 1 || content->count_p > 1)
		{
            ft_error("Error : Wrong number of player or exit\n");
			return (0);
		}
		if (map_line[i] != content->wall && map_line[i] != content->player
			&& map_line[i] != content->exit && map_line[i] != content->collect
			&& map_line[i] != content->space)
            {
                print_error("Error : Unknown symbol(s) in map\n");
                return (0);
            }
            i++;
        }
    return (1);
}
char	**parse_map(int fd, t_data *data)
{
     int	i;
    
    i = 1;
    data->map = ft_split(get_map(fd), '\n');
    check_content(data);
    if (!(check_format(data->map)))
        return (free_map(data));
    if (!(check_line(data->map[0], data->content.wall)))
        return (free_map(data));
    while (data->map[i] != NULL)
    {
        if (!(check_col(data->map[i], data->content.wall, data)))
            return (free_map(data));
        else if (!(check_other(data->map[i], &(data->content))))
            return (free_map(data));
        i++;
    }
    data->height = i;
    if (!(check_line(data->map[i - 1], data->content.wall)))
        return (free_map(data));
    return (data->map);
}