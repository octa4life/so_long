/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obellil- <obellil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 19:54:25 by obellil-          #+#    #+#             */
/*   Updated: 2025/02/09 21:11:12 by obellil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	openfd(char **argv)
{
	int	fd;

	fd = 0;
	if (argv[1])
	{
		if (ft_strnstr(argv[1] ,".ber", 15))
		{
			fd = open(argv[1],O_RDONLY);
			if (fd < 0)
				return (0);
		}
		else
		{
			print_error();
			return (0);
		}

	}
	return (0);
}

int	gnlfd(char **argv)
{
	int		count;
	int		fd;
	char	*line;
	char	*all;

	count = 0;
	line = get_next_line(fd);
	fd = openfd(argv);
	if (argv[1] && fd > 0)
	{
		while (*line != NULL)
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
	return (count);
}

int	check_close(char **argv)
{
	char	*line;
	int		count;
	int		fd;
	int		start;
	int		countline;

	count = 0;
	fd = openfd(argv);
	if (argv[1])
	{
	*line = get_next_line(fd);
		while (*line != NULL)
		{
			count++;
			countline ++;
			start = count -1;
			if(countline == '\n')
			{
				if (start[line] == '0' && countline == '0')
					return (0);
				if (start[line] == '1' && countline == '0')
					return (1);
			}
		}
	}
}

int	check_obj(char **argv)
{
	int		fd;
	char	*line;
	int		count[3];
	int		i;

	count[0] = 0;
	count[1] = 0;
	count[2] = 0;
	fd = openfd(argv);
	while ((line = get_next_line(fd)))
	{
		i = -1;
		while (line[++i])
			if (line[i] == 'C')
				count[0]++;
			else if (line[i] == 'E')
				count[1]++;
			else if (line[i] == 'P')
				count[2]++;
		free(line);
	}
	close(fd);
	return (count[0] >= 1 && count[1] == 1 && count[2] == 1);
}
