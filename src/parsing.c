/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obellil- <obellil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 19:54:25 by obellil-          #+#    #+#             */
/*   Updated: 2025/03/19 16:50:52 by obellil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	openfd(char **argv)
{
	int	fd;

	fd = 0;
	if (argv[1])
	{
		while (ft_strnstr(argv[2], ".ber", 15))
		{
			fd = open(argv[1], O_RDONLY);
			if (fd > 0)
				return (print_error("This folder can be open \n"),true);
			else
				return ((print_error("test")),false);
		}
	}
	return (fd);
}

int	check_square_map(char **argv)
{
	int		fd;
	int		line_len;
	int		cur_len;
	char	*line;

	fd = openfd(argv);
	if (fd < 0)
		return (print_error("Error : this folder can't be open \n"), 0);
	line = get_next_line(fd);
	if (!line)
		return (close(fd), print_error("Error : this folder is empty \n "), 0);
	line_len = get_line_length(line);
	while (line)
	{
		cur_len = get_line_length(line);
		free(line);
		if (cur_len != line_len)
			return (close(fd), print_error("Error : This map is not a square \n"), 0);
		line = get_next_line(fd);
	}
	return (close(fd), 1);
}

int	check_close(char **argv)
{
	char	*line;
	int		count;
	int		fd;
	int		start;
	int		countline;

	countline = 0;
	count = 0;
	fd = openfd(argv);
	if (argv[1])
	{
		line = get_next_line(fd);
		while (line != NULL)
		{
			count++;
			countline ++;
			start = count -1;
			if (countline == '\n' && start[line] == '0' && countline == '0')
				return (free(line),print_error("This map is not close"),0);
			if (countline == '\n' && start[line] == '1' && countline == '0')
				return (free(line), 1);
		}
		close(fd);
	}
	return (count);
}
