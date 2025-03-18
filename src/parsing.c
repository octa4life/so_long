/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obellil- <obellil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 19:54:25 by obellil-          #+#    #+#             */
/*   Updated: 2025/03/18 17:14:45 by obellil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	openfd(char **argv)
{
	int	fd;

	fd = 0;
	if (argv[1])
	{
		if (ft_strnstr(argv[1], ".ber", 15))
		{
			fd = open(argv[1], O_RDONLY);
			if (fd < 0)
				return (1);
		}
		else
		{
			print_error("ui");
			return (0);
		}
	}
	return (fd);
}

void init_struct(t_infra *data, char **argv)
{
	data->map = fill_map(argv);
	if (!data->map)
	{
		perror("Error initializing map");
		exit(EXIT_FAILURE);
	}
}

char **fill_map(char **argv)
{
	int fd;
	char *line;
	char **map = NULL;

	fd = open(argv[1], O_RDONLY);
	if (fd <= 0) {
		perror("Error opening file");
		return NULL;
	}
	while ((line = get_next_line(fd)) != NULL)
		free(line);
	close(fd);
	return map;
}

int	gnlfd(char **argv)
{
	int		fd;
	int		count;
	char	*line;

	fd = openfd(argv);
	if (fd < 0)
		return (printf("Erreur d'ouverture du fichier\n"), -1);
	count = 0;
	while ((line = get_next_line(fd)))
	{
		count++;
		free(line);
	}
	close(fd);
	printf("Nombre de lignes : %d\n", count);
	return (count);
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
				return (free(line),0);
			if (countline == '\n' && start[line] == '1' && countline == '0')
				return (free(line), 1);
		}
		close(fd);
	}
	return (count);
}

