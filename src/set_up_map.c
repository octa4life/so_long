/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obellil- <obellil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 09:35:13 by octavie           #+#    #+#             */
/*   Updated: 2025/05/07 15:39:51 by obellil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_map(int fd)
{
	char	*line_map;
	char	*buff;
	int		char_count;
	char	*tmp_buff;

	line_map = ft_strdup("");
	buff = ft_strdup("");
	char_count = get_next_line(fd, &line_map);
	if (char_count > 0)
	{
		tmp_buff = buff;
		while (char_count > 0)
		{
			if (line_map[0] == '\0' || line_map[0] == '\n' || line_map[0] == '\t')
			{
				free(line_map);
				free(buff);
				return(NULL);
			}
			buff = ft_strjoin(buff, line_map);
			free(tmp_buff);
			free(line_map);
			line_map = ft_strdup("");
			char_count = get_next_line(fd, &line_map);
			tmp_buff = buff;
		}
		return (buff);
	}
	free(buff);
	print_error("Error : Wrong lecture map\n");
	return (NULL);
}
// reads the entire map file line by line
// and concatenates it into a single string.

char	**parse_map(int fd, t_data *data)
{
	int		i;
	char	*line_map;

	i = 1;
	line_map = get_map(fd);
	if (!line_map)
		return (free(line_map), free_map(data), NULL);
	data->map = ft_split(line_map, '\n');
	free(line_map);
	check_content(data);
	if (!(check_square(data->map)))
		return (free_map(data));
	if (!(check_line(data->map[0], data->content.wall)))
		return (free_map(data));
	while (data->map[i] != NULL)
	{
		if (!(check_wall(data->map[i], data->content.wall, data)))
			return (free_map(data));
		else if (!(check_other(data->map[i++], &(data->content))))
			return (free_map(data));
	}
	data->height = i;
	if (!data->height && !(check_line(data->map[i - 1], data->content.wall)))
		return (free_map(data), NULL);
	if (!check_reachability(data))
		return (free_map(data), NULL);
	return (data->map);
}
// splits the map string into lines, validates the map's structure
// and contents, and sets the map dimensions.

char	**map_core(char **str, t_data *data)
{
	int		fd;

	fd = 0;
	data->map = NULL;
	if (ft_strchr(str[1], ".ber") == 0)
		return (print_error("Error : Need 1 .ber file \n"));
	else
	{
		fd = open(str[1], O_RDONLY);
		if (fd > 0)
			data->map = parse_map(fd, data);
		else
			return (print_error("Error :  Failed to open file\n"));
		if ((data->content.count_c == 0 || data->content.count_e != 1
				|| data->content.count_p != 1) && data->map != NULL)
		{
			free_map(data);
			return (print_error("Error : Need 1 Player/Exit and 1 Object\n"));
		}
	}
	return (data->map);
}
// checks the file extension, opens the map file, parses and validates the map,
// and ensures required elements are present.
