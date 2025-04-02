/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obellil- <obellil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 19:55:08 by obellil-          #+#    #+#             */
/*   Updated: 2025/04/02 16:24:58 by obellil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**open_fd(char **str, t_data *data)
{
	int		fd;

	fd = 0;
	data->map = NULL;
	if (!ft_strnstr(str[1], ".ber", ft_strlen(str[1])))
		return (print_error("Error\nNo correct format map found\n"), NULL);
	else
	{
		fd = open(str[1], O_RDONLY);
		if (fd > 0)
			data->map = parse_map(fd, data);
		else
			return (print_error("Error\nFailed to open file\n"), NULL);
		if ((data->content.count_c == 0 || data->content.count_e != 1
				|| data->content.count_p != 1) && data->map != NULL)
		{
			free_map(data);
			return (print_error("Error\nNeed 1 Player/Exit and at least 1 Object\n"), NULL);
		}
	}
	return (data->map);
}
char	*get_map(int fd)
{
	char	*line_map;
	char	*buff;
	int		char_count;
	char	*tmp_buff;

	line_map = ft_strdup("");
	buff = ft_strdup("");
	char_count = get_next_line(fd);
	if (char_count > 0)
	{
		tmp_buff = buff;
		while (char_count > 0)
		{
			buff = ft_strjoin(buff, line_map);
			free(tmp_buff);
			free(line_map);
			line_map = ft_strdup("");
			char_count = get_next_line(fd);
			tmp_buff = buff;
		}
		return (buff);
	}
	print_error("Error\nWrong lecture map\n");
	return (NULL);
}

void	*free_map(t_data *data)
{
	int		i;

	i = 0;
	while (data->map[i] != NULL)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	data->map = NULL;
	return (0);
}
char	**parse_map(int fd, t_data *data)
{
	int		i;

	i = 1;
	data->map = ft_split(get_map(fd), '\n');
	check_content(data);
	if (!(open_fd(data->map)))
		return (free_map(data));
	if (!(check_line(data->map[0], data->content.wall)))
		return (free_map(data));
	while (data->map[i] != NULL)
	{
		if (!(check_col(data->map[i], data->content.wall, data)))
			return (free_map(data));
		else if (!(check_other_obj(data->map[i], &(data->content))))
			return (free_map(data));
		i++;
	}
	data->height = i;
	if (!(check_line(data->map[i - 1], data->content.wall)))
		return (free_map(data));
	return (data->map);
}

int	print_error(char *mess)
{
	ft_printf("%s\n", mess);
	exit (1);
}
