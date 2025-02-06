/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obellil- <obellil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:42:36 by obellil-          #+#    #+#             */
/*   Updated: 2025/02/06 10:42:07 by obellil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	readfd(char **argv)
{
	int fd;

	fd = 0;
	if (argv[1])
	{
		if (ft_strnstr(argv[1],".ber", 4))
		{
			fd = open(argv[1],O_RDONLY);
			if(fd < 0)
				return (0);
			printf("%d",fd);
		}
		else
		{
			printf("error");
			print_error();
			return (0);
		}

	}
	return (0);
}
