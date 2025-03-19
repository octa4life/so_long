/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obellil- <obellil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 19:55:08 by obellil-          #+#    #+#             */
/*   Updated: 2025/03/19 11:41:03 by obellil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	print_error(char *mess)
{
	ft_printf("%s\n", mess);
	exit (1);
}

int	get_line_length(char *line)
{
	int	len;

	len = 0;
	while (line[len] && line[len] != '\n')
		len++;
	return (len);
}

void init_struct(t_infra *data, char **argv)
{
	data->map = fill_map(argv);
	if (!data->map)
	{
		print_error("Error : initializing map \n");
	}
}
