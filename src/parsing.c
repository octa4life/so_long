/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obellil- <obellil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 19:54:25 by obellil-          #+#    #+#             */
/*   Updated: 2025/02/11 15:12:12 by obellil-         ###   ########.fr       */
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
			printf("%d", fd);
			if (fd < 0)
				return (1);
		}
		else
		{
			print_error();
			return (0);
		}
	}
	return (fd);
}

void	init_struct(t_infra *data, char *fd)
{
	if (!data)
		return ;
	data->map = fill_map(fd);
}

char	**fill_map(char *fd, char **argv)
{
	char	*line;
	char	**map;
	int		i;

	fd = openfd(argv);
	if (fd < 0)
		return (NULL);
	if (argv[1] && fd > 0)
	{
		map = malloc(sizeof(char *) * 1000);
		if (!map)
		{
			close(fd);
			return (NULL);
		}
		i = 0;
		line = get_next_line(fd);
		while (line != NULL)
		{
			if (i >= 1000)
				break ;
			map[i++] = line;
		}
		map[i] = NULL;
		close(fd);
	}
		return (map);
}

int	gnlfd(char **argv)
{
	int		count;
	int		fd;
	char	*line;
	char	*all;

	fd = 0;
	count = 0;
	line = get_next_line(fd);
	fd = openfd(argv);
	if (argv[1] && fd > 0)
	{
		while (line != NULL)
		{
			count++;
			all = line;
			if (line == all)
				return (1);
			else
				return (0);
			free(line);
		}
		close(fd);
	}
	return (fd);
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

