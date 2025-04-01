/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obellil- <obellil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 19:54:25 by obellil-          #+#    #+#             */
/*   Updated: 2025/04/01 13:46:19 by obellil-         ###   ########.fr       */
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
			count ++;
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
int	check_obj(char **argv)
{
	int		fd;
	char	*line;
	int		count[3] = {0};
	int		i;

	fd = openfd(argv);
	if (fd < 0) return 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		i = -1;
		while (line[++i])
		{
			if (line[i] == 'C') count[0]++;
			else if (line[i] == 'E') count[1]++;
			else if (line[i] == 'P') count[2]++;
		}
		free(line);
		line = get_next_line(fd); // LECTURE DE LA LIGNE SUIVANTE AJOUTÉE
	}
	close(fd);
	return (count[0] >= 1 && count[1] == 1 && count[2] == 1);
}
