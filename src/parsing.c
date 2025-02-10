/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obellil- <obellil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 19:54:25 by obellil-          #+#    #+#             */
/*   Updated: 2025/02/10 15:03:30 by obellil-         ###   ########.fr       */
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
			while (countline == '\n' && start[line] == '0' && countline == '0')
				return (0);
			while (countline == '\n' && start[line] == '1' && countline == '0')
				return (1);
			free(line);
		}
		close(fd);
	}
	return count;
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
	line = get_next_line(fd);
	while (line != NULL)
	{
		i = -1;
		while (line[++i])
		{
			if (line[i] == 'C')
				count[0]++;
			else if (line[i] == 'E' || line[i] == 'P')
				count[1]++;
			else if (line[i] == 'P')
				count[2]++;
		}
		free(line);
	}
	close(fd);
	return (count[0] >= 1 && count[1] == 1 && count[2] == 1);
}

void	ff(char **tab, int x, int y)
{
	if (y < 0 || x < 0 || !tab[y] || !tab[y][x] ||
		tab[y][x] == '1' || tab[y][x] == 'V' || tab[y][x] == '\n')
		return ;
	tab[y][x] = 'V';
	ff(tab, x + 1, y);
	ff(tab, x - 1, y);
	ff(tab, x, y + 1);
	ff(tab, x, y - 1);
}
