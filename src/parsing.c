/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obellil- <obellil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 19:54:25 by obellil-          #+#    #+#             */
/*   Updated: 2025/03/27 17:59:23 by obellil-         ###   ########.fr       */
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

int	check_close(char **argv)
{
	char	*line;
	int		fd;
	int		line_len;
	int		countline;

	countline = 0;
	fd = openfd(argv);
	if (fd < 0)
		return false;
	line = get_next_line(fd);
	while (line != NULL)
	{
		line_len = 0;
		while (line[line_len] && line[line_len] != '\n')
			line_len++;
		if (line[0] != '1' || line[line_len - 1] != '1')
		{
			close(fd);
			print_error("Map non fermée");
			return false;
		}
		free(line);
		line = get_next_line(fd);
		countline++;
	}
	return (close (fd),true);
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
		return ((close(fd)), (print_error("Empty file or read error.")), false);
	first_line_length = 0;
	while (line[first_line_length] && line[first_line_length] != '\n')
		first_line_length++;
	free(line);
	while ((line = get_next_line(fd)) != NULL)
	{
		line_length = 0;
		while (line[line_length] && line[line_length] != '\n')
			line_length++;
		if (line_length != first_line_length)
		{
			free(line);
			close(fd);
			print_error("This map is not a square.");
			return (false);
		}
		free(line);
	}
	close(fd);
	return (true);
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

// int	check_square_map(char **argv)
// {
// 	int		fd;
// 	int		first_line_length;
// 	int		line_length;
// 	char	*line;

// 	fd = openfd(argv);
// 	if (fd < 0)
// 		return (false);
// 	line = get_next_line(fd);
// 	if (!line)
// 		return ((close(fd)),(print_error("Empty file or read error.")),false);
// 	first_line_length = 0;
// 	while (line[first_line_length] && line[first_line_length] != '\n')
// 	{
// 		printf("%s", line);
// 		first_line_length++;
// 	}
// 	free(line);
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 		line_length = 0;
// 		while (line[line_length] && line[line_length] != '\n')
// 		{
// 			printf("%s", line);
// 			line_length++;
// 		}
// 		if (line_length != first_line_length)
// 			return ((free(line)),close(fd),(print_error("This map is not a square.")),(false));
// 		free(line);
// 	}
// 	return ((close(fd)),true);
// }

// int	check_close(char **argv)
// {
// 	char	*line;
// 	int		count;
// 	int		fd;
// 	int		start;
// 	int		countline;

// 	countline = 0;
// 	count = 0;
// 	fd = openfd(argv);
// 	if (argv[1])
// 	{
// 		line = get_next_line(fd);
// 		while (line != NULL)
// 		{
// 			count++;
// 			countline ++;
// 			start = count -1;
// 			if (countline == '\n' && start[line] == '0' && countline == '0')
// 				return (free(line),print_error("This map is not close"),0);
// 			if (countline == '\n' && start[line] == '1' && countline == '0')
// 				return (free(line), 1);
// 		}
// 		close(fd);
// 	}
// 	return (count);
// }

// int	check_obj(char **argv)
// {
// 	int		fd;
// 	char	*line;
// 	int		count[3];
// 	int		i;

// 	count[0] = 0;
// 	count[1] = 0;
// 	count[2] = 0;
// 	fd = openfd(argv);
// 	line = get_next_line(fd);
// 	while (line != NULL)
// 	{
// 		i = -1;
// 		while (line[++i])
// 		{
// 			if (line[i] == 'C')
// 				count[0]++;
// 			else if (line[i] == 'E')
// 				count[1]++;
// 			else if (line[i] == 'P')
// 				count[2]++;
// 		}
// 		free(line);
// 	}
// 	return (close(fd),(count[0] >= 1 && count[1] == 1 && count[2] == 1));
//}
