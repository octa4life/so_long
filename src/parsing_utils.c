/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obellil- <obellil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 19:55:08 by obellil-          #+#    #+#             */
/*   Updated: 2025/04/01 15:23:00 by obellil-         ###   ########.fr       */
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

int	print_error(char *mess)
{
	ft_printf("%s\n", mess);
	exit (1);
}

