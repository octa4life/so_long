/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obellil- <obellil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:14:56 by obellil-          #+#    #+#             */
/*   Updated: 2025/03/25 10:23:24 by obellil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	main(int argc, char **argv)
// {
// 	(void) **argv;
// 	// Vérification du nombre d'arguments
// 	if (argc != 2)
// 	{
// 		ft_printf("Error: Invalid number of arguments. Usage: ./so_long <file.ber>\n");
// 		return (1);
// 	}
// 	return (0);
// }
int	main(int argc, char **argv)
{
	char		**map;
	t_infra		start_pos;

	if (argc != 2)
		return (print_error("Usage: ./so_long map.ber"), 1);
	if (!check_square_map(argv))
		return (1);
	if (!check_close(argv))
		return (1);
	if (!check_obj(argv))
		return (1);
	map = fill_map(argv);
	if (!map)
		return (print_error("Erreur: chargement de la map"), 1);
	start_pos.x = 0;
	start_pos.y = 0;
	if (!floodfill(map, start_pos, start_pos))
		return (print_error("Erreur: chemin invalide"), 1);
	printf("Parsing réussi, la map est valide !\n");
	return (0);
}
