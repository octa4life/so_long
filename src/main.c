/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obellil- <obellil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:14:56 by obellil-          #+#    #+#             */
/*   Updated: 2025/05/06 09:21:58 by obellil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_format(char **map)
{
	int		y;
	int		x;
	int		count_x;

	x = 0;
	y = 0;
	count_x = 0;
	while (map[0][count_x])
		count_x++;
	while (map[y] != NULL)
	{
		while (map[y][x])
			x++;
		if (x != count_x)
		{
			print_error("Error : Your map must be a rectangle or a square\n");
			return (0);
		}
		x = 0;
		y++;
	}
	return (1);
}

int main(int argc, char **argv)
{
	t_data data;

	if (argc != 2)
	{
		print_error("Error: Need 1 .ber file\n");
		return (0);
	}
	else
	{
		data.count = 0;
		data.mlx_ptr = mlx_init();
		check_content(&data); // Correction ici : passage de la structure complète
		data.map = map_check(argv, &data);
		if (data.map != NULL)
		{
			set_img(&data);
			core_display(&data);
		}
		else
			finish(&data);
	}
	return (0); // Correction du code de retour
}
