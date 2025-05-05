/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octavie <octavie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 19:55:08 by obellil-          #+#    #+#             */
/*   Updated: 2025/05/05 09:18:40 by octavie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_same_char(char *str)
{
	int		i;
	char	buffer;

	i = 0;
	buffer = '1';
	if (str == NULL)
		return (-1);
	while (str[i])
	{
		if (str[i] != buffer && str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

void	*print_error(char *str)
{
	write(2, str, ft_strlen(str));
	return (0);
}

void	*free_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i] != NULL)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	data->map = NULL;
	return (0);
}