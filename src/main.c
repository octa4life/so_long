/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obellil- <obellil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:14:56 by obellil-          #+#    #+#             */
/*   Updated: 2025/04/01 14:52:36 by obellil-         ###   ########.fr       */
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
// int	main(int argc, char **argv)
// {
// 	char		**map;
// 	t_pos		start_pos;


// 	map = NULL;

// 	if (argc != 2)
// 		return (print_error("Usage: ./so_long map.ber"), 1);
// 	if (!check_square_map(map))
// 		return (1);
// 	if (!check_close(map))
// 		return (1);
// 	if (!check_obj(argv))
// 		return (1);
// 	map = fill_map(argv);
// 	if (!map)
// 		return (print_error("Erreur: chargement de la map"), 1);
// 	start_pos.x = 0;
// 	start_pos.y = 0;
// 	if (!floodfill(map, start_pos, start_pos))
// 		return (print_error("Erreur: chemin invalide"), 1);
// 	printf("Parsing réussi, la map est valide !\n");
// 	return (0);
// }
