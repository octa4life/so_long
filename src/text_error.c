/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obellil- <obellil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:00:10 by obellil-          #+#    #+#             */
/*   Updated: 2025/03/18 17:15:21 by obellil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "so_long.h"

// int write_error(char **argv)
// {
// 	// Vérification de l'ouverture du fichier
// 	int fd = openfd(argv);
// 	if (fd == 0)
// 	{
// 		printf("Error: Failed to open the file '%s'. Make sure it exists and is accessible.\n", argv[1]);
// 		return (1);
// 	}
// 	// Vérification du contenu du fichier avec gnlfd
// 	if (!gnlfd(argv))
// 	{
// 		printf("Error: Failed to read the file '%s'. Ensure the file format is correct.\n", argv[1]);
// 		return (1);
// 	}
// 	// Vérification si la carte est fermée avec check_close
// 	if (!check_close(argv))
// 	{
// 		printf("Error: The map in '%s' is not properly enclosed by walls ('1').\n", argv[1]);
// 		return (1);
// 	}
// 	// Vérification des objets nécessaires sur la carte avec check_obj
// 	if (!check_obj(argv))
// 	{
// 		printf("Error: The map in '%s' is missing required objects:\n", argv[1]);
// 		printf("       - At least one collectible ('C')\n");
// 		printf("       - One exit ('E')\n");
// 		printf("       - One starting position ('P')\n");
// 		return (1);
// 	}
// 	// Si toutes les vérifications sont good, afficher un message de succès
// 	printf("File '%s' successfully validated! The map is ready to be used.\n", argv[1]);
// 	close(fd);

// 	return (0);
// }
