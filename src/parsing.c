/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obellil- <obellil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 19:54:25 by obellil-          #+#    #+#             */
/*   Updated: 2025/03/25 13:05:01 by obellil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	openfd(char **argv)
{
	int	fd;

	fd = 0;
	if (argv[1])
	{
		if (ft_strnstr(argv[1], ".ber", 50))
		{
			fd = open(argv[1], O_RDONLY);
			if (fd > 0)
				return(true);
		}
			if (fd < 0)
				return ((print_error("This fd is not compliant")),false);
			else
				return ((print_error("This fd is not compliant"),false));
	}
	return (fd);
}

int	check_square_map(char **argv)
{
	int		fd;
	int		first_line_length;
	int		line_length;
	char	*line;

	fd = openfd(argv);
	if (fd < 0)
		return (false);
	line = get_next_line(fd);
	if (!line)
		return ((close(fd)),(print_error("Empty file or read error.")),false);
	first_line_length = 0;
	while (line[first_line_length] && line[first_line_length] != '\n')
	{
		printf("%s", line);
		first_line_length++;
	}
	free(line);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		line_length = 0;
		while (line[line_length] && line[line_length] != '\n')
		{
			printf("%s", line);
			line_length++;
		}

		if (line_length != first_line_length)
			return ((free(line)),close(fd),(print_error("This map is not a square.")),(false));
		free(line);
	}
	return ((close(fd)),true);
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
