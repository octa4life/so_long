/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obellil- <obellil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 19:55:08 by obellil-          #+#    #+#             */
/*   Updated: 2025/02/10 17:17:09 by obellil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
// int	floodfill(char **tab, t_pos y, t_pos x)
// {
// 	char **cpy_map;

// 	cpy_map = copy_tab(tab);
// 	if (!cpy_map)
// 		return (0);
// 	ff(cpy_map, x.x, y.y);
// 	return (1);
// 	// et si il reste C E P
// 	// map non finisable
// }
