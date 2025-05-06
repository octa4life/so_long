/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obellil- <obellil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 09:35:13 by octavie           #+#    #+#             */
/*   Updated: 2025/05/06 15:46:45 by obellil-         ###   ########.fr       */
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
			buff = ft_strjoin(buff, line_map);
			free(tmp_buff);
			free(line_map);
			line_map = ft_strdup("");
			char_count = get_next_line(fd, &line_map);
			tmp_buff = buff;
		}
		return (buff);
	}
	print_error("Error : Wrong lecture map\n");
	return (NULL);
}

char	**map_check(char **str, t_data *data)
{
	int	fd;

	data->map = NULL;
	if (!ft_strchr(str[1], ".ber"))
		return (print_error("Error : Invalid map format\n"));
	fd = open(str[1], O_RDONLY);
	if (fd < 0)
		return (print_error("Error : Can't open map\n"));
	data->map = parse_map(fd, data);
	close(fd);
	if (!data->map)
		return (NULL);
	check_content(data);
	if (data->content.count_c < 1 || data->content.count_e != 1
		|| data->content.count_p != 1)
	{
		free_map(data);
		return (print_error("Error : Invalid map components\n"));
	}
	return (data->map);
}
