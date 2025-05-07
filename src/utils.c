/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obellil- <obellil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 19:55:08 by obellil-          #+#    #+#             */
/*   Updated: 2025/05/07 13:58:04 by obellil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*free_map(t_data *data)
{
	int		i;

	i = 0;
	if (!data->map)
		return (0);
	while (data->map[i] != NULL)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	data->map = NULL;
	return (0);
}
// frees all allocated memory for the map and resets its pointer to NULL.

char	*ft_stradd(char *str, char buff)
{
	int		i;
	char	*ret;

	i = 0;
	ret = (char *)malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (ret == NULL)
		return (NULL);
	while (str[i])
	{
		ret[i] = str[i];
		i++;
	}
	free(str);
	ret[i] = buff;
	ret[++i] = '\0';
	return (ret);
}
// creates a new string by appending a single character
// to the end of an existing string.

int	get_next_line(int fd, char **str)
{
	char			buff;
	int				ret;

	ret = read(fd, &buff, 1);
	while (ret > 0)
	{
		*str = ft_stradd(*str, buff);
		if (buff == '\n')
			return (ret);
		else
			ret += 1;
		ret = read(fd, &buff, 1);
	}
	if (ret == 0)
	{
		free(*str);
		*str = NULL;
	}
	return (ret);
}
// reads a line from a file descriptor one character at
// a time until a newline or EOF is reached.

int	only_ones(char *str)
{
	int		i;
	char	buff;

	i = 0;
	buff = '1';
	if (str == NULL)
		return (-1);
	while (str[i])
	{
		if (str[i] != buff && str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}
// Checks if the string contains only '1' characters (excluding '\n').
// Returns 1 if true, 0 if not, -1 if input is NULL.

void	*print_error(char *str)
{
	write(2, str, ft_strlen(str));
	return (0);
}
