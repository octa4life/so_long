/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obellil- <obellil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:23:45 by obellil-          #+#    #+#             */
/*   Updated: 2025/03/25 10:22:23 by obellil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	stock[BUFFER_SIZE + 1] = {};
	char		*new_line;
	int			readl;

	new_line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (ft_gnlchr(stock))
		(ft_gnlclean(stock), new_line = ft_gnljoin(new_line, stock));
	readl = 1;
	while (readl > 0 && ft_gnlchr(stock) == 0)
	{
		readl = read(fd, stock, BUFFER_SIZE);
		if (readl < 0)
			return (free(new_line), NULL);
		if (readl == 0)
		{
			if (new_line != NULL && new_line[0] != '\0')
				return (new_line);
			return (free(new_line), NULL);
		}
		stock[readl] = '\0';
		new_line = ft_gnljoin(new_line, stock);
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
