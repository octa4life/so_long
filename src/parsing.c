/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obellil- <obellil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:42:36 by obellil-          #+#    #+#             */
/*   Updated: 2025/02/06 12:48:12 by obellil-         ###   ########.fr       */
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
	line = 0;
	fd = openfd(argv);
	if (argv[1] && fd > 0)
	{
		while ((*line = (get_next_line(fd)) != NULL))
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
