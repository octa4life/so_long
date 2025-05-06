/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octavie <octavie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:14:56 by obellil-          #+#    #+#             */
/*   Updated: 2025/05/06 21:49:10 by octavie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
