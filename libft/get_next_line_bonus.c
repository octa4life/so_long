/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obellil- <obellil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:23:45 by obellil-          #+#    #+#             */
/*   Updated: 2024/11/20 17:34:51 by obellil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	stock[FD_LIMIT][BUFFER_SIZE + 1] = {};
	char		*new_line;
	int			readl;

	new_line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (ft_gnlchr(stock[fd]))
		(ft_gnlclean(stock[fd]), new_line = ft_gnljoin(new_line, stock[fd]));
	readl = 1;
	while (readl > 0 && ft_gnlchr(stock[fd]) == 0)
	{
		readl = read(fd, stock[fd], BUFFER_SIZE);
		if (readl < 0)
			return (free(new_line), NULL);
		if (readl == 0)
		{
			if (new_line != NULL && new_line[0] != '\0')
				return (new_line);
			return (free(new_line), NULL);
		}
		stock[fd][readl] = '\0';
		new_line = ft_gnljoin(new_line, stock[fd]);
	}
	return (new_line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*newline;

// 	fd = open("giant_line.txt", O_RDONLY);
// 	newline = get_next_line(fd);
// 	while (newline)
// 	{
// 		printf("%s", newline);
// 		free(newline);
// 		newline = get_next_line(fd);
// 	}
// 	free(newline);
// 	close(fd);
// 	return (0);
// }
