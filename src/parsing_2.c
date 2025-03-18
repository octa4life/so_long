/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obellil- <obellil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 09:15:24 by obellil-          #+#    #+#             */
/*   Updated: 2025/03/18 12:03:35 by obellil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	floodfill(char **tab, t_infra y, t_infra x)
{
	char	**cpy_map;
	int		i;
	int		j;
	int		is_valid;

	cpy_map = copy_tab(tab);
	if (!cpy_map)
		return (false);
	ff(cpy_map, x.x, y.y);
	i = 0;
	is_valid = true;
	while (cpy_map[i] && is_valid)
	{
		j = 0;
		while (cpy_map[i][j] && is_valid)
		{
			if (cpy_map[i][j] == 'C' || cpy_map[i][j] == 'E'
				|| cpy_map[i][j] == 'P')
				is_valid = false;
			j++;
		}
		i++;
	}
	free(cpy_map);
	return (is_valid);
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
			else if (line[i] == 'E')
				count[1]++;
			else if (line[i] == 'P')
				count[2]++;
		}
		free(line);
	}
	close(fd);
	return (count[0] >= 1 && count[1] == 1 && count[2] == 1);
}

char **copy_tab(char **tab)
{
	int		i;
	int		len;
	char	**copy;

	i = 0;
	len = 0;
	while (tab[len])
		len++;
	copy = malloc((len + 1) * sizeof(char *));
	if (!copy)
		return (NULL);
	while (i < len)
	{
		copy[i] = ft_strdup(tab[i]); // Allocate and duplicate the string
		if (!copy[i])
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[len] = NULL;
	return (copy);
}
