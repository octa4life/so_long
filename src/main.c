/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obellil- <obellil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:14:56 by obellil-          #+#    #+#             */
/*   Updated: 2025/02/11 14:05:43 by obellil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	main(int argc, char **argv)
// {
// 	if(argc == 2)
// 	{
// 		gnlfd(argv);
// 	}
// }

int	main(int argc, char **argv)
{
	t_pos Map;

	// Vérification du nombre d'arguments
	if (argc != 2)
	{
		printf("Error: Invalid number of arguments. Usage: ./so_long <file.ber>\n");
		return (1);
	}
	// Vérification de l'ouverture du fichier
	int fd = openfd(argv);
	if (fd == 0)
	{
		printf("Error: Failed to open the file '%s'. Make sure it exists and is accessible.\n", argv[1]);
		return (1);
	}
	// Vérification du contenu du fichier avec gnlfd
	if (!gnlfd(argv))
	{
		printf("Error: Failed to read the file '%s'. Ensure the file format is correct.\n", argv[1]);
		return (1);
	}
	// Vérification si la carte est fermée avec check_close
	if (!check_close(argv))
	{
		printf("Error: The map in '%s' is not properly enclosed by walls ('1').\n", argv[1]);
		return (1);
	}
	// Vérification des objets nécessaires sur la carte avec check_obj
	if (!check_obj(argv))
	{
		printf("Error: The map in '%s' is missing required objects:\n", argv[1]);
		printf("       - At least one collectible ('C')\n");
		printf("       - One exit ('E')\n");
		printf("       - One starting position ('P')\n");
		return (1);
	}
	// Si toutes les vérifications passent, afficher un message de succès
	printf("File '%s' successfully validated! The map is ready to be used.\n", argv[1]);

	// Fermeture du fichier (si nécessaire)
	close(fd);

	return (0);
}
